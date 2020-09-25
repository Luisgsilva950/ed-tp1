#include <iostream>
#include "Node.h"

//
// Created by @Luis G. on 24/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//

#ifndef ED_TP1_QUEUE_H
#define ED_TP1_QUEUE_H

/**
 * This class represent the Queue TAD. Only the necessary methods are implemented here.
 *
 * @tparam T Represent the type that will be stored in the TAD.
 */
template<class T>
class Queue {
private:
    Node<T> *first;
    Node<T> * last;
public:
    Queue() {
        this->first = nullptr;
        this->last = nullptr;
    }

    explicit Queue(T value) {
        this->first = new Node<T>(value);
        this->last = nullptr;
    }

    ~Queue() {
        this->first = nullptr;
    }

    bool isEmpty() {
        return this->first == nullptr;
    }
    void insert(T value) {
        Node<int> *newNode = new Node<T>(value);
        if (isEmpty()) {
            this->first = newNode;
            this->last = newNode;
        } else {
            this->last->setNext(newNode);
            this->last = newNode;
        }
    }

    void pop() {
        Node<T> *nextNode = this->first->getNextNode();
        if (!nextNode->isNull()) nextNode->setPrevious(nullptr);
        this->first = nextNode;
    }

    T get() {
        return this->first->getValue();
    }

    void showList() {
        if (!this->isEmpty()) {
            Node<T> *element = this->first;
            while (element) {
                std::cout << element->getValue() << std::endl;
                element = element->getNextNode();
            }
        }
    }
};

#endif //ED_TP1_QUEUE_H
