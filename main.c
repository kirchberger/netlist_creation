#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("file location is: %s\n",argv[1]);
	
	FILE *ptr_net;
	ptr_net = fopen(argv[1],"r");

	
	char buffer[255];
	while(fgets(buffer,255,ptr_net) != NULL){
		printf("%s\n", buffer);
	}
	
	fclose(ptr_net);
	printf("Finished \n");
	return 0;
}
