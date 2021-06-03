#include <iostream>

class Node
{
public:
	int data;
	Node* next;
};

Node* head = nullptr; 
Node* tail = nullptr;

void AddNodeAtFront()
{
	Node *n = new Node;
	n->next = head;
	head = n;
}

void DeleteFrontNode()
{
	if (head == nullptr) return;

	Node* tmp = head->next;
	delete head;
	head = tmp;
}

int main()
{

	for (int i = 0; i < 20; i++)
	{
		AddNodeAtFront();
		head->data = i*3;
	}

	for (int i = 0; i < 10; i++)
	{
		DeleteFrontNode();
	}


	Node* i = head;
	while (i != nullptr)
	{
		std::cout << i->data << std::endl;
		i = i->next;
	}

	return 0;
}





