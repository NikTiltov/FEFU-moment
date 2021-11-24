#include <stdio.h>
#include <stdlib.h>

typedef struct deque_int {
    int val;
    struct deque_int *next;
} node_t;

typedef struct deque_int_interface {
    size_t size;
    node_t *head;
    node_t *tail;
} Deque;

Deque *deque_init() {
    Deque *d = malloc(sizeof(Deque));
    d->head = NULL; d->tail = NULL; d->size = 0;
    return d;
}

void free_deque(Deque *d) {
    if(!d->size) return;
    else if(d->size == 1) {
        free(d->head);
        d->head = NULL; d->tail = NULL; d->size = 0;
        return;
    }

    while(d->head) {
        node_t *tmp = d->head->next;
        free(d->head); d->head = tmp;
    }

    free(d);
    d = NULL;
}

void enqueue(Deque *d, int val) {
    node_t *tmp = malloc(sizeof(node_t));

    if(d->size == 0) {
        d->head = tmp;
        d->tail = tmp;

        tmp->next = NULL;
        tmp->val = val;

        ++d->size;

        return;
    }

    d->tail->next = tmp;
    d->tail = tmp;

    tmp->next = NULL;
    tmp->val = val;

    ++d->size;
}

int dequeue(Deque *d) {
    if(!d->head) return -1;

    node_t *tmp = d->head->next;
    free(d->head);
    d->head = tmp;

    --d->size;

    return 0;
}

int bottom(Deque *d) {
    if(!d->head) return 0;
    return d->head->val;
}

int main() {
    Deque *d = deque_init();

    enqueue(d, 1);
    printf("first in the dequeue = %d; \n", bottom(d));
    dequeue(d);
    enqueue(d, 2);
    printf("first in the dequeue = %d; \n", bottom(d));
    dequeue(d);
    enqueue(d, 3);
    printf("first in the dequeue = %d; \n", bottom(d));
    dequeue(d);
    enqueue(d, 4);
    printf("first in the dequeue = %d; \n", bottom(d));

    free_deque(d);
}
