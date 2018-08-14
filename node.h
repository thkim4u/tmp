#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	explicit Node(char data);
	char GetData();
	Node* InsertPreviousNode(char data);
	Node* InsertNextNode(char data);
	Node* GetPreviousNode();
	Node* GetNextNode();
	bool ErasePreviousNode();
	bool EraseNextNode();

	// Add My Code
private:
	Node* prev;
	Node* next;
	char data;
};

#endif  // NODE_H_
