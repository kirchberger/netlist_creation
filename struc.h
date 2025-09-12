
// System and component structures and methods accociated

typedef struct component{
  int node1;
  int node2;
  double value;
  struct component* next;
  char id[];
} component;

typedef struct node{
  struct node* next;
  char id[];
} node;

typedef struct circuit{
  int comps[2];
  int nodes;
  component* cRoot[2];
  component* cEnd[2];
  node* nRoot;
  node* nEnd;
}circuit;

int addComponent(circuit* netlist, char* token[],int type){
  component* current;

  // Add component
  if (netlist->comps[type] == 0){
    netlist->cRoot[type] = malloc(sizeof(component)+strlen(token[0])+1); // 4+4+8+8+ char size
    netlist->cEnd[type] = netlist->cRoot[type];
    current = netlist->cRoot[type];
    netlist->comps[type]++;
  } 
  else{
    current = netlist->cRoot[type];
    do{
      if(!strcmp(current->id,token[0])){
	printf("Duplicate component identifiers\n");
	return 1;
      }
      if(current->next != NULL){
	current = current->next;
      }
    }while(current->next != NULL);
    current->next = malloc(sizeof(component)+strlen(token[0])+1);
    current = current->next;
    netlist->comps[type]++;
  }
  strcpy(current->id,token[0]);

  // Validate value
 


  // Add Component

  
  return 0;
}

int memoryDeallocate(circuit* netlist){
  
  component* current;
  component* temp;
  for (int i = 0;i<2;i++){
    if (netlist->comps[i] != 0){
      current = netlist->cRoot[i];
      while (current->next !=NULL){
	temp = current->next;
	free(current);
	current = temp;
      }
      free(current);
    }
  }
}
