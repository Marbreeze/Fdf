#include "fdf.h"

int     main(int ac, char**av)
{
    int fd;
    t_fdf **fdf;

    if(ac != 2)
    {
        ft_putstr("Usage: ./fdf <filename>\n");
        return (0);
    }
    if(ac == 2)
    {
        // fd = open(av[1], O_RDONLY);
        // if(fd <= 0)
        // {
        //     perror("error");
        //     exit(1);
        // }
        if (read_n_check(av[1], &fdf) == -1)
        {
            ft_putstr("BAD");
            return (0);
        }
        // draw(fdf);
        
        

    }
}