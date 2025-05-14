#include <iostream>
#include <list>

class Node
{
public:
	Node()
	{
		x = 0;
		y = 0;
	}

	Node(int x_, int y_)
	{
		x = x_;
		y = y_;
	}

	int x;
	int y;
};

int main()
{
	std::list<Node> L;

	L.push_front(Node(1, 2));
	L.push_front(Node(3, 4));
	L.push_front(Node(5, 6));
	L.push_front(Node(7, 8));
	L.push_front(Node(9, 10));

	L.push_back(Node(70, 80));
	L.push_back(Node(90, 100));

	std::cout << "front of L : " << L.front().x << ", " << L.front().y << std::endl;
	std::cout << "back of L : " << L.back().x << ", " << L.back().y << std::endl;


	for (auto v : L)
	{
		std::cout << v.x << ", " << v.y << std::endl;
	}

	std::cout << "size of L : " << L.size() << std::endl;

	

	// wrong update
	std::cout << std::endl;
	std::cout << "wrong way to update" << std::endl;
	for (auto v : L)
	{
		v.x *= 10;
	}

	for (auto v : L)
	{
		std::cout << v.x << ", " << v.y << std::endl;
	}

	// correct update
	std::cout << std::endl;
	std::cout << "correct way to update" << std::endl;
	for (auto& v : L)
	{
		v.x *= 10;
	}

	for (auto v : L)
	{
		std::cout << v.x << ", " << v.y << std::endl;
	}



	return 0;
}