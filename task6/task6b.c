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
		printf("Calling setenv with: variable %s, value %s\n", 
			var, argv[2]);
		if (setenv(var, argv[2], 1) != 0) {
			fprintf(stderr, "setenv failed\n");
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
