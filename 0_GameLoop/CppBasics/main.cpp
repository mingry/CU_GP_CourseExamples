#include <iostream>
#include <string>
#include <vector>

class Monster {
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
		std::cout << "Monster: " << name << " at (" << pos_x << ", " << pos_y << ") health: " << health << std::endl;
	}
	
	void Attacked() {
		health -= 10;
		if (health <= 0) {
			health = 0;
		}
	}

	void Heal() {
		health += 10;
		if (health >= 100) {
			health = 100;
		}
	}

private:
	int pos_x;
	int pos_y;
	int health;
	std::string name;

};

void HealAllMonsters(std::vector<Monster>& ms) {
	for (auto& m : ms) {
		m.Heal();
	}
}

int main() {

	std::vector<Monster> monsters(3);

	monsters.push_back(Monster("Lee"));


	for (int i = 2; i < monsters.size(); i++) {
		monsters[i].Attacked();
		monsters[i].Attacked();
		monsters[i].Attacked();
		monsters[i].Attacked();
	}

	HealAllMonsters(monsters);


	for (auto &m : monsters) {
		m.Render();
	}

	return 0;
}