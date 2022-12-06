#include <stdio.h>
#include <stdlib.h>

void show_environment(void) {
	extern char **environ;
	char **env = environ;
	
	if (env == NULL) {
		printf("Список переменных окружения пуст\n");
	} else {
		printf("Список переменных окружения\n");
		while (*env) {
			printf("\t%s\n", *env);
			env++;
		}
		printf("Окончание списка\n");
		/* Второй вариант вывода списка */
		/*
		{
			int i;
			for (i = 0; environ[i] != NULL; i++)
				printf("\t%s\n", environ[i]);
		}*/
	}
	
}

int main(int argc, char **argv) {
	
	if (argc > 2) {
		fprintf(stderr, "Too many arguments\n");
		exit(EXIT_FAILURE);
	}
	
	show_environment();
	
	if (argc == 2) {
		printf("Deleting variable %s from environment\n", argv[1]);
		if (unsetenv(argv[1]) != 0) {
			fprintf(stderr, "Cannot unset %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	} else {
		printf("Deleting all environment\n");
		clearenv();
	}
	
	show_environment();
	
	return EXIT_SUCCESS;
}
