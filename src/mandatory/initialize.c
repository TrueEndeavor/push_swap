
#include <push_swap.h>

t_push_swap_data *initialize_push_swap_data(int ac, char **av) 
{
    t_push_swap_data *data = (t_push_swap_data *)malloc(sizeof(t_push_swap_data));
    if (data == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    data->stackA.top = NULL;
    data->stackA.bottom = NULL;
    data->stackA.size = 0;

    data->stackB.top = NULL;
    data->stackB.bottom = NULL;
    data->stackB.size = 0;

    data->head = NULL;
    data->lisLength = 0;

 	for (int i = ac - 1; i >= 1; i--) {
        t_list_node* new_node = create_new_node(atoi(av[i]));

        // Add the new node to stackA
        if (data->stackA.top == NULL) {
            data->stackA.top = new_node;
            data->stackA.bottom = new_node;
        } else {
            new_node->next = data->stackA.top;
            data->stackA.top->prev = new_node;
            data->stackA.top = new_node;
        }
        data->stackA.size++;
    }
    return data;
}

t_list_node *create_new_node(int data) 
{
    t_list_node *new_node = (t_list_node *)malloc(sizeof(t_list_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return NULL;
    }
    new_node->data = data;
    new_node->lis = 0; // Initialize lis to 0
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
