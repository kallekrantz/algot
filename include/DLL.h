#ifndef __algot_dll__
#define __algot_dll__

namespace algot{
  class DLLNode;
  class DLL{
  public:
    DLL();
    ~DLL();
    const DLLNode *  addElement(int e);
    bool deleteElement(int e);
    bool isEmpty() const;
    int size() const;
    const DLLNode * getHead() const;
    const DLLNode *  getTail() const;
    int* toArray() const;
  private:
    algot::DLLNode* head;
    algot::DLLNode* tail;
    int sizeOf;
  };
}
#endif
