#include "include/SLLNode.h"

algot::SLLNode::SLLNode(int nvalue, algot::SLLNode* next):algot::BASENode(nvalue){
  this->next = next;
}

algot::SLLNode* algot::SLLNode::getNext(){
  return this->next;
}
const algot::SLLNode* algot::SLLNode::getNext() const{
  return this->next;
}

void algot::SLLNode::setNext(algot::SLLNode* node){
  this->next = node;
}
