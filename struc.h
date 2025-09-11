
// System and component structures and methods accociated

typedef struct resistor{
  int node1;
  int node2;
  struct resistor* next;
  char identifier[];
} resistor;

typedef struct capacitor{
  int node1;
  int node2;
  struct capacitor* next;
  char identifier[];
} capacitor;

typedef struct node{
  struct node* next;
  char identifier[];
} node;

typedef struct circuit{
  uint resistors;
  uint capacitors;
  resistor* resRoot;
  capacitor* capRoot;
  resistor* resEnd;
  capacitor* capEnd;
  node* nodeRoot;
}circuit;

int addComponent(circuit* netlist, char* token[],int componentType){
  printf("Resistors: %d, %d\n", netlist->resistors, netlist);
  return 0;
}

int memoryDealocate(){

}
