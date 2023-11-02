#include <push_swap.h>

void free_push_swap_data(t_push_swap_data *data) 
{
    t_list_node *current = data->head;
    while (current != NULL) {
        t_list_node *temp = current;
        current = current->next;
        free(temp);
    }

    // Free remaining stack nodes if any
    while (data->stackA.top != NULL) {
        t_list_node *temp = data->stackA.top;
        data->stackA.top = data->stackA.top->next;
        free(temp);
    }

    while (data->stackB.top != NULL) {
        t_list_node *temp = data->stackB.top;
        data->stackB.top = data->stackB.top->next;
        free(temp);
    }

    // Free the main structure
    free(data);
}
