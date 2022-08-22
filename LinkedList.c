#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

typedef struct element {
    struct student data;
    struct element *prox;
} Element;

List* create_list() {
    List* list = (List*) malloc(sizeof(List));
    if (list != NULL) {
        *list = NULL;
    }

    return list;
}

void free_list(List* list) {
    if (list != NULL) {
        Element* node;
        while((*list) != NULL) {
            node = *list;
            *list = (*list)->prox;
            free(node);
        }
        free(list);
    }
}

int size_of_list(List* list) {
    if( list == NULL ) {
        return 0;
    }

    int count = 0;
    Element* node = *list;
    while(node != NULL) {
        count++;
        node = node->prox;
    }
    return count;
}

int list_is_empty(List* list) {
    if (list == NULL) {
        return 1;
    }

    if (*list == NULL) {
        return 1;
    }

    return 0;
}

int insert_at_beginning(List *list, Student student) {
    if (list == NULL) {
        return 0;
    }

    Element* node = (Element*) malloc(sizeof(Element));
    if (node == NULL) {
        return 0;
    }

    node->data = student;
    node->prox = (*list);
    *list = node;

    return 1;
}

int insert_at_end(List* list, Student student) {
    if (list == NULL) {
        return 0;
    }

    Element *node = (Element*) malloc(sizeof(Element));
    if (node == NULL) {
        return 0;
    }

    node->data = student;
    node->prox = NULL;

    if ((*list) == NULL) {
        *list = node;
    } else {
        Element *helper = *list;
        while (helper->prox != NULL) {
            helper = helper->prox;
        }

        helper->prox = node;
    }

    return 1;
}


int insert_ordered_list(List *list, Student student) {
  Element *node = (Element*) malloc(sizeof(Element));
  node->data = student;

  if (list_is_empty(list)) {
      node->prox = (*list);
      *list = node;
      return 1;
  } else {
    Element *previous, *current = *list;
    while(current != NULL && current->data.id < student.id) {
        previous = current;
        current = current->prox;
    }

    if ( current == *list ) {
        node->prox = (*list);
        *list = node;
    } else {
        node->prox = previous->prox;
        previous->prox = node;
    }

    return 1;
  }
}

int remove_from_beginning(List *list) {
    if(list_is_empty(list)) {
        return 0;
    }

    Element *node = *list;
    *list = node->prox;
    free(node);
    return 1;
}

int remove_from_end(List *list) {
    if(list_is_empty(list)) {
        return 0;
    }

    Element *previous, *current = *list;
    while(current->prox != NULL) {
        previous = current;
        current = current->prox;
    }

    if (current == (*list)) {
        *list = current->prox;
    } else {
        previous->prox = current->prox;
        free(current);
    }

    return 1;
}

int remove_by_id(List *list, int id) {
    if(list_is_empty(list)) {
        return 0;
    }

    Element *previous, *current = *list;
    while (current != NULL && current->data.id != id){
        previous = current;
        current = current->prox;
    }

    if (current == NULL) {
        printf("Student not found!");
        return 0;
    }

    if (current == *list) {
        *list = current->prox;
    } else {
        previous->prox = current->prox;
        free(current);
    }

    return 1;
}

int search_by_id(List *list, int id, Student *student) {
    if (list_is_empty(list)) {
        return 0;
    }

    Element *node = *list;
    while(node != NULL && node->data.id != id) {
        node = node->prox;
    }

    if (node == NULL) {
        return 0;
    } else {
        *student = node->data;
        return 1;
    }
}


int list_data(List *list) {
    if(list_is_empty(list)){
        return 0;
    }

    Element *list_aux = *list;
    while (list_aux != NULL){
        printf("--------- -------- -------- ------- \n");
        printf("ID: %d\n", list_aux->data.id);
        printf("Name: %s\n", list_aux->data.name);
        printf("Grade: %.2f\n", list_aux->data.grade);
        list_aux = list_aux->prox;
    }

    return 1;
}
