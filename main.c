#include <snekobject.h>
#include <stack.h>
#include <stdio.h>

int main(void) {
    printf("Starting the Sneklang interpreter...\n");
    stack_t *stack = stack_new(10);
    printf("size of stack: %zu\n", sizeof(*stack));
    snek_object_t *str = new_snek_string("abc");
    stack_push(stack, str);
    snek_object_t *vec = new_snek_vector3(
        new_snek_string("x"),
        new_snek_string("y"),
        new_snek_string("z"));
    stack_push(stack, vec);
    printf("snek object str: %s\n", str->data.v_string);

    snek_object_t *vec1 = new_snek_vector3(
    new_snek_string("1"),
    new_snek_string("1"),
    new_snek_string("1"));

    snek_object_t *added_vecs = snek_add(vec, vec1);
    printf("added_vecs x: %s\n", added_vecs->data.v_vector3.x->data.v_string);
    printf("added_vecs y: %s\n", added_vecs->data.v_vector3.y->data.v_string);
    printf("added_vecs z: %s\n", added_vecs->data.v_vector3.z->data.v_string);

    return 0;
}
