#ifndef __alogt_sll__
#define __algot_sll__
#include <iostream>
namespace algot{
  class SLL{
  public:
    struct Node{
      Node(int value, Node* next = NULL) : value_(value), next_(next){};
      int value_;
      Node* next_;
    };
  protected:
    Node* head_;
    int sizeOf_;
  public:
    SLL();
    ~SLL();
    const Node * addElement(int e);
    bool deleteElement(int e);
    const Node * getHead() const;
    const Node * getNode(int e) const;
    bool isEmpty();
    int* toArray(int &count);
    int size();

  };
}
#endif
