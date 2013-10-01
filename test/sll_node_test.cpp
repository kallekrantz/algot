#include "include/SLLNode.h"
#include "gtest/gtest.h"

class SLLNodeTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    sl0 = new algot::SLLNode(1);
    sl1 = new algot::SLLNode(2, sl0);
    sl2 = new algot::SLLNode(3, sl1);
  }
  virtual void TearDown(){
    delete sl0;
    delete sl1;
    delete sl2;
  }
  algot::SLLNode *sl0;
  algot::SLLNode *sl1;
  algot::SLLNode *sl2;
};

TEST_F(SLLNodeTest, SetNext){
  sl0->setNext(sl1);
  EXPECT_EQ(sl0->getNext(), sl1);
}
TEST_F(SLLNodeTest, SetValue){
  sl0->setValue(5);
  EXPECT_EQ(sl0->getValue(), 5);
}
TEST_F(SLLNodeTest, ValueConstruct){
  EXPECT_EQ(sl0->getValue(), 1);
  EXPECT_EQ(sl1->getValue(), 2);
  EXPECT_EQ(sl2->getValue(), 3);
}
TEST_F(SLLNodeTest, NextConstruct){
  EXPECT_EQ(sl1, sl2->getNext());
  EXPECT_EQ(sl0, sl1->getNext());
  EXPECT_EQ(NULL, sl0->getNext());
}
