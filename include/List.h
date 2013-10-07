#ifndef __algot_list__
#define __algot_list__
namespace algot{
  class List{
  public: 
    List(unsigned int size = 10);
    ~List();
    int addElement(int e);
    int* setElement(unsigned int i, int e);
    bool deleteElement(int e);
    bool deleteIndex(unsigned int i);
    int findElement(int e);
    int* getElement(unsigned int i);
    unsigned int size();
    bool isEmpty();
    unsigned int containerSize();
  private:
    unsigned int resizeTo(unsigned int size);
    int* list_;
    unsigned int size_;
    unsigned int realSize_;
  };
}
#endif
