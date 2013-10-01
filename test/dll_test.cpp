#include "include/DLLNode.h"
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
  const algot::DLLNode* const head = dll0->getHead();
  const algot::DLLNode* const tail = dll0->getTail();
  EXPECT_EQ(tail, head->getNext());
  EXPECT_EQ(head, tail->getPrev());
}

TEST_F(DLLTest, AddElement){
  ASSERT_TRUE(dll0->addElement(2));
}

TEST_F(DLLTest, AddIdentialElement){
  ASSERT_TRUE(dll0->addElement(1));
  ASSERT_FALSE(dll0->addElement(1));
}

TEST_F(DLLTest, AddSeriesOfElements){
  int count = 100;
  for(int i = 0; i < count; i++){
    ASSERT_TRUE(dll0->addElement(i));
  }
}
