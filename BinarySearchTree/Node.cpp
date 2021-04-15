//
// Created by hellf on 4/13/2021.
//

#include "Node.h"


Node::Node(Node *parent, Node *lch, Node *rch, int val){
    this->lch = lch;
    this->rch = rch;
    this-> parent = parent;
    this->val  = val;
}