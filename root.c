#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int    ft_def_code(void)
{
    int r = rand() % (999999 - 111111) + 111111;
    return (r);
}

char     ft_rand_digit(void)
{

    int     i = 0;
    
    i = rand() % 100;
    if ((i > 47 && i < 57) || (i > 64 && i < 70))
        return (i);
    else
        ft_rand_digit();
}

int    ft_print_pgms(char *c)
{
    int     i = 0;
    int     t = 0;

    while (c[i] != '\0')
    {
        if (c[i] == 'A' || c[i] == 'B' || c[i] == 'C' || c[i] == 'D' || c[i] == 'E')
        {    
            ft_putchar(c[i]);
            i++;
            t++;
        }
        else
            i++;
    }
    if (t == 0)
    {
        printf("< NO PROGRAMS FOUND >\n");
        return (0);
    }
    else
    {
        ft_putchar('\n');
        return (1);
    }
}

void    ft_table(char pstack, char dstack)
{
    printf("PRO DAT\n");
    printf("[%c] [%c]\n", pstack, dstack);
}

int     main(void)
{
    int     i = 0;
    int     sec = 10;
    int     pcode = ft_def_code();
    int     aicode = ft_def_code();
    int     pgms = 0;
    char    psys[7];
    char    aisys[7];
    char    pobj = '0';
    char    aiobj = '0';
    char    pgmdump = '0';
    char    pstack = ' ';
    char    dstack = ' ';
    
    //GENERATING ACCESS CODES

    srand(time(NULL));
/*
    printf("\nGENERATING PLAYER'S ACCESS CODE\n");
    printf("%d\n\n", pcode);
    sleep(1);
    printf("GENERATING AI'S ACCESS CODE\n");
    printf("%d\n\n", aicode);
    printf("\n");
    sleep(1);
    while (sec >= 0)
    {
        printf("\033[A\33[2KT\rPLAYERS HAVE NOW %d SECONDS TO REMEMBER OPPONENT CODE\n", sec);
        sec--;
        sleep(1);
    }
    system("clear");
*/
    //GENERATING SYSTEMS

    while (i <= 5)
    {
        psys[i] = ft_rand_digit();
        i++;
    }
    psys[i] = '\0';
    i = 0;

    printf("\nGENERATING PLAYER'S SYSTEM\n");
    printf("%s\n\n", psys);
    sleep(1);

    while (i <= 5)
    {
        aisys[i] = ft_rand_digit();
        i++;
    }
    aisys[i] = '\0';
    i = 0;

    printf("GENERATING AI'S SYSTEM\n");
    printf("%s\n\n", aisys);
    sleep(1);

    //PLAYER GETS OBJECT
    
    pobj = ft_rand_digit();
    printf("PLAYER GETS OBJECT\n%c\n\n", pobj);
    sleep(1);

    //PLAYER SENDS PROGRAM
    
    printf("AVAILABLE PROGRAMS\n");
    pgms = ft_print_pgms(psys);
    sleep(1);

    if (pgms == 1)
    {
        printf("WHAT PROGRAM DO YOU WANT TO SEND ?\n");
        scanf("%c", &pgmdump);
        pstack = pgmdump;
        printf("\nSENDING %c TO STACK\n\n", pgmdump);
    }
    ft_table(pstack, dstack);


    return (0);
}
