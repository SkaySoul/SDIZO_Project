//
// Created by hellf on 06.03.2021.
//

#include "Node.h"

Node::Node(Node *prev, Node *next, int value) {
    this->value = value;
    this->next = next;
    this->prev = prev;
}

