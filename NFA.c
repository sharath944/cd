#include <stdio.h>
#include <stdbool.h>
bool dfa_accept(char* input)
{
    int state = 0;
    for (int i = 0; input[i] != '\0'; i++) 
	{
        switch (state)
		{
            case 0:
                if (input[i] == 'a')
				{
                    state = 1;
                } else {
                    return false;
                }
                break;
            case 1:
                if (input[i] == 'b') {
                    state = 2;
                } else {
                    return false;
                }
                break;
            case 2:
                if (input[i] == 'b')
				{
                    state = 2;
                } else if (input[i] == 'c')
				{
                    state = 3;
                } else
				{
                    return false;
                }
                break;
            case 3:
                return false;
        }
    }
    return state == 2 || state == 3;
}
bool nfa_accept(char* input)
{
    int state[3] = {0};
    for (int i = 0; input[i] != '\0'; i++)
	{
        switch (input[i])
		{
            case 'a':
                state[0] = 1;
                break;
            case 'b':
                state[1] = 1;
                break;
            case 'c':
                state[2] = 1;
                break;
        }
    }
    return state[0] && state[1] && (state[2] || !input[0]);
}
int main()
{
    char input[100];
    printf("Enter input: ");
    scanf("%s", input);
    printf("DFA: %s\n", dfa_accept(input) ? "Accepted" : "Rejected");
    printf("NFA: %s\n", nfa_accept(input) ? "Accepted" : "Rejected");
    return 0;
}
