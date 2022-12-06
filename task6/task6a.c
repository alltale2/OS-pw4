#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	char *var, *value;
	
	if (argc == 1 || argc > 3) {
		fprintf(stderr, "usage: envir1 var [value]\n");
		exit(1);
	}
	
	var = argv[1];
	value = getenv(var);
	if (value) 
		printf("Переменная %s имеет значение %s\n", var, value);
	else
		printf("Переменная %s не имеет значения\n", var);
		
	if (argc == 3) {
		char *string;
		value = argv[2];
		string = malloc(strlen(var)+strlen(value)+2);
		if (!string) {
			fprintf(stderr, "out of memory\n");
			exit(1);
		}
		strcpy(string, var);
		strcat(string, "=");
		strcat(string, value);
		printf("Calling putenv with: %s\n", string);
		if (putenv(string) != 0) {
			fprintf(stderr, "putenv failed\n");
			free(string);
			exit(1);
		}
		
		value = getenv(var);
		if (value)
			printf("Новое значение %s равно %s\n", var, value);
		else
			printf("Новое значение %s равно null?", var);
	}
	
	return EXIT_SUCCESS;
}
