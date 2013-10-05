#ifndef __alogt_sll__
#define __algot_sll__
namespace algot{
  class SLLNode;
  class SLL{
  public:
    SLL();
    ~SLL();
    const SLLNode * addElement(int e);
    bool deleteElement(int e);
    const SLLNode * getHead() const;
    const SLLNode * getNode(int e) const;
    bool isEmpty();
    int* toArray(int &count);
    int size();
  private:
    SLLNode* head;
    int sizeOf;
  };
}
#endif
