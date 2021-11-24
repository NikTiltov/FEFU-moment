#include <stdio.h>
#include <stdlib.h>

typedef struct stack_int_node {
    int val;
    struct stack_int_node *prev;
} node_t;

typedef struct stack_interface {
    struct stack_int_node *head;
    size_t size;
} Stack;

Stack *stack_init() {
    Stack *s = malloc(sizeof(Stack));
    s->head = NULL; s->size = 0;
    return s;
}

void push(Stack *s, int val) {
    node_t *tmp = s->head;
    s->head = malloc(sizeof(node_t));

    s->head->val = val;
    s->head->prev = tmp;

    ++s->size;
}

int pop(Stack *s) {
    if(!s->head) return -1;

    node_t *tmp = s->head->prev;
    free(s->head);
    s->head = tmp;
    --s->size;

    return 0;
}

void print(Stack *s) {
    node_t *cur = s->head;
    while(cur) {
        printf("%d ", cur->val);
        cur = cur->prev;
    }
}

int top(Stack *s) {
    if(!s->head) return 0;
    return s->head->val;
}

int main() {
    Stack *s = stack_init();

    push(s, 1);
    push(s, 2);
    push(s, 3);

    print(s);
    printf("\n");

    printf("size = %llu; top = %d;\n", s->size, top(s));
    pop(s);
    printf("size = %llu; top = %d;\n", s->size, top(s));
    pop(s);
    printf("size = %llu; top = %d;\n", s->size, top(s));
    pop(s);

    free(s);
}
