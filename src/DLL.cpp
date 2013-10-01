#include "include/DLL.h"
#include "include/DLLNode.h"
#include <iostream>

algot::DLL::DLL(){
  this->sizeOf = 0;
  this->head = new DLLNode(0);
  this->tail = new DLLNode(0);
  head->setNext(tail);
  tail->setPrev(head);
}

algot::DLL::~DLL(){
  algot::DLLNode* node = head->getNext();
  algot::DLLNode* old = NULL; 
  delete head;
  while(node != tail){
    old = node;
    node = node->getNext();
    delete old;
  }
  delete tail;
}

const algot::DLLNode* const algot::DLL::getHead() const{
  return this->head;
}

const algot::DLLNode* const algot::DLL::getTail() const{
  return this->tail;
}

bool algot::DLL::addElement(int e){
  algot::DLLNode* node = head->getNext();
  while(node != tail){
    if( e < node->getValue()){
      node = new DLLNode(e, node->getPrev(), node->getNext());
      node->getPrev()->setNext(node);
      node->getNext()->setPrev(node);
      this->sizeOf++;
      return true;
    }
    else if(e == node->getValue()){
      return false;
    }
    node = node->getNext();
  }
  node = new DLLNode(e, node->getPrev(), tail);
  node->getPrev()->setNext(node);
  node->getNext()->setPrev(node);
  this->sizeOf++;
  return true;
}
