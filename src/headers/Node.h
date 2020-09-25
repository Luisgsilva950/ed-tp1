//
// Created by @Luis G. on 21/09/20.
// Was necessary implement the methods in .h file because i wanted use templates.
//
#ifndef ED_TP1_NODE_H
#define ED_TP1_NODE_H

/**
 * This class is a Node for implement the TAD`s of project. Has 3 attributes, the value, the next, representing the next node of TAD
 * and the previous, representing the previous node of TAD.
 *
 * @tparam T Represent the type that will be stored in the TAD.
 */
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

    bool isNull() {
        return this == nullptr;
    }
};


#endif //ED_TP1_NODE_H
