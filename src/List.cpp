#include "include/List.h"
#include <iostream>
algot::List::List(unsigned int size){
  size_ = size;
  realSize_ = 0;
  list_ = new int[size_];
}

algot::List::~List(){
  delete[] list_;
}

int* algot::List::setElement(unsigned int i, int e){
  if(i >= size_){
    return NULL;
  }
  list_[i] = e;
  return list_+i;
}

int algot::List::addElement(int e){
  if(realSize_ == size_){
    resizeTo(size_*2);
  }
  list_[realSize_++] = e;
  return e;
}

bool algot::List::deleteElement(int e){
  int i;
  bool found = false;
  for(i = 0; i < realSize_; i++){
    if(e == list_[i]){  
      found = true;
      break;
    }
  }
  if(!found){
    return false;
  }
  return deleteIndex(i);
}

bool algot::List::deleteIndex(unsigned int index){
  if(index >= realSize_){
    return false;
  }
  for(int j = index+1; j < realSize_; j++){
    list_[j-1] = list_[j];
  }
  realSize_--;
  return true;
}

int algot::List::findElement(int e){
  for(int i = 0; i < realSize_; i++){
    if(e == list_[i]){
      return i;
    }
  }
  return -1;
}

int* algot::List::getElement(unsigned int i){
  if(i >= realSize_){
    return NULL;
  }
  return list_ + i;
}

unsigned int algot::List::size(){
  return realSize_;
}

bool algot::List::isEmpty(){
  return realSize_ == 0;
}

unsigned int algot::List::containerSize(){
  return size_;
}


unsigned int algot::List::resizeTo(unsigned int size){
  int* temp = list_;
  list_ = new int[size];
  for(unsigned int i = 0; i < size_; i++){
    list_[i] = temp[i];
  }
  size_ = size;
  delete[] temp;
  return size;
}

