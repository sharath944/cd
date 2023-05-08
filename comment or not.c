#include <stdio.h>
int main()
{
    char input[100];
    fgets(input, 100, stdin);
    if (strlen(input) >= 2 && input[0] == '/' && input[1] == '/')
    {
        printf("This is a comment.\n");
    }
    else
    {
        printf("This is not a comment.\n");
    }
    return 0;
}
