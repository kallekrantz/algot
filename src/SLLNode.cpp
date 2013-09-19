#include "include/SLLNode.h"

algot::SLLNode::SLLNode(int value, algot::SLLNode* next){
  this->value = value;
  this->next = next;
}

void algot::SLLNode::setValue(int value){
  this->value = value;
}

int algot::SLLNode::getValue(){
  return this->value;
}

algot::SLLNode* algot::SLLNode::getNext(){
  return this->next;
}

void algot::SLLNode::setNext(algot::SLLNode* node){
  this->next = node;
}
