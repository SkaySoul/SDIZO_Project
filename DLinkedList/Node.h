//
// Created by hellf on 06.03.2021.
//

#ifndef SDIZO_PROJECT_NODE_H
#define SDIZO_PROJECT_NODE_H


class Node {
public:
        int value;
        Node * prev;
        Node * next;
        Node(Node *prev,Node *next, int value);

};


#endif //SDIZO_PROJECT_NODE_H
