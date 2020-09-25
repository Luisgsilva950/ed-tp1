#include <iostream>
#include "Node.h"

//
// Created by @Luis G. on 24/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//

#ifndef ED_TP1_STACK_H
#define ED_TP1_STACK_H

/**
 * This class represent the Stack TAD. Only the necessary methods are implementeds here.
 *
 * @tparam T Represent the type that will be stored in the TAD.
 */
template<class T>
class Stack {
private:
    Node<T> *first;
    Node<T> *last;
public:
    Stack() {
        this->first = nullptr;
        this->last = nullptr;
    }

    explicit Stack(T value) {
        this->first = new Node<T>(value);
        this->last = nullptr;
    }

    ~Stack() {
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
            newNode->setNext(this->first);
            this->first->setPrevious(newNode);
            this->first = newNode;
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

#endif //ED_TP1_STACK_H
