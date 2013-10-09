#ifndef __algot_dll__
#define __algot_dll__
#include <iostream>
namespace algot{
  template <typename T>
  struct DLLNode{
  DLLNode<T>(T value, DLLNode<T> *prev = NULL, DLLNode<T> *next = NULL) : value_(value), prev_(prev), next_(next){};
    T value_;
    DLLNode<T>* prev_;      
    DLLNode<T>* next_;
  };
  
  template<class E>
  class DLL{
  protected:
    DLLNode<E>* head_;
    DLLNode<E>* tail_;
    int sizeOf_;
  public:
    DLL(){
      sizeOf_ = 0;
      head_ = new algot::DLLNode<E>(0);
      tail_ = new DLLNode<E>(0);
      head_->next_ = tail_;
      tail_->prev_ = head_;
    };
    ~DLL(){
      algot::DLLNode<E>* node = head_->next_;
      algot::DLLNode<E>* old = NULL; 
      delete head_;
      while(node != tail_){
        old = node;
        node = node->next_;
        delete old;
      }
      delete tail_;
    };
    const DLLNode<E> *  addElement(int e){
      algot::DLLNode<E>* node = head_->next_;
      while(node != tail_){
        if( e <= node->value_){
          node = new algot::DLLNode<E>(e, node->prev_, node->next_);
          node->prev_->next_ = node;
          node->next_->prev_ = node;
          sizeOf_++;
          return node;
        }
        node = node->next_;
      }
      node = new algot::DLLNode<E>(e, node->prev_, tail_);
      node->prev_->next_ = node;
      node->next_->prev_ = node;
      sizeOf_++;
      return node;
      
    }
    bool deleteElement(int e){
      algot::DLLNode<E>* node = head_->next_;
      while(node != tail_){
        if(e < node->value_){
          break;
        }
        if(e == node->value_){
          node->prev_->next_ = node->next_;
          node->next_->prev_ = node->prev_;
          
          delete node;
          sizeOf_--;
          
          return true;
        }
        node = node->next_;
      }
      return false;
    };
    bool isEmpty() const{
      return sizeOf_ == 0;
    };
    int size() const{
      return sizeOf_;
    };
    const DLLNode<E>* getHead() const{
        return head_;
    };
    const DLLNode<E>*  getTail() const{
      return tail_;
    };
    int* toArray() const{
      int* out = new int[size()];
      algot::DLLNode<E>* node = head_->next_;
      for(int i = 0; i < size(); i++){
        out[i] = node->value_;
        node = node->next_;
      }
      return out;
      
    };
  };
}
#endif
