#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

void push_back(node_t **head, int value) {
    if(!*head) {
        *head = (node_t*) malloc(sizeof(node_t));
        (*head)->val = value;
        (*head)->next = NULL;
    } else {
        node_t *cur = *head;
        while(cur->next) {
            cur = cur->next;
        }

        cur->next = (node_t *) malloc(sizeof(node_t));
        cur->next->val = value;
        cur->next->next = NULL;
    }
}

void push_front(node_t **head, int value) {
    node_t *tmp = (node_t*) malloc(sizeof(node_t));
    tmp->val = value;
    tmp->next = *head;
    *head = tmp;
}

int pop_front(node_t **head) {
    if(!*head) return -1;

    node_t *tmp = *head;
    *head = (*head)->next;
    free(tmp);

    return 0;
}

int pop_back(node_t **head) {
    if(!*head) return -1;

    if(!(*head)->next) {
        free(*head);
        *head = NULL;
        return 0;
    }

    node_t *cur = (*head)->next, *tmp = NULL;
    while(cur->next) {
        tmp = cur;
        cur = cur->next;
    }
    free(cur);
    tmp->next = NULL;

    return 0;
}

int remove_by_value(node_t **head, int value) {
    if(!*head) return -1;

    node_t *cur = *head, *tmp = *head;
    while(cur) {
        if(cur->val == value) {
            if(cur == *head) {
                *head = cur->next;
            } else {
                tmp->next = cur->next;
            }
            free(cur);
            return 0;
        }
        tmp = cur;
        cur = cur->next;
    }

    return -1;
}

void print_list(node_t *head) {
    node_t *cur = head;
    while(cur) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
}

void free_list(node_t **head) {
    node_t *cur = *head;
    while(cur) {
        node_t *tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    *head = NULL;
}

int main() {
    node_t *head = NULL;
    push_front(&head, 1);
    push_back(&head, 2);
    print_list(head);
    pop_front(&head);
    pop_back(&head);
    push_front(&head, 1);
    remove_by_value(&head, 2);
    free_list(&head);
}
