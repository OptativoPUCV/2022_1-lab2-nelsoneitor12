#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
     List *lista=(List*) calloc(1, sizeof(List));
  lista->head=NULL;
  lista->current=NULL;
  lista->tail=NULL;
  return lista;
}

void * firstList(List * list) {

if(list->head && list->head->data){
    list->current = list->head;
    return list->head->data;
}
  return NULL;
}

void * nextList(List * list) {
  if(list->current && list->current->next){
    list->current=list->current->next;
    return list->current->data;
  }
  return NULL;
}

void * lastList(List * list) {
  if(list->tail && list->tail->data){
    list->current=list->tail;
    return list->tail->data;
  }
  return NULL;
}

void * prevList(List * list) {
    if(list->current && list->current->prev){
        list->current=list->current->prev;
        return list->current->data;
    }
    return NULL;
}

void pushFront(List * list, void * data) {
    Node *n= createNode(data);
    if(list->current && list->head){
        n->prev=list->head->prev;
        list->head->prev=n;
        n->next=list->head;
        list->current=list->head;
        list->head=n;
    }
    else{
        list->head=n;
        list->tail=list->head;
        list->current=list->head;
    }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
    Node *n= createNode(data);
    if(list->current){
        n->next=list->current->next;
        n->prev=list->current;
        list->current->next=n;
        if(list->current==list->tail){
            list->tail=list->current->next;
        }
       if(list->head==list->tail){
           list->tail=list->current->next;
       }
        list->current=list->current->next;
    }
}
void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    if(list->current){
        list->current->prev->next=list->current->next;
        list->current->next->prev=list->current->prev;
        return list->current->data;
        list->current=list->current->prev;
    }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}