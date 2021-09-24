#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
    int i;
    while (begin_list)
    {
        begin_list = begin_list->next;
        ++i;
    }
    return (i);
}
