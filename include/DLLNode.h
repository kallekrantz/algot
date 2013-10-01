#ifndef __algot_dll_node__
#define __algot_dll_node__
#include <cstddef>
#include "include/BASENode.h"

namespace algot{
  class DLLNode : public BASENode{
  public:
    DLLNode(int value, DLLNode* prev=NULL, DLLNode* next=NULL);
    DLLNode* getNext();
    const DLLNode* const getNext() const;
    DLLNode* getPrev();
    const DLLNode* const getPrev() const;
    void setNext(DLLNode* node);
    void setPrev(DLLNode* node);
  private:
    DLLNode* prev;
    DLLNode* next;
  };
}
#endif
