#ifndef __alogt_sll__
#define __algot_sll__
namespace algot{
  class SLLNode;
  class SLL{
  public:
    SLL();
    ~SLL();
    bool addElement(int e);
    bool deleteElement(int e);
    const SLLNode *const getHead() const;
    const SLLNode *const getNode(int e) const;
    bool isEmpty();
    int* toArray(int &count);
    int size();
  private:
    SLLNode* head;
    int sizeOf;
  };
}
#endif
