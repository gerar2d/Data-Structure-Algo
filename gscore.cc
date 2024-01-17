#include <iostream>
#include <string.h>
#include <stdexcept>
using namespace std;


class GameEntry{
    public:
    GameEntry(const string& n="", int s=0);
    string getName() const;
    int getScore() const;
    
    private:
    string name;
    int score;
};

class Scores {
    public:
    Scores(int maxEnt);
    ~Scores();
    void add(const GameEntry &e);
    GameEntry remove(int i);
      
    private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
 
};
GameEntry::GameEntry(const string &n, int s)
    : name(n), score(s){}

string GameEntry::getName() const { return name; }

int GameEntry::getScore() const { return score; }

// throw exception only worked with "out_of_range syntax"
GameEntry Scores::remove(int i) {
    if ((i < 0) || (i >= numEntries))
        { throw out_of_range("Invalid index"); }
    GameEntry e = entries[i];
    for (int j = i+1; j < numEntries; j++)
        { entries[j-1] = entries[j]; }
    numEntries--;
    cout<< "--- "<<e.getName()<<" | "<<e.getScore()<<endl;
    return e;
}

Scores::Scores(int maxEnt){
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

Scores::~Scores(){
    delete[] entries;
}

void Scores::add(const GameEntry& e){
   int newScore = e.getScore();
   if (numEntries == maxEntries){
    if (newScore <= entries[maxEntries-1].getScore())
        return;
   }
   else numEntries++;

   int i = numEntries-2;
   while (i >= 0 && newScore > entries[i].getScore()){
    entries[i+1] = entries[i];
    i--;
   }  
   entries[i+1] = e;
   cout<<"+++ "<<e.getName()<<" | "<<e.getScore()<<endl;   
}


int main(){
    // maxentry = 4
    Scores scr(4);
    GameEntry ge;
   
    scr.add(GameEntry("john", 500));
    scr.add(GameEntry("Jay", 200));
    scr.add(GameEntry("Rambo", 300));

    // inserted in the beginning
    scr.add(GameEntry("Ash", 100));
    // inserted in the end
    scr.add(GameEntry("Ray", 600));
    // jake wont be added
    scr.add(GameEntry("jake", 10));
    // inserted in the middle
    scr.add(GameEntry("Linda", 350));
    
    // a couple of entries removed
    ge = scr.remove(3);
    ge = scr.remove(2);
    
}