#include "gtest/gtest.h"
#include "include/DLLNode.h"
#include <iostream>

class DLLNodeTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    dllNode0 = new algot::DLLNode(1);
    dllNode2 = new algot::DLLNode(3);
    dllNode1 = new algot::DLLNode(2, dllNode0, dllNode2);
    dllNode0->setNext(dllNode1);
    dllNode2->setPrev(dllNode1);


  }
  virtual void TearDown(){
    delete dllNode0;
    delete dllNode1;
    delete dllNode2;
  }
  algot::DLLNode *dllNode0, *dllNode1, *dllNode2;
};

TEST_F(DLLNodeTest, ValueConstruct){
  EXPECT_EQ(1, dllNode0->getValue());
}

TEST_F(DLLNodeTest, NextPrev){
  EXPECT_EQ(dllNode1, dllNode0->getNext());
  EXPECT_EQ(dllNode0, dllNode1->getPrev());
  EXPECT_EQ(dllNode2, dllNode1->getNext());
  EXPECT_EQ(dllNode1, dllNode2->getPrev());
}

TEST_F(DLLNodeTest, SetValue){
  dllNode0->setValue(10);
  EXPECT_EQ(10, dllNode0->getValue());
}

