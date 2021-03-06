#include "gtest/gtest.h"
#include "include/HashTable.h"

class HashTableTest : public ::testing::Test{
protected:
  virtual void SetUp(){
    table = new algot::HashTable();
  }
  virtual void TearDown(){
    delete table;
  }
  algot::HashTable *table;
};

TEST_F(HashTableTest, AddNonExisting){
  ASSERT_TRUE(table->add("Hi"));
  ASSERT_TRUE(table->exists("Hi"));
}

TEST_F(HashTableTest, AddExisting){
  ASSERT_TRUE(table->add("Hi"));
  ASSERT_FALSE(table->add("Hi"));
}

TEST_F(HashTableTest, GetExisting){
  table->add("Hi");
  ASSERT_TRUE(table->exists("Hi"));
}

TEST_F(HashTableTest, GetNonExisting){
  table->exists("Hi");
}

TEST_F(HashTableTest, IsEmpty){
  ASSERT_TRUE(table->isEmpty());
}


TEST_F(HashTableTest, IsNotEmpty){
  table->add("Hi");
  ASSERT_FALSE(table->isEmpty());
}

TEST_F(HashTableTest, SizeIsZeroAndOne){
  table->add("Hi");
  ASSERT_EQ((unsigned)1, table->size());
  table->add("Hi5");
  ASSERT_EQ((unsigned)2, table->size());
}

TEST_F(HashTableTest, AddThousandsAndSize){
  std::string basestring = "Hej";
  unsigned int count = 3;
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string(basestring + std::to_string(i)); //std::to_string is the new shit in c++11
    ASSERT_TRUE(table->add(addedWord));
  }
  ASSERT_EQ((unsigned)5, table->containerSize());
}


TEST_F(HashTableTest, AddThousandAndCheck){
  unsigned int count = 1000;
  std::string basestring = "TestTest";
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string(basestring + std::to_string(i)); 
    //std::to_string is the new shit in c++11
    ASSERT_TRUE(table->add(addedWord));
    ASSERT_TRUE(table->exists(addedWord));
  }
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string(basestring + std::to_string(i)); 
    ASSERT_TRUE(table->exists(addedWord));
  }
}

TEST_F(HashTableTest, AddLotsOfThings){
  unsigned int count = 1000;
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string("wat" + std::to_string(i)); //std::to_string is the new shit in c++11
    ASSERT_TRUE(table->add(addedWord));
  }
}


TEST_F(HashTableTest, EraseExisting){
  std::string str = "Hej";
  table->add(str);
  ASSERT_TRUE(table->erase(str));
  ASSERT_FALSE(table->exists(str));
}

TEST_F(HashTableTest, EraseNonExisting){
  std::string str = "Hej";
  ASSERT_FALSE(table->erase(str));
}

TEST_F(HashTableTest, SubtractSize){
  std::string str = "Hej";
  table->add(str);
  ASSERT_TRUE(table->erase(str));
  ASSERT_EQ((unsigned)0, table->size());
  ASSERT_TRUE(table->isEmpty());
}

TEST_F(HashTableTest, SubtractLotsSize){
  unsigned int count = 10000;
  std::string basestring = "Hej";
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string(basestring + std::to_string(i)); 
    //std::to_string is the new shit in c++11
    ASSERT_TRUE(table->add(addedWord));
    ASSERT_TRUE(table->exists(addedWord));
  }
  for(unsigned int i = 0; i < count; i++){
    std::string addedWord = std::string(basestring + std::to_string(i)); 
    //std::to_string is the new shit in c++11
    ASSERT_TRUE(table->erase(addedWord));
  }
  ASSERT_EQ((unsigned)0, table->size());
  ASSERT_TRUE(table->isEmpty());
}
