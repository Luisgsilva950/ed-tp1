#include <iostream>
#include "../Node/Node.h"
//
// Created by @Luis G. on 21/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//

using namespace std;
#ifndef ED_TP1_LIST_H
#define ED_TP1_LIST_H

template<class T>
class List {
private:
    Node<T> *first;
    Node<T> *last;
public:
    List() {
        this->first = nullptr;
        this->last = nullptr;
    }

    explicit List(T value) {
        this->first = new Node<T>(value);
        this->last = nullptr;
    }

    ~List() {
        this->first = nullptr;
    }

    bool isEmpty() {
        return this->first == nullptr;
    }

    void insertOnFront(T value) {
        auto *newNode = new Node<T>(value);
        if (isEmpty()) {
            this->first = newNode;
            this->last = newNode;
        } else {
            newNode->setNext(this->first);
            first->setPrevious(newNode);
            this->first = newNode;
        }
    }

    T getFirst() {
        return this->first->getValue();
    }

    void popFirst() {
        Node<T> *nextNode = this->first->getNextNode();
        nextNode->setPrevious(nullptr);
        this->first = nextNode;
    }

    void insertOnLast(T value) {
        auto *newNode = new Node<T>(value);
        if (isEmpty()) {
            this->first = newNode;
            this->last = newNode;
        } else {
            this->last->setNext(newNode);
            this->last = newNode;
        }
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

#endif //ED_TP1_LIST_H
