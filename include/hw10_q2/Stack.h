#ifndef STACK_H
#define STACK_H

#include "List.h"

namespace ece309 {

  class Stack {
  private:
    List list;

  public:
    Stack() {}
    void push(Item);
    void pop();
    Item &peek();
    bool empty();
  };
  
}

#endif // STACK_H
