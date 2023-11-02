#include <push_swap.h>

void print_push_swap_data(t_push_swap_data* data) 
{
    printf("Stack A: ");
    t_list_node* current = data->stackA.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("Stack B: ");
    current = data->stackB.top;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");

    printf("LIS Length: %d\n", data->lisLength);
}
