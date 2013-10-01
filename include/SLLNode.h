#ifndef __algot_sll_node__
#define __algot_sll_node__
#include <cstddef>
#include "include/BASENode.h"

namespace algot{
  class SLLNode : public BASENode{
  public:
    SLLNode(int value, SLLNode* next = NULL);
    const SLLNode* getNext() const;
    SLLNode* getNext();
    void setNext(SLLNode* node);
  private:
    SLLNode* next;
  };
}
#endif

