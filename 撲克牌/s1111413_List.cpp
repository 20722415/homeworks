#include"s1111413_List.h"
#include<iostream>
#include<iomanip>
using namespace std;



template<typename T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
   
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
    
}
template<typename T>
void LinkedList<T>::insertAtFront(const T& value) {
    Node<T>* newNode = new Node<T>(value);              
    if (isEmpty()) {
        head = tail = newNode;
     
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}
template<typename T>
T LinkedList<T>::getdata(int x)
{
    Node<T>* current = head;
    for (int i = 0; i < x; i++)
    {
        current = current->next;
    }

    return current->data;

}
template<typename T>
void LinkedList<T>::changedata(int a, int b)
{
    T temp = getdata(a);
        Node<T>* current = head;
    for (int i = 0; i < a; i++)
    {
        current = current->next;
    }
    current->data = getdata(b);
    current = head;
    for (int i = 0; i < b; i++)
    {
        current = current->next;
    }
    current->data = temp;
}
template<typename T>
void LinkedList<T>::insertAtBack(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;

}

template<typename T>
void LinkedList<T>::removeFromFront() {
    if (isEmpty()) {
        return;
    }

    Node<T>* temp = head;
    if (head == tail) {
    
        head = tail = nullptr;
    }
    else {
        head = head->next;
    }
    delete temp;
    size--;
}
template<typename T>
T LinkedList<T>::getfront()
{
    return head->data;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
void LinkedList<T>::clear() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    size = 0;
    
}


template class LinkedList<Card>;


