#ifndef __algot_dll__
#define __algot_dll__

namespace algot{
  class DLLNode;
  class DLL{
  public:
    DLL();
    ~DLL();
    bool addElement(int e);
    bool deleteElement(int e);
    bool isEmpty();
    const DLLNode * const getHead() const;
    const DLLNode * const getTail() const;
  private:
    algot::DLLNode* head;
    algot::DLLNode* tail;
    int sizeOf;
  };
}
#endif
