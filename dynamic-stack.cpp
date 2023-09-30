#include "dynamic-stack.h"
#include <iostream>

const DynamicStack::StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack() {
    init_capacity_ = 16;
    size_ = 0;
    capacity_ = init_capacity_;
    items_ = new StackItem[capacity_];


}

DynamicStack::DynamicStack(unsigned int capacity){
    capacity_ = capacity;
    size_ = 0;
    init_capacity_ = capacity_;
    items_ = new StackItem(capacity_);
}

DynamicStack::~DynamicStack() {
    delete [] items_;
    items_ = nullptr;

}

unsigned int DynamicStack::size() const {
    return size_;
}

bool DynamicStack::empty() const {
    return ( size_ == 0 );
}

DynamicStack::StackItem DynamicStack::peek() const {
    if( empty() ){
        return EMPTY_STACK;
    }
    return (items_[size_-1]);
}

void DynamicStack::push(StackItem value) {
    if (size_ == capacity_){
        capacity_ *= 2;
        StackItem *arrTemp;
        arrTemp = new StackItem[ capacity_];
        for ( unsigned int i = 0; i < size_; i++){
            arrTemp[i] = items_[i];
        }

        int *previous = items_;
        items_ = arrTemp;
        arrTemp = nullptr;
        delete [] previous;
        previous = nullptr;
    }

    items_[size_] = value;
    size_++;
}

DynamicStack::StackItem DynamicStack::pop() {
    if ( empty() ){
        return EMPTY_STACK;
    }

    StackItem tempVal = items_[size_-1];
    items_[size_-1] = EMPTY_STACK;
    size_--;

    if ( (size_ < (capacity_/4)) && (capacity_/2 >= init_capacity_) ){
        capacity_ /= 2;
        StackItem *arrTemp;
        arrTemp = new StackItem[ capacity_];
        for ( unsigned int i =0; i < size_; i++){
            arrTemp[i] = items_[i];
        }

        int *previous = items_;
        items_ = arrTemp;
        arrTemp = nullptr;
        delete [] previous;
        previous = nullptr;
    }

    return tempVal;
}

void DynamicStack::print() const {
    for ( unsigned int i = size_-1; i >= 0; i--){
        std::cout<<items_[i] << ", ";
    }
    std::cout << std::endl;
}
