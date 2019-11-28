//
// Created by msi on 11/27/2019.
//
#include <vector>
#include <iostream>
#include<algorithm> // for heap
#ifndef HEAP_HEAP_HPP
#define HEAP_HEAP_HPP
using namespace std;

// implementing singleton design pattern
template <typename T>
class heap {
public:
    static heap& get_instance(vector<T> t)
    {
        static heap instance{t};
        return instance; // Instantiated on first use.
    }
private:
    vector<T> myV;
    void heapify();  // in heap form
    // constructing heap
    heap(vector<T> v);
public:
    // disable copy and = operator
    heap(heap const&) = delete;
    void operator=(heap const&) = delete;

    // push to heap
    void push(T data);
    // pop the max
    void pop();
    // size of heap
    int size() {
        return myV.size();
    }
    // if heap is empty
    bool is_empty() {
        return myV.empty();
    }
    // delete all values in heap
    void clear() {
        myV.clear();
    }
    // printing heap
    template <typename T1>
    friend ostream & operator << (ostream &os, heap<T1> &hp);
};

// constructing heap
template <typename T>
heap<T>::heap(vector<T> v) {
    myV = v;
    heapify();
}
// format to heap form
template <typename T>
void heap<T>::heapify() {
    make_heap(myV.begin(), myV.end());
}
// push data to heap
template <typename T>
void heap<T>::push(T data) {
    myV.push_back(data);
    heapify();
}
// pop the max root
template <typename T>
void heap<T>::pop() {
    pop_heap(myV.begin(), myV.end());
    myV.pop_back();
    heapify();
}
// printing heap
template <typename T1>
ostream &operator<< (ostream &os, heap<T1> &hp) {
    for (T1 &x : hp.myV)
        os << x << " ";
    return os;
}

#endif //HEAP_HEAP_HPP
