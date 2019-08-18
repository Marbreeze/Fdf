#include "fdf.h"

int error_check_function(int ac, char *av, int fd, char *buffer, char *map)
{
    if (ac != 2 && (fd = open(av[1], O_RDONLY) > 0)
    {
        error_function();
        return (1);
    }
    else if (check_size_function(buffer, map) == EXIT_FAILURE)
    {
        error_funtion();
        return (1);
    }
    else
        return (0);
}

int check_size_function(char *buffer, char *map)
{
    if (!(buffer = ft_strnew(1500))
    {
        error_function();
        return (1);
    }
    else if (!(map = ft_strnew(1500)))
    {
        error_function()
        return (1);
    }
    else
        return (0);
}

void    error_function(void)
{
    ft_putstr("error");
}