#ifndef MYSTACK_H_
#define MYSTACK_H_

#include <ctcilib/LinkedListNode.h>

#include <stdexcept>
#include <string>

template<typename T>
class MyStack {
    private:
        ctcilib::LinkedListNode<T>* top_;
    public:
        MyStack();
        T pop();
        void push(T item);
        T peek() const;
        bool is_empty() const;
        std::string to_string() const;
};

template<typename T>
MyStack<T>::MyStack() : top_(nullptr) {}

template<typename T>
T MyStack<T>::pop() {
    if (is_empty()) {
        throw std::range_error("Stack is empty.");
    }
    auto old_top{top_};
    top_ = top_->next_;
    old_top->next_ = nullptr;
    return old_top->data_;
}

template<typename T>
void MyStack<T>::push(T item) {
    if (top_) {
        top_->push_front(item);
    } else {
        top_ = new ctcilib::LinkedListNode<T>(item, nullptr, nullptr);
    }
}

template<typename T>
T MyStack<T>::peek() const {
    if (is_empty()) {
        throw std::range_error("Stack is empty.");
    }
    return top_->data_;
}

template<typename T>
bool MyStack<T>::is_empty() const {
    return !top_;
}

template<typename T>
std::string MyStack<T>::to_string() const {
    if (top_) {
        return top_->print_forward();
    }
    return "";
}

#endif // MYSTACK_H_