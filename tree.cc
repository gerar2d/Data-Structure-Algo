#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

typedef int Elem;
struct Node{
    Elem elt;
    Node* parent;
    Node* left;
    Node* right;
    Node() : elt(), parent(NULL), right(NULL), left(NULL) {}
};

class Position{
    public:
        Position(Node* _v = NULL);
        Elem& operator* ();
        Position left() const;
        Position right() const;
        Position parent() const;
        bool isRoot() const;
        bool isExternal() const;
        friend class LinkedBinaryTree;
    private:
        Node* v;
};

Position::Position(Node* _v = NULL)  
    : v(_v) {}

Elem& Position::operator* ()
    { return v->elt; }

Position Position::left() const
    { return Position(v->left); }

Position Position::right() const
    { return Position(v->right); }

Position Position::parent() const
    { return Position(v->parent); }

bool Position::isRoot() const
    { return v->parent == NULL && v->right == NULL; }

bool Position::isExternal() const
    { return v->left == NULL && v->right == NULL; }

typedef list<Position> PositionList;

class LinkedBinaryTree{
    protected:
        Node nn;
    public:
        Position pos;
    public:
        LinkedBinaryTree();
        int size() const;
        bool empty() const;
        Position root() const;
        PositionList position() const;
        void addRoot();
        void isRoot();
        void expandExternal(const Position& p);
    protected:
        void preorder(Node* v, PositionList& pl) const;
    private:
        Node* _root;
        int n;
};

LinkedBinaryTree::LinkedBinaryTree()
    : _root(NULL), n(0) {}

int LinkedBinaryTree::size() const
    { return n; }

bool LinkedBinaryTree::empty() const
    { return size() == 0; }

Position LinkedBinaryTree::root() const
    { return Position(_root); }

void LinkedBinaryTree::addRoot()
    { _root = new Node; n = 1; }

int main(){
    LinkedBinaryTree lbt;
    
}