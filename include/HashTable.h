#ifndef __ALGOT_HASHTABLE__
#define __ALGOT_HASHTABLE__
#include <string>
#include "include/DLL.h"
namespace{
  unsigned int defaultHash(std::string str){
    //Apparantly this comes from Paul Larsson from Microsoft (Snickers)
    //However, the base implementation was using const char* as input
    //Something that this line fixes ;) (uglyuglyugly)
    const char* s = str.c_str();
    unsigned h = 0; //Can be HASH instead for more security against hash-based attacks
    while (*s){
        h = h * 101 + (unsigned char) *s++;
    }
    return h;
  }
}
namespace algot{
  class HashTable{
  public:
    HashTable(unsigned int size = 3, unsigned int (*fun)(std::string) = defaultHash);
    ~HashTable();
    bool add(std::string);
    unsigned int size();
    bool isEmpty();
    unsigned int containerSize();
    bool erase(std::string);
    bool exists(std::string);
  private:
    void resizeTo(unsigned int);
    double loadFactor();
    unsigned int (*hashFunc)(std::string);
    unsigned int useHash(std::string, unsigned int size);
    DLL<std::string>* table;
    unsigned int usedCells;
    unsigned int tableSize;
  };
}
#endif






