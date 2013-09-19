#ifndef __alogt_sll__
#define __algot_sll__
namespace algot{
  class SLLNode;
  class SLL{
  public:
    SLL();
    bool addElement(int e);
    bool deleteElement(int e);
    bool isEmpty();
    int* toArray(int &count);
    int size();
  private:
    SLLNode* head;
    int sizeOf;
  };
}
#endif
