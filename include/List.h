#ifndef __algot_list__
#define __algot_list__
namespace algot{
  class List{
  public: 
    int addElement(int e);
    bool removeElement(int e);
    int findElement(int e);
    int getELement(int i);
  private:
    int expandTo(int size);
    int* list_;
    int size_;
  };
}
#endif
