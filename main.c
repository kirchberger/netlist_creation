#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	printf("file location is: %s\n",argv[1]);
	
	FILE *ptr_net;
	ptr_net = fopen(argv[1],"r");

	
	char buffer[255];
	while(fgets(buffer,255,ptr_net) != NULL){
		char* piece = strtok(buffer," ");
		if (piece != "\n"){
			printf("%s", strlen(piece));
		}
	}
	
	fclose(ptr_net);
	printf("Finished \n");
	return 0;
}


