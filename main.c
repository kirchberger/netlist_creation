#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struc.h"


int lexor (char* fileLoc, circuit* netlist){
  FILE *file;
  file = fopen(fileLoc,"r");

  char buff[100];
  char *token[4]; // may need to change in future this might be better as a linked structure for potentially long lines.
  int componentType;
  int arguments;
  int arg;
  //struct systemdata system = {0,0};
  int line = 0;
  while(fgets(buff,100,file) != NULL){
    line++;
    token[0] = strtok(buff," \n");
    if (token[0] != NULL){
      switch (token[0][0]){
	case 'r': // Resistor
	  componentType = 0;
	  arguments = 4;
	  break;
	case 'c': // Capacitor
	  componentType = 1;
	  arguments = 4;
	  break;
	default: // Unknown
	  printf("Component on line %d not recognized\n",line);
	  // Memory deallocate
	  fclose(file);
	  return 1;
      }
      
      arg = 1;
      while(arg < arguments){ // Grabs all arguments
	token[arg] = strtok(NULL, " \n");
	if (token[arg] == NULL){ // Checks for too few arguments
	  printf("Too few arguments on line %d\n",line);
	  // Memory deallocate
	  fclose(file);
	  return 1;
	}
	arg++;
      }

      if (strtok(NULL, " \n")){ // Checks for too many arguments
        printf("Too many arguments on line %d\n",line);
	// Memory deallocate
	fclose(file);
	return 1;
      }

      if (addComponent(netlist, token, componentType)){
	fclose(file);
	return 1;
      }
    }
  }
  fclose(file);
  return 0;
}

int main(int argc, char* argv[]) {

  if (argc<2){ // Check conditions
    printf("No file location\n");
    return 1;
  }
  if (argc>3){
    printf("Too many arguments\n");
    return 1;
  }

  circuit* netlist = malloc(sizeof(circuit)); // Allocate systen structure

  // Run lexor to get all components
  if (lexor(argv[1],netlist)){
    free(netlist);
    return 1;
  }
  // Build system
  free(netlist);
  printf("Finished \n");
  return 0;
}


