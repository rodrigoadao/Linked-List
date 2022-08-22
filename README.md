# Linked List!

## Files

- main.c
- LinkedList.h
- LinkedList.c

## Functions

- void free_list(List* list);
- int size_of_list(List* list);
- int list_is_empty(List* list);
- int insert_at_beginning(List *list, Student student);
- int insert_at_end(List *list, Student student);
- int insert_ordered_list(List *list, Student student);
- int remove_from_beginning(List *list);
- int remove_from_end(List *list);
- int remove_by_id(List *list, int id);
- int list_data(List *list);

## How to Compile in Command Prompt?

- gcc -o main main.c LinkedList.c LinkedList.h

It's going to generate a main binary that you can execute using

- ./main

