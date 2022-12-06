#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error!!! Correct program usage: task5 OPTION_NAME\n");
    } else {
        char *value, *res;
        res = getenv(argv[1]);
        value = malloc(strlen(res)+1);
        strcpy(value, res);
        if (value) {
            printf("Variable %s possesses the value: %s\n", argv[1], value);
        } else {
            printf("Variable %s doesn't has the value\n", argv[1]);
        }
    }
    return EXIT_SUCCESS;
}
