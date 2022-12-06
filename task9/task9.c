#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char computer[256];
	struct utsname uts;
	
	if (gethostname(computer, 255) != 0 || uname(&uts) < 0) {
		fprintf(stderr, "Colud not get host information\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Computer host name is %s\n", computer);
	printf("System is %s on %s hardware\n", 
							uts.sysname, uts.machine);
	printf("Nodename is %s\n", uts.nodename);
	printf("Version is %s, %s\n", 
							uts.release, uts.version);
							
	printf("\nInique computer id: %ld\n", gethostid());
	
	return EXIT_SUCCESS;
}
