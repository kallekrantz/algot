#ifndef __alogt_sll__
#define __algot_sll__
#include <iostream>
namespace algot{
  template <typename T>
  struct SLLNode{
    SLLNode<T>(T value = T(), SLLNode* next = NULL) : value_(value), next_(next){};
    int value_;
    SLLNode<T>* next_;
  };

  template<class E>
  class SLL{
  public:
  protected:
    SLLNode<E>* head_;
    int sizeOf_;
  public:
    SLL(){
      sizeOf_ = 0;
      head_ = new algot::SLLNode<E>();
    };

    ~SLL(){
      algot::SLLNode<E> *node = head_->next_;
      algot::SLLNode<E> *prev;
      delete head_;
      while(node){
        prev = node;
        node = node->next_;
        delete prev;
      }
    };

    const SLLNode<E> * addElement(E e){
      algot::SLLNode<E>* node = head_->next_;
      algot::SLLNode<E>* prev = head_;
      while(node){
        if(e <= node->value_){
          prev->next_ = (new algot::SLLNode<E>(e, node));
          this->sizeOf_++;
          return prev->next_;
        }
        prev = node;
        node = node->next_;
      }
      prev->next_ = (new algot::SLLNode<E>(e, NULL));
      this->sizeOf_++;
      return prev->next_;
    };
    bool deleteElement(E e){
      algot::SLLNode<E> *node = head_->next_, *prev = head_;
      while(node){
        if(e < node->value_){
          break;
        }
        else if(e == node->value_){
          prev->next_ = node->next_;
          delete node;
          sizeOf_--;
          return true;
        }
        prev = node;
        node = node->next_;
      }
      return false;
    };

    const SLLNode<E> * getHead() const{
        return head_->next_;
    };
    const SLLNode<E> * getNode(E e) const{
      SLLNode<E>* node = head_->next_;
      while(node){
        if(node->value_ == e){
          return node;
        }
        node = node->next_;
      }
      return NULL;
      
    };
    
    bool isEmpty(){
      return sizeOf_ == 0;      
    }
    
    E* toArray(int &count){
      count = size();
      int* outputArray = new E[count];
      algot::SLLNode<E>* node = head_->next_;
      for(int i = 0; i < count; i++){
        outputArray[i] = node->value_;
        node = node->next_;
      }
      return outputArray;
    }
    int size(){
      return sizeOf_;
    };
  };
}
#endif
