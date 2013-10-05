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

const algot::DLLNode * algot::DLL::getHead() const{
  return this->head;
}

const algot::DLLNode * algot::DLL::getTail() const{
  return this->tail;
}

const algot::DLLNode * algot::DLL::addElement(int e){
  algot::DLLNode* node = head->getNext();
  while(node != tail){
    if( e <= node->getValue()){
      node = new DLLNode(e, node->getPrev(), node->getNext());
      node->getPrev()->setNext(node);
      node->getNext()->setPrev(node);
      this->sizeOf++;
      return node;
    }
    node = node->getNext();
  }
  node = new DLLNode(e, node->getPrev(), tail);
  node->getPrev()->setNext(node);
  node->getNext()->setPrev(node);
  this->sizeOf++;
  return node;
}

//Deletes a node which is equal to element e. 
//This does not delete all elements that are equal.
bool algot::DLL::deleteElement(int e){
  algot::DLLNode* node = head->getNext();
  while(node != tail){
    if(e < node->getValue()){
      break;
    }
    if(e == node->getValue()){
      node->getPrev()->setNext(node->getNext());
      node->getNext()->setPrev(node->getPrev());

      delete node;
      sizeOf--;

      return true;
    }
    node = node->getNext();
  }
  return false;
}

int* algot::DLL::toArray() const{
  int* out = new int[size()];
  algot::DLLNode* node = head->getNext();
  for(int i = 0; i < size(); i++){
    out[i] = node->getValue();
    node = node->getNext();
  }
  return out;
}

bool algot::DLL::isEmpty() const{
  return this->sizeOf == 0;
}

int algot::DLL::size() const{
  return this->sizeOf;
}
