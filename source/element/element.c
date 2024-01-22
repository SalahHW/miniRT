#include "../../include/miniRT.h"

t_element *init_element(void)
{
    t_element *new_element;

    new_element = (t_element *)malloc(sizeof(t_element));
    if (!new_element)
        return (NULL);
    new_element->identifier = unknown;
    new_element->next = NULL;
    return (new_element);
}