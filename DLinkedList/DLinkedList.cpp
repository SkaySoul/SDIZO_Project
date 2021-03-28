//
// Created by hellf on 05.03.2021.
//

#include "DLinkedList.h"
#include <iostream>

DLinkedList* createDLinkedList(unsigned long size) {
    DLinkedList *temp = (DLinkedList*) calloc(size,sizeof(DLinkedList)*size);
    temp->head = temp->tail = nullptr;
    return temp;
}

void deleteDLinkedList(DLinkedList **list) {
    Node *temp = (*list)->head;
    Node *next = nullptr;
    while (temp) {
        next = temp->next;
        free(temp);
        temp = next;
    }
    free(*list);
    *list = nullptr;
}


void pushFront(DLinkedList *list, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == nullptr) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = nullptr;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == nullptr) {
        list->tail = tmp;
    }
    list->size++;
}

int popFront(DLinkedList *list) {
    Node *prev;
    int tmp;
//    if (list->head == nullptr) {
//        exit(2);
//    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = nullptr;
    }
    if (prev == list->tail) {
        list->tail = nullptr;
    }
    tmp = prev->value;
    free(prev);

    list->size--;
    return tmp;
}

void pushBack(DLinkedList *list, int value) {
    Node *p = (Node*) malloc(sizeof(Node));
//    if (tmp == nullptr) {
//        exit(3);
//    }
    p->value = value;
    p->next = nullptr;
    p->prev = list->tail;
    if (list->tail) {
        list->tail->next = p;
    }
    list->tail = p;

    if (list->head == nullptr) {
        list->head = p;
    }
//    list->size++;
}

int popBack(DLinkedList *list) {
    Node *next;
    int tmp;
    if (list->tail == nullptr) {
        exit(4);
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = nullptr;
    }
    if (next == list->head) {
        list->head = nullptr;
    }
    tmp = next->value;
    free(next);

    list->size--;
    return tmp;
}


Node* getN(DLinkedList *list, size_t index) {
    Node *tmp = nullptr;
    size_t i;

    if (index < list->size/2) {
        i = 0;
        tmp = list->head;
        while (tmp && i < index) {
            tmp = tmp->next;
            i++;
        }
    } else {
        i = list->size - 1;
        tmp = list->tail;
        while (tmp && i > index) {
            tmp = tmp->prev;
            i--;
        }
    }

    return tmp;
}

void insert(DLinkedList *list, size_t index, int value) {
    Node *elm = nullptr;
    Node *ins = nullptr;
    elm = getN(list, index);
    if (elm == nullptr) {
        exit(5);
    }
    ins = (Node*) malloc(sizeof(Node));
    ins->value = value;
    ins->prev = elm;
    ins->next = elm->next;
    if (elm->next) {
        elm->next->prev = ins;
    }
    elm->next = ins;

    if (!elm->prev) {
        list->head = elm;
    }
    if (!elm->next) {
        list->tail = elm;
    }

    list->size++;
}

int deleteNth(DLinkedList *list, size_t index) {
    Node *elm = nullptr;
    int tmp = NULL;
    elm = getN(list, index);
    if (elm == nullptr) {
        exit(5);
    }
    if (elm->prev) {
        elm->prev->next = elm->next;
    }
    if (elm->next) {
        elm->next->prev = elm->prev;
    }
    tmp = elm->value;

    if (!elm->prev) {
        list->head = elm->next;
    }
    if (!elm->next) {
        list->tail = elm->prev;
    }

    free(elm);

    list->size--;

    return tmp;
}

//DLinkedList* fromArray(void *arr, size_t n, size_t size) {
//    DLinkedList *tmp = nullptr;
//    size_t i = 0;
//    if (arr == nullptr) {
//        exit(7);
//    }
//
//    tmp = createDLinkedList();
//    while (i < n) {
//        pushBack(tmp, ((char*)arr + i*size));
//        i++;
//    }
//
//    return tmp;
//}
//
//int showValue(int index){
//
//    return
//}