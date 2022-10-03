#include "push_swap.h"

t_list  *create_lst(char *charray[])
{
    int     i;
    int     *tmp;
    t_list  *lst;

    i = 0;
    while (charray[i])
    {
        tmp = ft_calloc(1, sizeof(int));
        *tmp = ft_atoi(charray[i]);
        ft_lstadd_back(&lst, ft_lstnew(tmp));

        i++;
    }
    return (lst);
}

int main(int argc, char *argv[])
{
    t_list  *args;

    if (argc < 2)
    {
        write(1, "Not enough arguments\n", 22);
        return (0);
    }
    args = create_lst(argv);
    ft_lstprint(args);
    // ft_atoi
    

    return (0);
}