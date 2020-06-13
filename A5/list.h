#ifndef NODEH
#define NODEH
struct NODE{
	int data;
	struct NODE *next;
};

void newList();
int addNode(int value);
void prettyPrint();

#endif

