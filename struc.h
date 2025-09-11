


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
  int resistors;
  int capacitors;
  resistor* resRoot;
  capacitor* capRoot;
  node* nodeRoot;
}circuit;
