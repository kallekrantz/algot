#include "include/HashTable.h"
algot::HashTable::HashTable(unsigned int newsize, unsigned int (*fun)(std::string)){
  hashFunc = fun;
  tableSize = newsize;
  usedCells = 0;
  table = new algot::DLL<std::string>[tableSize];
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
  algot::DLL<std::string>* list = table + hashNum;
  if(list->isEmpty()){
    usedCells++;
  }
  else if(list->get(str)){
    return false;
  }
  list->add(str);
  if(loadFactor() > 0.75){
    resizeTo((tableSize-1)*2 + 1); 
    //The plus one is to avoid the tableSize being a direct power of two all the time.
  }

  return true;
}

bool algot::HashTable::exists(std::string str){
  unsigned int hashNum = useHash(str, tableSize);
  algot::DLL<std::string>* list = table + hashNum;
  if(list->get(str)){
    return true;
  }
  return false;
}

bool algot::HashTable::erase(std::string str){
  unsigned int hashNum = useHash(str, tableSize);
  algot::DLL<std::string>* list = table + hashNum;
  if(list->erase(str)){
    if(list->isEmpty()){
      usedCells--;
    }
    return true;    
  }
  return false;
  
}

void algot::HashTable::resizeTo(unsigned int newSize){
  algot::DLL<std::string>* newTable = new algot::DLL<std::string>[newSize];
  unsigned int newUsedCells = 0;
  for(unsigned int i = 0; i < tableSize; i++){
    algot::DLL<std::string>* list = table + i;
    const algot::DLLNode<std::string>* first = list->getHead()->next_;
    for(auto it = first; it != list->getTail(); it = it->next_){
      std::string newString = std::string(it->value_);
      unsigned int newIndex = useHash(newString, newSize);
      DLL<std::string>* newList = newTable + newIndex;
      if(newList->isEmpty()){
        newUsedCells++;
      }
      newList->add(newString);
    }
  }
  this->usedCells = newUsedCells;
  this->tableSize = newSize;
  delete[] table;
  table = newTable;
}

double algot::HashTable::loadFactor(){
  return (double)usedCells/(double)tableSize;
}
unsigned int algot::HashTable::useHash(std::string str, unsigned int newSize){
  return hashFunc(str) % newSize;
}



