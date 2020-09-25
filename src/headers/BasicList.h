#include <iostream>
#include "Node.h"
//
// Created by @Luis G. on 21/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//

using namespace std;
#ifndef ED_TP1_LIST_H
#define ED_TP1_LIST_H

/**
 * This class represent the basic list doubly chained TAD. Basic because the are not all methods implemented here. Only necessary for
 * do the School Job.
 *
 * @tparam T Represent the type that will be stored in the TAD.
 */
template<class T>
class BasicList {
private:
    Node<T> *first;
    Node<T> *last;
public:
    BasicList() {
        this->first = nullptr;
        this->last = nullptr;
    }

    explicit BasicList(T value) {
        this->first = new Node<T>(value);
        this->last = nullptr;
    }

    ~BasicList() {
        this->first = nullptr;
    }

    bool isEmpty() {
        return this->first == nullptr;
    }

    void insertOnFront(T value) {
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
};

#endif //ED_TP1_LIST_H
