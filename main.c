#include <stack.h>
#include <stdio.h>

int main(void) {
    printf("Starting the Sneklang interpreter...\n");
    stack_t *stack = stack_new(10);
    printf("size of stack: %zu\n", sizeof(*stack));
    return 0;
}
