#include "include/SLL.h"
#include <iostream>

algot::SLL::SLL(){
  sizeOf_ = 0;
  head_ = new algot::SLL::Node(0);
}

algot::SLL::~SLL(){
  algot::SLL::Node *node = head_->next_;
  algot::SLL::Node *prev;
  delete head_;
  while(node){
    prev = node;
    node = node->next_;
    delete prev;
  }
}

bool algot::SLL::isEmpty(){
  return sizeOf_ == 0;
}

const algot::SLL::Node * algot::SLL::addElement(int e){
  algot::SLL::Node* node = head_->next_;
  algot::SLL::Node* prev = head_;
  while(node){
    if(e <= node->value_){
      prev->next_ = (new algot::SLL::Node(e, node));
      this->sizeOf_++;
      return prev->next_;
    }
    prev = node;
    node = node->next_;
  }
  prev->next_ = (new algot::SLL::Node(e, NULL));
  this->sizeOf_++;
  return prev->next_;
}

bool algot::SLL::deleteElement(int e){
  algot::SLL::Node *node = head_->next_, *prev = head_;
  while(node){
    if(e < node->value_){
      break;
    }
    else if(e == node->value_){
      prev->next_ = node->next_;
      delete node;
      sizeOf_--;
      return true;
    }
    prev = node;
    node = node->next_;
  }
  return false;
}

int* algot::SLL::toArray(int &count){
  count = size();
  int* outputArray = new int[count];
  algot::SLL::Node* node = head_->next_;
  for(int i = 0; i < count; i++){
    outputArray[i] = node->value_;
    node = node->next_;
  }
  return outputArray;
}

int algot::SLL::size(){
  return sizeOf_;
}

const algot::SLL::Node * algot::SLL::getHead() const{
  return head_->next_;
}

const algot::SLL::Node * algot::SLL::getNode(int e) const{
  SLL::Node* node = head_->next_;
  while(node){
    if(node->value_ == e){
      return node;
    }
    node = node->next_;
  }
  return NULL;
}
