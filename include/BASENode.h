#ifndef __algot_base_node__
#define __algot_base_node__
namespace algot{
  class BASENode{
  public:
    BASENode(int value);
    void setValue(int value);
    int getValue() const;
  private:
    int value;
  };
}
#endif
