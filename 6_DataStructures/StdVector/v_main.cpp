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
	std::vector<int> vec(5);

	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = i * 30;
	}

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}

	for (auto v : vec)
	{
		std::cout << v << std::endl;
	}

	std::cout << "add one more data" << std::endl;
	vec.push_back(6 * 30);

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}


	std::cout << "remove one data" << std::endl;
	vec.pop_back();

	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
	}

	std::cout << "resize" << std::endl;
	vec.resize(2);
	for (int i = 0; i < vec.size(); i++)
	{
		std::cout << i << ": " << vec[i] << std::endl;
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