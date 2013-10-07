#ifndef __algot_dll__
#define __algot_dll__
#include <iostream>
namespace algot{
  class DLL{
    public:
    struct Node{
      Node(int value, Node *prev = NULL, Node *next = NULL) : value_(value), prev_(prev), next_(next){};
      int value_;
      Node* prev_;      
      Node* next_;

    };
  protected:
    Node* head_;
    Node* tail_;
    int sizeOf_;
  public:
    DLL();
    ~DLL();
    const DLL::Node *  addElement(int e);
    bool deleteElement(int e);
    bool isEmpty() const;
    int size() const;
    const DLL::Node * getHead() const;
    const DLL::Node *  getTail() const;
    int* toArray() const;
  };
}
#endif
