#include <stdio.h>
char *ft_backslash(char *hold)
{
    int i = 0;
    if(!hold)
        return NULL;
    while(hold[i])
    {
        if(hold[i] == '\n')
            return hold + i;
        i++;
    }
    return 0;
}
int main()
{
    char hold[] = "hello we are the best\nher";
    printf("%s", ft_backslash(hold));
}