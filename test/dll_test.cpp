#include "include/DLL.h"
#include "gtest/gtest.h"

class DLLTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    dll0 = new algot::DLL<int>();
    dll1 = new algot::DLL<int>();
    dll2 = new algot::DLL<int>();
  }
  virtual void TearDown(){
    delete dll0;
    delete dll1;
    delete dll2;
  }
  algot::DLL<int> *dll0;
  algot::DLL<int> *dll1;
  algot::DLL<int> *dll2;
};

TEST_F(DLLTest, HeadTailLink){
  const algot::DLLNode<int>* const head = dll0->getHead();
  const algot::DLLNode<int>* const tail = dll0->getTail();
  EXPECT_EQ(tail, head->next_);
  EXPECT_EQ(head, tail->prev_);
}

TEST_F(DLLTest, AddElement){
  ASSERT_TRUE(dll0->add(2));
}

TEST_F(DLLTest, AddIdentialElement){
  ASSERT_EQ(dll0->add(1)->value_, 1);
  ASSERT_EQ(dll0->add(1)->value_, 1);
}

TEST_F(DLLTest, AddSeriesOfElements){
  int count = 100;
  for(int i = 0; i < count; i++){
    ASSERT_EQ(dll0->add(i)->value_, i);
  }
}

TEST_F(DLLTest, DeleteExistingElement){
  dll0->add(5);
  ASSERT_TRUE(dll0->erase(5));
}

TEST_F(DLLTest, DeleteNotExistingElement){
  ASSERT_FALSE(dll0->erase(5));
}

TEST_F(DLLTest, AddSize){
  int count = 100;
  for (int i = count; i > 0; i--){
    dll0->add(i);
  }
  ASSERT_EQ(count, dll0->size());
}

TEST_F(DLLTest, SubtractSize){
  int count = 100;
  for(int i = 1; i < count; i++){
    ASSERT_EQ(dll0->add(i)->value_, i);
  }
  for(int i = 1; i < count; i++){
    ASSERT_TRUE(dll0->erase(i));
  }
  ASSERT_EQ(0, dll0->size());
  ASSERT_TRUE(dll0->isEmpty());
}

TEST_F(DLLTest, ToArray){
  int count = 100;
  for(int i = 0; i < count; i++){
    dll0->add(i);
  }
  int *array = dll0->toArray();
  for(int i = 0; i < count; i++){
    ASSERT_EQ(array[i], i);
  }
}

TEST_F(DLLTest, GetExisting){
  const algot::DLLNode<int>* node = dll0->add(2);
  ASSERT_EQ(node, dll0->get(2));
}

TEST_F(DLLTest, GetNonExisting){
    ASSERT_EQ(NULL, dll0->get(2));
}

TEST_F(DLLTest, GetSeries){
  int count = 100;
  for(int i = 0; i < count; i++){
    ASSERT_TRUE(dll0->add(i));
  }
  for(int i = 0; i< count; i++){
    ASSERT_EQ(i, dll0->get(i)->value_);
  }
}

TEST_F(DLLTest, IsEmpty){
  ASSERT_TRUE(dll0->isEmpty());
}

TEST_F(DLLTest, IsNotEmpty){
  dll0->add(1);
  ASSERT_FALSE(dll0->isEmpty());
}

TEST_F(DLLTest, AddReverseOrder){
  int count = 100;
  for(int i = count; i > 0; i--){
    ASSERT_EQ(dll0->add(i)->value_,i);
  }
  const algot::DLLNode<int>* node = dll0->getHead();
  for(int i = count; i < count; i++){
    ASSERT_EQ(node->value_, i);
    node = node->next_;
  }
}

