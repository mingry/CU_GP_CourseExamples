#include <iostream>
#include <vector>


class Pos
{
public:
	Pos()
	{
		x = 0;
		y = 0;
	}

	Pos(int _x, int _y) 
	{
		x = _x;
		y = _y;
	}

	int x;
	int y;
};

int main()
{
	std::vector<int> v(5);

	for (int i = 0; i < v.size(); i++)
	{
		v[i] = i * 30;
	}

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << i << ": " << v[i] << std::endl;
	}

	std::cout << "add one more data" << std::endl;
	v.push_back(6 * 30);

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << i << ": " << v[i] << std::endl;
	}


	std::cout << "remove one data" << std::endl;
	v.pop_back();

	for (int i = 0; i < v.size(); i++)
	{
		std::cout << i << ": " << v[i] << std::endl;
	}

	std::cout << "resize" << std::endl;
	v.resize(2);
	for (int i = 0; i < v.size(); i++)
	{
		std::cout << i << ": " << v[i] << std::endl;
	}


	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	

	std::vector<Pos> positions;

	Pos p;
	p.x = 1;
	p.y = 2;
	positions.push_back(p);

	std::cout << "positions";
	std::cout << std::endl;
	for (int i = 0; i < positions.size(); i++)
	{
		std::cout << i << ": " << positions[i].x << " " << positions[i].y << std::endl;
	}

	std::cout << "Add many positions" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		positions.push_back({ i * 10, i * 20 });
	}
	for (int i = 0; i < positions.size(); i++)
	{
		std::cout << i << ": " << positions[i].x << " " << positions[i].y << std::endl;
	}

	return 0;
}