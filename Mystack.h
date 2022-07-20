#include <iostream>
#include <algorithm>
#ifndef MYSTACK__
#define MYSTACK__
#define init 500
template<typename T>
class Stack
{
    public:
    Stack<T>() {capacity_ = init; data_ = new T[init];}
    T operator[](size_t index) const;
    void push(const T data);
    void pop();
    size_t size() const;
    T top() const;
    T buttom() const;
    bool isEmpty() const;
    void clear();

    private:
    size_t size_ = 0;
    size_t capacity_ = 0;
    T* data_ = nullptr;
};

template<typename T> T Stack<T>::operator[](size_t index) const
{
	return *(data_+index);
}
template<typename T> T Stack<T>::buttom() const
{
    if(!size_) return NULL;
    return data_[0];
};
template<typename T> T Stack<T>::top() const
{
    if(!size_) return NULL;
    return data_[size_-1];
};
template<typename T> size_t Stack<T>::size() const
{
    return size_;
};
template<typename T> bool Stack<T>::isEmpty() const
{
    return !size_;
}
template<typename T> void Stack<T>::push(const T data)
{
        data_[size_] = data;
        ++size_;
}
template<typename T> void Stack<T>::pop()
{
    if(size_ == 0)
        std::cout<<"stack is empty.";
    else
        --size_;
}
template<typename T> void Stack<T>::clear()
{
    delete [] data_;
    data_ = new T[init];
    capacity_ = init;
    size_ = 0;
}
#endif
