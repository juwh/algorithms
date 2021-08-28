#ifndef MYQUEUE_H_
#define MYQUEUE_H_

#include <ctcilib/LinkedListNode.h>

#include <stdexcept>
#include <string>

template<typename T>
class MyQueue {
    private:
        ctcilib::LinkedListNode<T>* front_;
        std::string to_string_recursive(ctcilib::LinkedListNode<T>* node) const;
    public:
        MyQueue();
        void add(T item);
        T remove();
        T peek() const;
        bool is_empty() const;
        std::string to_string() const;
};

template<typename T>
std::string MyQueue<T>::to_string_recursive(ctcilib::LinkedListNode<T>* node) const {
    if (!node) {
        return "";
    }
    auto out{to_string_recursive(node->next_)};
    return out + (out.empty() ? "" : "->") + std::to_string(node->data_);
}

template<typename T>
MyQueue<T>::MyQueue() : front_(nullptr) {}

template<typename T>
void MyQueue<T>::add(T item) {
    if (front_) {
        front_->push_back(item);
    } else {
        front_ = new ctcilib::LinkedListNode<T>(item, nullptr, nullptr);
    }   
}

template<typename T>
T MyQueue<T>::remove() {
    if (is_empty()) {
        throw std::range_error("Queue is empty.");
    }
    auto old_front{front_};
    front_ = front_->next_;
    old_front->next_ = nullptr;
    return old_front->data_;
}

template<typename T>
T MyQueue<T>::peek() const {
    if (is_empty()) {
        throw std::range_error("Queue is empty.");
    }
    return front_->data_;
}

template<typename T>
bool MyQueue<T>::is_empty() const {
    return !front_;
}

template<typename T>
std::string MyQueue<T>::to_string() const {
    return to_string_recursive(front_);
}

#endif // MYQUEUE_H_