#include "include/BASENode.h"

algot::BASENode::BASENode(int invalue):value(invalue){
  
}

void algot::BASENode::setValue(int value){
  this->value = value;
}

int algot::BASENode::getValue() const{
  return value;
}
