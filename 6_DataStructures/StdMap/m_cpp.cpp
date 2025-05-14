#include <iostream>
#include <map>
#include <string>

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
	std::map<std::string, Pos> positions;

	/*std::string s = "john";
	Pos john_pos = { 10, 20 };

	positions[s] = john_pos;*/

	positions["john"] = Pos(10, 20);
	positions["make"] = Pos(20, 30);
	positions["sam"] = Pos(300, 20);
	positions["jane"] = Pos(10, 10);
	positions["choi"] = Pos(20, 20);


	/*std::cout << positions["john"].x << " " << positions["john"].y << std::endl;
	std::cout << positions["make"].x << " " << positions["make"].y << std::endl;
	std::cout << positions["sam"].x << " " << positions["sam"].y << std::endl;
	std::cout << positions["jane"].x << " " << positions["jane"].y << std::endl;
	std::cout << positions["choi"].x << " " << positions["choi"].y << std::endl;*/

	for (auto v : positions)
	{
		std::cout << v.first << ": " << v.second.x << " " << v.second.y << std::endl;
	}
	

	return 0;
}