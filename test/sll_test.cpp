#include "include/SLL.h"
#include "gtest/gtest.h"

class SLLTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    sl0 = new algot::SLL<int>();
    sl1 = new algot::SLL<int>();
    sl2 = new algot::SLL<int>();
  }
  virtual void TearDown(){
    delete sl0;
    delete sl1;
    delete sl2;
  }
  algot::SLL<int> *sl0;
  algot::SLL<int> *sl1;
  algot::SLL<int> *sl2;
};

TEST_F(SLLTest, IsEmpty){
  EXPECT_TRUE(sl0->isEmpty());
  EXPECT_TRUE(sl1->isEmpty());
  EXPECT_TRUE(sl2->isEmpty());
}

TEST_F(SLLTest, AddElementIdentical){
  EXPECT_EQ(sl0->addElement(1)->value_, 1);
  EXPECT_EQ(sl0->addElement(1)->value_, 1);
}

TEST_F(SLLTest, AddElementSeries){
  for(int i = 0; i < 100; i++){
    ASSERT_TRUE(sl2->addElement(i));
  }
}

TEST_F(SLLTest, DeleteElementIdentical){
  sl0->addElement(1);
  EXPECT_TRUE(sl0->deleteElement(1));
  EXPECT_FALSE(sl0->deleteElement(1));
}

TEST_F(SLLTest, DeleteElementSeries){
  for(int i = 0; i < 100; i++){
    sl1->addElement(i);
  }
  for(int i = 0; i < 100; i++){
    ASSERT_TRUE(sl1->deleteElement(i));
  }
}

TEST_F(SLLTest, AddSize){
  for(int i = 0; i < 100; i++){
    ASSERT_TRUE(sl2->addElement(i));
    ASSERT_EQ(i+1, sl2->size());
  }
}

TEST_F(SLLTest, SubtractSize){
  int count = 100;
  for(int i = 0; i <= count; i++){
    sl2->addElement(i);
  }
  for(int i = 0; i <= count; i++){
    sl2->deleteElement(i);
    ASSERT_EQ(count-i, sl2->size());
  }
}

TEST_F(SLLTest, ToArray){
  int count = 100;
  int* array = new int[count];
  for(int i = 0; i < count; i++){
    array[i] = i;
    sl0->addElement(i);
  }
  int countCompare;
  int* compareArray = sl0->toArray(countCompare);
  ASSERT_EQ(count, countCompare);
  for(int i = 0; i < count; i++){
    ASSERT_EQ(array[i], compareArray[i]);
  }
  delete[] array;
}

TEST_F(SLLTest, IterateList){
  int count = 100;
  for(int i = 0; i < count; i++){
    sl0->addElement(i);
  }
  algot::SLLNode<int> const* head = sl0->getHead();
  for(int i = 0; i < count; i++){
    ASSERT_EQ(i, head->value_);
    head = head->next_;
  }
}

TEST_F(SLLTest, FindInList){
  sl0->addElement(1);
  sl0->addElement(-1);
  sl0->addElement(5);
  EXPECT_EQ(-1, sl0->getNode(-1)->value_);
  EXPECT_EQ(5, sl0->getNode(5)->value_);
  EXPECT_FALSE(sl0->getNode(2));
}
