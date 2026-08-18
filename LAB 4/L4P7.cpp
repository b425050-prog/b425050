#include <iostream>
#include <string>
using namespace std;

class GameManager;

class Player {
private:
    string playerName;
    int health;
    int score;
    int level;

public:
    Player(string name, int playerHealth, int playerScore, int playerLevel) {
        playerName = name;
        health = playerHealth;
        score = playerScore;
        level = playerLevel;
    }

    friend class GameManager;
};

class GameManager {
public:
    void displayPlayerDetails(const Player &player) {
        cout << "\n--- Player Details ---\n";
        cout << "Player Name : " << player.playerName << '\n';
        cout << "Health      : " << player.health << '\n';
        cout << "Score       : " << player.score << '\n';
        cout << "Level       : " << player.level << '\n';
    }

    void checkAlive(const Player &player) {
        if (player.health > 0)
            cout << "Player Status: Alive\n";
        else
            cout << "Player Status: Not Alive\n";
    }

    void displayLevelAndScore(const Player &player) {
        cout << "Current Level: " << player.level << '\n';
        cout << "Current Score: " << player.score << '\n';
    }
};

int main() {
    string playerName;
    int health, score, level;

    cout << "Enter player name: ";
    getline(cin, playerName);

    cout << "Enter health: ";
    cin >> health;

    cout << "Enter score: ";
    cin >> score;

    cout << "Enter level: ";
    cin >> level;

    Player player(playerName, health, score, level);
    GameManager manager;

    manager.displayPlayerDetails(player);
    manager.checkAlive(player);
    manager.displayLevelAndScore(player);

    return 0;
}
