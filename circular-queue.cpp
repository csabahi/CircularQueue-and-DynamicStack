#include <iostream>
#include "circular-queue.h"

const CircularQueue::QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue() {
    capacity_ = 16;
    size_ = 0;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;

}

CircularQueue::CircularQueue(unsigned int capacity) {
    capacity_ = capacity;
    size_ = 0;
    items_ = new QueueItem[capacity_];
    head_ = 0;
    tail_ = 0;

}

CircularQueue::~CircularQueue() {
    delete [] items_;
    items_ = nullptr;
}

unsigned int CircularQueue::size() const {
    return size_;
}

bool CircularQueue::empty() const {
    return (size_ == 0);
}

bool CircularQueue::full() const {
    return (size_ == capacity_);
}

CircularQueue::QueueItem CircularQueue::peek() const {
    if (size_==0){
        return EMPTY_QUEUE;
    }
    return items_[head_];
}

bool CircularQueue::enqueue(QueueItem value) {
    if (full()){
        return false;
    }

    items_[tail_] = value;
    tail_ = (tail_+1) % capacity_;
    size_ ++;
    return true;
}

CircularQueue::QueueItem CircularQueue::dequeue() {
    if (empty()){
        return EMPTY_QUEUE;
    }
    QueueItem value = items_[head_];
    items_[head_] = EMPTY_QUEUE;
    head_ = (head_ + 1) % capacity_;
    size_--;
    return value;
}

void CircularQueue::print() const {
    for (unsigned int i = 0; i<tail_; i++){
        std::cout<< items_[head_+i] <<", "<< std::endl;
    }
}
