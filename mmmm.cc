#include <iostream>
#include <string>
#include <stdexcept>

class GameEntry {
public:
    GameEntry(const std::string& name = "", int score = 0) : playerName(name), playerScore(score) {}

    std::string getName() const {
        return playerName;
    }

    int getScore() const {
        return playerScore;
    }

private:
    std::string playerName;
    int playerScore;
};

class Scores {
public:
    Scores(int maxEnt = 10);
    ~Scores();
    void add(const GameEntry& e);
    GameEntry remove(int i);
    int getNumEntries() const;

private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores() {
    delete[] entries;
}

void Scores::add(const GameEntry& e) {
    if (numEntries < maxEntries) {
        entries[numEntries] = e;
        numEntries++;
        std::cout << "Added Entry: " << e.getName() << " - " << e.getScore() << std::endl;
    }
    else {
        std::cout << "Error: Score list is full. Unable to add entry." << std::endl;
    }
}

GameEntry Scores::remove(int i) {
    if (i < 0 || i >= numEntries) {
        throw std::out_of_range("Invalid index");
    }

    GameEntry removedEntry = entries[i];

    for (int j = i; j < numEntries - 1; j++) {
        entries[j] = entries[j + 1];
    }

    numEntries--;

    std::cout << "Removed Entry: " << removedEntry.getName() << " - " << removedEntry.getScore() << std::endl;

    return removedEntry;
}

int Scores::getNumEntries() const {
    return numEntries;
}

int main() {
    Scores highScores(5);

    highScores.add(GameEntry("Player1", 100));
    highScores.add(GameEntry("Player2", 200));
    highScores.add(GameEntry("Player3", 150));
    highScores.add(GameEntry("Player4", 180));
    highScores.add(GameEntry("Player5", 120));

    GameEntry removedEntry = highScores.remove(0);
    removedEntry = highScores.remove(2);
    removedEntry = highScores.remove(highScores.getNumEntries() - 1);

    highScores.add(GameEntry("Player6", 300));
    highScores.add(GameEntry("Player7", 250));
    highScores.add(GameEntry("Player8", 275));
    highScores.getNumEntries();
    return 0;
}