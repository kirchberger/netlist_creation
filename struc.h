


typedef struct resistor{
	int identifier;
	int node1;
	int node2;
	struct resistor* next;
} resistor;

typedef struct capacitor{
	int identifier;
	int node1;
	int node2;
	struct capacitor* next;
} capacitor;

typedef struct node{
	char[];
	struct node* next;
} node;

typedef struct circuit{
	int resistors;
	int capacitors;
	resistor* resRoot;
	capacitor* capRoot;
	node* nodeRoot;
}circuit;
