#include "include/DLL.h"
#include "gtest/gtest.h"

class DLLTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    dll0 = new algot::DLL();
    dll1 = new algot::DLL();
    dll2 = new algot::DLL();
  }
  virtual void TearDown(){
    delete dll0;
    delete dll1;
    delete dll2;
  }
  algot::DLL *dll0;
  algot::DLL *dll1;
  algot::DLL *dll2;
};

TEST_F(DLLTest, HeadTailLink){
  const algot::DLL::Node* const head = dll0->getHead();
  const algot::DLL::Node* const tail = dll0->getTail();
  EXPECT_EQ(tail, head->next_);
  EXPECT_EQ(head, tail->prev_);
}

TEST_F(DLLTest, AddElement){
  ASSERT_TRUE(dll0->addElement(2));
}

TEST_F(DLLTest, AddIdentialElement){
  ASSERT_EQ(dll0->addElement(1)->value_, 1);
  ASSERT_EQ(dll0->addElement(1)->value_, 1);
}

TEST_F(DLLTest, AddSeriesOfElements){
  int count = 100;
  for(int i = 0; i < count; i++){
    ASSERT_EQ(dll0->addElement(i)->value_, i);
  }
}

TEST_F(DLLTest, DeleteExistingElement){
  dll0->addElement(5);
  ASSERT_TRUE(dll0->deleteElement(5));
}

TEST_F(DLLTest, DeleteNotExistingElement){
  ASSERT_FALSE(dll0->deleteElement(5));
}

TEST_F(DLLTest, AddSize){
  int count = 100;
  for (int i = count; i > 0; i--){
    dll0->addElement(i);
  }
  ASSERT_EQ(count, dll0->size());
}

TEST_F(DLLTest, SubtractSize){
  int count = 100;
  for(int i = 1; i < count; i++){
    ASSERT_EQ(dll0->addElement(i)->value_, i);
  }
  for(int i = 1; i < count; i++){
    ASSERT_TRUE(dll0->deleteElement(i));
  }
  ASSERT_EQ(0, dll0->size());
}

TEST_F(DLLTest, ToArray){
  int count = 100;
  for(int i = 0; i < count; i++){
    dll0->addElement(i);
  }
  int *array = dll0->toArray();
  for(int i = 0; i < count; i++){
    ASSERT_EQ(array[i], i);
  }
}

TEST_F(DLLTest, IsEmpty){
  ASSERT_TRUE(dll0->isEmpty());
}

TEST_F(DLLTest, IsNotEmpty){
  dll0->addElement(1);
  ASSERT_FALSE(dll0->isEmpty());
}

TEST_F(DLLTest, AddReverseOrder){
  int count = 100;
  for(int i = count; i > 0; i--){
    ASSERT_EQ(dll0->addElement(i)->value_,i);
  }
  const algot::DLL::Node* node = dll0->getHead();
  for(int i = count; i < count; i++){
    ASSERT_EQ(node->value_, i);
    node = node->next_;
  }
}
