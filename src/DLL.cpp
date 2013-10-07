#include "include/DLL.h"

algot::DLL::DLL(){
  sizeOf_ = 0;
  head_ = new algot::DLL::Node(0);
  tail_ = new Node(0);
  head_->next_ = tail_;
  tail_->prev_ = head_;
}

algot::DLL::~DLL(){
  algot::DLL::Node* node = head_->next_;
  algot::DLL::Node* old = NULL; 
  delete head_;
  while(node != tail_){
    old = node;
    node = node->next_;
    delete old;
  }
  delete tail_;
}

const algot::DLL::Node * algot::DLL::getHead() const{
  return head_;
}

const algot::DLL::Node * algot::DLL::getTail() const{
  return tail_;
}

const algot::DLL::Node * algot::DLL::addElement(int e){
  algot::DLL::Node* node = head_->next_;
  while(node != tail_){
    if( e <= node->value_){
      node = new algot::DLL::Node(e, node->prev_, node->next_);
      node->prev_->next_ = node;
      node->next_->prev_ = node;
      sizeOf_++;
      return node;
    }
    node = node->next_;
  }
  node = new algot::DLL::Node(e, node->prev_, tail_);
  node->prev_->next_ = node;
  node->next_->prev_ = node;
  sizeOf_++;
  return node;
}

//Deletes a node which is equal to element e. 
//This does not delete all elements that are equal.
bool algot::DLL::deleteElement(int e){
  algot::DLL::Node* node = head_->next_;
  while(node != tail_){
    if(e < node->value_){
      break;
    }
    if(e == node->value_){
      node->prev_->next_ = node->next_;
      node->next_->prev_ = node->prev_;

      delete node;
      sizeOf_--;

      return true;
    }
    node = node->next_;
  }
  return false;
}

int* algot::DLL::toArray() const{
  int* out = new int[size()];
  algot::DLL::Node* node = head_->next_;
  for(int i = 0; i < size(); i++){
    out[i] = node->value_;
    node = node->next_;
  }
  return out;
}

bool algot::DLL::isEmpty() const{
  return sizeOf_ == 0;
}

int algot::DLL::size() const{
  return sizeOf_;
}
