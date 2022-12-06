#include <stdio.h>
#include <stdlib.h>

int main(void) {

    extern char **environ;
    
    /*{
       int i;
       if (environ) {
           printf("Environment variable list start\n");
           for (i = 0; environ[i]; i++)
               printf("\t%s\n", environ[i]);
           printf("Environment variable list end\n");
       } else {
           printf("Environment variable list is empty\n");
       }
    }*/
    {
        char **env = environ;
        if (env) {
            printf("Environment variable list start\n");
            while(*env) {
                printf("\t%s\n", *env);
                env++;
            }
            printf("Environment variable list end\n");
        } else {
            printf("Environment variablr list is empty\n");
        }
    }

    return EXIT_SUCCESS;
}
