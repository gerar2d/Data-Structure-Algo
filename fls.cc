#include <iostream>
using namespace std;

template <typename E> 
class Position { 
    public:
        E& operator*();
        Position parent() const; 
        PositionList children() const; 
        bool isRoot() const;
        bool isExternal() const;
};

template <typename E> 
class Tree {
    public:
        class Position;
        class PositionList; public:
        int size() const;
        bool empty() const;
        Position root() const; 
        PositionList positions() const;
};