typedef struct student {
    int id;
    char name[30];
    float grade;
} Student;

typedef struct element* List;

List* create_list();
void free_list(List* list);
int size_of_list(List* list);
int list_is_empty(List* list);
int insert_at_beginning(List *list, Student student);
int insert_at_end(List *list, Student student);
int insert_ordered_list(List *list, Student student);
int remove_from_beginning(List *list);
int remove_from_end(List *list);
int remove_by_id(List *list, int id);
int list_data(List *list);
