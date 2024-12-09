#include <iostream>
#include <vector>
#include <algorithm>

struct Character {
    int health, attack, defense, agility;
};

bool compareByAgility(const Character &a, const Character &b) {
    return a.agility > b.agility;
}

int main() {
    int n;
    std::cin >> n;

    Character hero;
    std::cin >> hero.health >> hero.attack >> hero.defense >> hero.agility;

    std::vector<Character> enemies(n);
    for (int i = 0; i < n; i++) {
        std::cin >> enemies[i].health >> enemies[i].attack >> enemies[i].defense >> enemies[i].agility;
    }

    std::sort(enemies.begin(), enemies.end(), compareByAgility);

    long long totalDamage = 0;
    long long heroHealth = hero.health;

    for (int i = 0; i < n; i++) {
        long long damageTaken = std::max(enemies[i].attack - hero.defense, 0);
        totalDamage += damageTaken;
        heroHealth -= damageTaken;
        
        if (heroHealth <= 0) {
            std::cout << -1 << std::endl;
            return 0;
        }
    }

    std::cout << totalDamage << std::endl;

    return 0;
}