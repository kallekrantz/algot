#include "include/SLL.h"
#include "include/SLLNode.h"
#include <iostream>
algot::SLL::SLL(){
  sizeOf = 0;
  head = new SLLNode(0);
}

algot::SLL::~SLL(){
  algot::SLLNode *node = head->getNext();
  algot::SLLNode *prev;
  delete head;
  while(node){
    prev = node;
    node = node->getNext();
    delete prev;
  }
}

bool algot::SLL::isEmpty(){
  return !(bool)head->getNext();
}

bool algot::SLL::addElement(int e){
  algot::SLLNode* node = head;
  algot::SLLNode* next = NULL;
  while(next = node->getNext()){
    if(e < next->getValue()){
      node->setNext(new algot::SLLNode(e, next));
      this->sizeOf++;
      return true;
    }
    else if(e == next->getValue()){
      return false;
    }
    else{
      node = next;
    }
  }
  node->setNext(new algot::SLLNode(e, next));
  this->sizeOf++;
  return true;
}

bool algot::SLL::deleteElement(int e){
  algot::SLLNode *node = head, *next = NULL, *prev = NULL;
  while((prev = node) && (node = node->getNext())){
    
    if(e < node->getValue()){
      break;
    }
    else if(e == node->getValue()){
      prev->setNext(node->getNext());
      delete node;
      sizeOf--;
      return true;
    }
    else{
      prev = node;
    }
  }
  return false;
}

int* algot::SLL::toArray(int &count){
  count = this->size();
  int* outputArray = new int[count];
  algot::SLLNode* node = this->head->getNext();
  for(int i = 0; i < count; i++){
    outputArray[i] = node->getValue();
    node = node->getNext();
  }
  return outputArray;
}

int algot::SLL::size(){
  return sizeOf;
}

const algot::SLLNode *const algot::SLL::getHead() const{
  return head->getNext();
}

const algot::SLLNode *const algot::SLL::getNode(int e) const{
  SLLNode* node = this->head->getNext();
  while(node){
    if(node->getValue() == e){
      return node;
    }
    node = node->getNext();
  }
  return NULL;
}
