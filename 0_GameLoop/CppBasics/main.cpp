#include <iostream>
#include <string>
#include <vector>


class Monster {

private:
	int pos_x, pos_y;
	int health;
	std::string name;

public:
	Monster() {
		pos_x = rand() % 100;
		pos_y = rand() % 100;
		health = 100;
		name = "noname";
	}

	Monster(std::string name) {
		pos_x = rand() % 100;
		pos_y = rand() % 100;
		health = 100;
		this->name = name;
	}

	void Render() {
		std::cout << name << " at: (" << pos_x << ", " << pos_y << "), ";
		std::cout << " Health: " << health << std::endl;
	}

	void Attacked(int damage) {
		health -= damage;
		if (health <= 0) {
			std::cout << name << " is dead!" << std::endl;
		}
		else {
			std::cout << name << "'s Health is now: " << health << std::endl;
		}
	}	

	void Heal(int amount) {
		health += amount;
		std::cout << name << "'s Health is now: " << health << std::endl;
	}

	


};

void HealAllMonsters(std::vector<Monster>& monsters, int amount) {
	for (Monster& m : monsters) {
		m.Heal(amount);
	}
}

int main() {

	std::cout << "Hello Monsters!" << std::endl;

	Monster monster1;
	Monster monster2("Peter");
	Monster monster3("Linda");

	monster1.Render();
	monster2.Render();
	monster3.Render();


	std::cout << std::endl << std::endl << "Assigning monster2 to monster2_1 (copy)" << std::endl;

	Monster monster2_1 = monster2;
	monster2_1.Attacked(20);

	monster2_1.Render();
	monster2.Render();


	std::cout << std::endl << std::endl << "Referencing monster2 by monster2_2" << std::endl;

	Monster &monster2_2 = monster2;
	monster2_2.Attacked(20);

	monster2_2.Render();
	monster2.Render();


	std::cout << std::endl << std::endl <<  "Using Vector" << std::endl;

	std::vector<Monster> monstors;

	monstors.push_back(Monster("James"));
	monstors.push_back(Monster("Choi"));
	monstors.push_back(Monster("Ella"));

	for (int i = 0; i < monstors.size(); i++) {
		monstors[i].Render();
	}

	/*for (Monster& m : monstors) {
		m.Render();
	}*/


	std::cout << std::endl << std::endl << "Rendering all monsters after healing" << std::endl;

	HealAllMonsters(monstors, 10);

	for (Monster& m : monstors) {
		m.Render();
	}
		

	return 0;
}