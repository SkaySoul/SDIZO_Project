//
// Created by hellf on 4/13/2021.
//

#ifndef SDIZO_PROJECT_NODE_H
#define SDIZO_PROJECT_NODE_H


class Node {
public:
    Node *lch;
    Node *rch;
    Node *parent;
    int val;
    Node(Node *parent, Node *lch, Node *rch, int val);
};


#endif //SDIZO_PROJECT_NODE_H
