
#include"s1111413_Card.h"
#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& value) : data(value), next(nullptr) {  }
};

template<typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList();
    ~LinkedList();

    void insertAtFront(const T& value);
    void insertAtBack(const T& value);
    void removeFromFront();
    bool isEmpty() const;
    int getSize() const;
    void changedata(int a, int b);
    T getdata(int x);
    void clear();
    T getfront();
};


#endif
