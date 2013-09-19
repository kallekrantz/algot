#ifndef __algot_sll_node__
#define __alogt_sll_node__
#include <cstddef>
namespace algot{
  class SLLNode{
  public:
    SLLNode(int value, SLLNode* next = NULL);
    void setValue(int value);
    int getValue();
    SLLNode* getNext();
    void setNext(SLLNode* node);
  private:
    int value;
    SLLNode* next;
  };
}
#endif

