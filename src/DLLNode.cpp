#include "include/DLLNode.h"

algot::DLLNode::DLLNode(int value, DLLNode* prev, DLLNode* next) : BASENode(value){
  this->next = next;
  this->prev = prev;
}

algot::DLLNode* algot::DLLNode::getNext(){
  return this->next;
}

const algot::DLLNode* const algot::DLLNode::getNext() const{
  return this->next;
}

algot::DLLNode* algot::DLLNode::getPrev(){
  return this->prev;
}

const algot::DLLNode* const algot::DLLNode::getPrev() const{
  return this->prev;
}

void algot::DLLNode::setNext(DLLNode* node){
  this->next = node;
}

void algot::DLLNode::setPrev(DLLNode* node){
  this->prev = node;
}
