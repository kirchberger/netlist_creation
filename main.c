#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lexor (char* fileLoc){
	FILE *file;
	file = fopen(fileLoc,"r");

	char buff[100];
	char* token;
	while(fgets(buff,100,file) != NULL){
		//printf("line: %s", buff);
		token = strtok(buff," ");
		while(token != 0){
			if (*token != '\n'){
				printf("%s", token);
			}
			token = strtok(0," ");
		}
	}

	fclose(file);
}

int main(int argc, char* argv[]) {
	if (argc<2){
		printf("No file location\n");
		return 1;
	}

	if (argc>3){
		printf("Too many arguments\n");
		return 1;
	}
	printf("file location is: %s\n",argv[1]);
	
	lexor(argv[1]);
	/*
	char buffer[255];
	while(fgets(buffer,255,ptr_net) != NULL){
		// First Character
		char* piece = strtok(buffer," ");
		if (*piece != '\n'){
			switch (*piece[0]
		}

	}*/
	printf("Finished \n");
	return 0;
}


