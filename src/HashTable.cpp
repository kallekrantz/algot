#include "include/HashTable.h"
#include <algorithm>
#include <iostream>
algot::HashTable::HashTable(unsigned int newsize, unsigned int (*fun)(std::string)){
  hashFunc = fun;
  tableSize = newsize;
  usedCells = 0;
  table = new std::list<std::string>[tableSize];
}

algot::HashTable::~HashTable(){
  delete[] table;
}


unsigned int algot::HashTable::size(){
  return usedCells;
}

unsigned int algot::HashTable::containerSize(){
  return tableSize;
}

bool algot::HashTable::isEmpty(){
  return usedCells == 0;
}

bool algot::HashTable::add(std::string str){
  unsigned int hashNum = useHash(str, tableSize);
  std::list<std::string>* list = table + hashNum;
  if(list->empty()){
    list->push_front(str);
    usedCells++;
  }
  else{
    std::list<std::string>::iterator findIter = std::find(list->begin(), list->end(), str);
    if(findIter == list->end()){
      list->push_back(str);
    }
    else{
      return false;
    }
  }

  if(loadFactor() > 0.75){
    resizeTo(tableSize*2 + 1); //The plus one is to avoid the tableSize being a power of two all the time.
  }
  return true;
}

bool algot::HashTable::exists(std::string str){
  unsigned int hashNum = useHash(str, tableSize);
  std::list<std::string>* list = table + hashNum;
  std::list<std::string>::iterator findIter = std::find(list->begin(), list->end(), str);
  if(findIter == list->end()){
    return false;
  }
  return true;
}

bool algot::HashTable::remove(std::string str){
  unsigned int hashNum = useHash(str, tableSize);
  std::list<std::string>* list = table + hashNum;
  std::list<std::string>::iterator findIter = std::find(list->begin(), list->end(), str);  

  if(findIter == list->end()){
    return false;
  }
  else{
    list->erase(findIter);
    if(list->empty()){
      usedCells--;
    }
    return true;
  }
}

void algot::HashTable::resizeTo(unsigned int newSize){
  std::list<std::string>* newTable = new std::list<std::string>[newSize];
  unsigned int newUsedCells = 0;
  for(unsigned int i = 0; i < tableSize; i++){
    std::list<std::string>::iterator first = table[i].begin();
    if(first != table[i].end()){
      for(auto it = first; it != table[i].end(); it++){ //AUTO IS THE SHIT
        unsigned int newIndex = useHash(*it, newSize);
        if(newTable[newIndex].empty()){
          newUsedCells++;
        }
        newTable[newIndex].push_front(*it);
      }
    }
  }
  usedCells = newUsedCells;
  tableSize = newSize;
  delete[] table;
  table = newTable;
}

double algot::HashTable::loadFactor(){
  return (double)usedCells/(double)tableSize;
}
unsigned int algot::HashTable::useHash(std::string str, unsigned int newSize){
  return hashFunc(str) % newSize;
}



