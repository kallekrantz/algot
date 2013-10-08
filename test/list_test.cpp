#include "gtest/gtest.h"
#include "include/List.h"

class ListTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    list0 = new algot::List();
    list1 = new algot::List(20);
  }
  virtual void TearDown(){
    delete list0;
    delete list1;
  }
  algot::List *list0;
  algot::List *list1;
};

TEST_F(ListTest, IsEmpty){
  ASSERT_TRUE(list0->isEmpty());
}

TEST_F(ListTest, IsNotEmpty){
  list0->addElement(1);
  ASSERT_FALSE(list0->isEmpty());
}

TEST_F(ListTest, ContainerSize){
  ASSERT_EQ((unsigned)10, list0->containerSize());
  ASSERT_EQ((unsigned)20, list1->containerSize());
}

TEST_F(ListTest, ExpandContainerSize){
  for(int i = 0; i < 15; i++){
    list0->addElement(i);
  }
  ASSERT_EQ((unsigned)20, list0->containerSize());
}

TEST_F(ListTest, GetExistingElement){
  list0->addElement(1);
  ASSERT_EQ(1, *list0->getElement(0));
}

TEST_F(ListTest, GetNonExistingElement){
  ASSERT_EQ(NULL, list0->getElement(0));
}

TEST_F(ListTest, SetOutOfBounds){
  ASSERT_EQ(NULL, list0->setElement(50,1));
}
TEST_F(ListTest, SetElement){
  ASSERT_EQ(1, *list0->setElement(5,1));
}

TEST_F(ListTest, DeleteExistingElement){
  list0->addElement(5);
  ASSERT_TRUE(list0->deleteElement(5));
}

TEST_F(ListTest, DeleteNonExistingElement){
  ASSERT_FALSE(list0->deleteElement(5));
}

TEST_F(ListTest, DeleteExistingIndex){
  list0->addElement(5);
  ASSERT_TRUE(list0->deleteIndex(0));
}

TEST_F(ListTest, DeleteNonExistingIndex){
  ASSERT_FALSE(list0->deleteIndex(0));
}

TEST_F(ListTest, FindExistingElement){
  list0->addElement(5);
  ASSERT_EQ(0, list0->findElement(5));
}

TEST_F(ListTest, FindNonExistingElement){
  ASSERT_EQ(-1, list0->findElement(5));
}

TEST_F(ListTest, AddSize){
  list0->addElement(5);
  ASSERT_EQ((unsigned)1, list0->size());
}

TEST_F(ListTest, SubtractSize){
  int count = 100;
  for(int i = 0; i < count; i++){
    list0->addElement(i);
  }
  ASSERT_EQ((unsigned)count, list0->size());
  list0->deleteElement(5);
  ASSERT_EQ((unsigned)count-1, list0->size());
}
