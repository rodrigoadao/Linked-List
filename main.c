#include <stdio.h>
#include <string.h>
#include "LinkedList.h"

void menu();
struct student create_student();
void handle_message();

int main() {
    List *list;
    list = create_list();
    menu(list);
    return 1;
}

void menu(List *list) {
    int option, size, id;
    struct student student;
    do {
        printf("- - - LIST - - -\n");
        printf("1 - INSERT AT THE BEGINNING: \n");
        printf("2 - INSERT AT THE END: \n");
        printf("3 - INSERT ORDERED: \n");
        printf("4 - REMOVE FROM THE BEGINNING: \n");
        printf("5 - REMOVE FROM THE END: \n");
        printf("6 - REMOVE BY ID: \n");
        printf("7 - LIST DATA: \n");
        printf("8 - LIST SIZE: \n");
        printf("0 - QUIT: \n\n");

        scanf("%d", &option);
        switch (option)
        {
            case 1:
                student = create_student();
                handle_message(insert_at_beginning(list, student));
            break;
            case 2:
                student = create_student();
                handle_message(insert_at_end(list, student));
            break;
            case 3:
                student = create_student();
                handle_message(insert_ordered_list(list, student));
            break;
            case 4:
                handle_message(remove_from_beginning(list));
            break;
            case 5:
                handle_message(remove_from_end(list));
            break;
            case 6:
                printf("ID: ");
                scanf("%d", &id);
                handle_message(remove_by_id(list, id));
            break;
            case 7:
                handle_message(list_data(list));
            break;
            case 8:
                size = size_of_list(list);
                printf("LIST SIZE: %d\n", size);
            break;
        }
    } while (option != 0);

}

struct student create_student() {
    struct student student;
    char name[20];

    printf("ID: ");
    scanf("%d",&student.id);

    printf("NAME: ");
    scanf("%s",name);
    strcpy(student.name,name);

    printf("GRADE: ");
    scanf("%f",&student.grade);

    return student;
}

void handle_message(int value) {
    if (value) {
        printf("\n- - - SUCESS - - -\n");
    } else {
        printf("\n- - - FAILED - - -\n");
    }
}
