#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <struc.h>


void lexor (char* fileLoc){
	FILE *file;
	file = fopen(fileLoc,"r");

	char buff[100];
	char* token;
	//struct systemdata system = {0,0};
	int i = 0;
	while(fgets(buff,100,file) != NULL){
		i++;
		token = strtok(buff," \n");
		if (token != NULL){
			switch (token[0]){
				case 'r':
				//system->res++;
					printf("Resistor\n");
					break;
				case 'c':
				//system->caps++;
					printf("Capacitor\n");
					break;
				default:
					printf("Component on line %d not recognized\n",i);
			}
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

	printf("Finished \n");
	return 0;
}


