#include <stdio.h>
#include <malloc.h>

typedef struct NodeStruct {
    int data;
    struct NodeStruct* next;
} node;

void print_list(node *head)
{
    node *current_node = head;
    while (current_node != NULL)
    {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}


void insert_node(node *head, int val)
{
    node *current_node = head;
    while (current_node->next != NULL)
        current_node = current_node->next;

    node* new_node = malloc(sizeof(node));

    new_node->data = val;
    new_node->next = NULL;
    current_node->next = new_node;
}

void delete_node(node **head, node *node_to_delete)
{
    if (node_to_delete == *head)
    {
        node* next_node = (*head)->next;
        free(*head);
        *head = next_node;
        return;
    }

    node *current_node = *head;
    while (current_node->next != node_to_delete)
        current_node = current_node->next;

    current_node->next = node_to_delete->next;
    free(node_to_delete);
}

void find_and_delete(node **head, int val)
{
    node *current_node = *head;
    while (current_node->data != val)
        current_node = current_node->next;

    delete_node(head, current_node);
}

int main() {

    node* head = malloc(sizeof(node));

    head->data = 1;
    head->next = NULL;

    insert_node(head, 2);
    insert_node(head, 3);
    insert_node(head, 4);

    print_list(head);

    find_and_delete(&head,1);

    print_list(head);

    return 0;
}