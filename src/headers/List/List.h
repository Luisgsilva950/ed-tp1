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
            this->first->setPrevious(newNode);
            this->first = newNode;
        }
    }

    T getFirst() {
        return this->first->getValue();
    }

    void popLast() {
        Node<T> *previousNode = this->last->getPreviousNode();
        if (!previousNode->isNull()) previousNode->setNext(nullptr);
        this->last = previousNode;
    }

    void popFirst() {
        Node<T> *nextNode = this->first->getNextNode();
        if (!nextNode->isNull()) nextNode->setPrevious(nullptr);
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

    void removeByValue(T value) {
        if (this->first->getValue() == value) {
            this->popFirst();
        } else if (this->last->getValue() == value) {
            this->popLast();
        } else {
            Node<T> *node = this->first;
            while (!node->isNull()) {
                if (node->getValue() == value) {
                    Node<T> *before = node->getPreviousNode();
                    Node<T> *after = node->getNextNode();
                    if (!before->isNull()) {
                        before->setNext(after);
                    } else if (!after->isNull()) {
                        after->setPrevious(nullptr);
                    }
                    if (!after->isNull()) {
                        after->setPrevious(before);
                    } else if (!before->isNull()) {
                        before->setNext(nullptr);
                    }
                }
                node = node->getNextNode();
            }
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
