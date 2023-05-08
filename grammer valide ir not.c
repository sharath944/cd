#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given string is a valid grammar
int is_grammar(char *str) {
    int len = strlen(str);
    int i = 0;

    // Rule S -> AB
    if (str[0] == 'a') {
        i++;
        while (i < len && str[i] == 'a') {
            i++;
        }
        if (i < len && str[i] == 'b') {
            i++;
            while (i < len && str[i] == 'b') {
                i++;
            }
            // check if the remaining substring is empty
            if (i == len) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    if (is_grammar(str)) {
        printf("%s is a valid grammar.\n", str);
    } else {
        printf("%s is not a valid grammar.\n", str);
    }
    return 0;
}
