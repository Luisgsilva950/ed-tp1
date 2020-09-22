//
// Created by @Luis G. on 21/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//
#ifndef ED_TP1_NODE_H
#define ED_TP1_NODE_H

template<class T>
class Node {
private:
    T value;
    Node *next;
    Node *previous;
public:
    Node(T value) {
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }

    T getValue() {
        return this->value;
    }

    Node *getNextNode() {
        return this->next;
    }

    Node *getPreviousNode() {
        return this->previous;
    }

    void setNext(Node *node) {
        this->next = node;
    }

    void setPrevious(Node *node) {
        this->previous = node;
    }
};


#endif //ED_TP1_NODE_H
