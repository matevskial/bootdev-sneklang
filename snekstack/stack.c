#include "stack.h"
#include <stdlib.h>

stack_t *stack_new(size_t capacity) {
    stack_t *new_stack = (stack_t*)malloc(sizeof(stack_t));
    if (new_stack == NULL) {
        return NULL;
    }
    new_stack->count = 0;
    new_stack->capacity = capacity;
    new_stack->data = (void**)malloc(capacity * sizeof(void*));
    if (new_stack->data == NULL) {
        free(new_stack);
        return NULL;
    }
    return new_stack;
}

void stack_push(stack_t *stack, void *obj) {
    if (stack->count >= stack->capacity) {
        size_t new_capacity = stack->capacity == 0 ? 2 : stack->capacity * 2;
        void **new_data = realloc(stack->data, new_capacity);
        if (new_data == NULL) {
            free(stack->data);
            return;
        }
        stack->capacity = new_capacity;
        stack->data = new_data;
    }
    stack->data[stack->count] = obj;
    stack->count++;
}

void *stack_pop(stack_t *stack) {
    if (stack->count == 0) {
        return NULL;
    }
    void *obj = stack->data[stack->count - 1];
    stack->count--;
    return obj;
}

void stack_free(stack_t *stack) {
    if (stack == NULL) {
        return;
    }
    if (stack->data == NULL) {
        return;
    }
    free(stack->data);
    free(stack);
}
