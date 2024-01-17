#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class List;

class ListNode{
    public:
        ListNode(int);
        int getData();
        friend class List;
    private:
        int data;
        ListNode* next;
};

ListNode::ListNode(int dataIn)
    { data = dataIn; next = 0; }

int ListNode::getData()
    { return data; }

class List{
    public:
        List();
        ~List();
        void insertNewNode(int);
        void print();
        ListNode* search(int);
        bool isEmpty();
        void insertBegin(int);
        void insertEnd(int);
    private:
        ListNode* start;
        ListNode* end;
};
List::List()
    : start(NULL), end(NULL) {}

List::~List(){
    if (!isEmpty()){
        ListNode* current = start;
        ListNode* temp;
        while (current != 0){
            temp = current;
            current = current->next;
            delete temp;
        }
    }
}

bool List::isEmpty(){
    if (start == NULL && end == NULL) return 1;
    else return 0;
}

void List::insertBegin(int dataIn){
    if (isEmpty()){
        ListNode* newP = new ListNode(dataIn);
        start = newP;
        end = newP;
    }else{
        ListNode* newP = new ListNode(dataIn);
        newP->next = start;
        start = newP;
    }
}

void List::insertEnd(int dataIn){
    if (isEmpty()){
        ListNode* newP = new ListNode(dataIn);
        start = newP;
        end = newP;
    }else{
        ListNode* newP = new ListNode(dataIn);
        end->next = newP;
        end = newP;
    }
}

void List::insertNewNode(int dataIn){
    if (isEmpty()) insertBegin(dataIn);
    else{
    if (dataIn < start->data) insertBegin(dataIn);
    else if (dataIn >= end->data) insertEnd(dataIn);
    else{
        ListNode* current = start;
        ListNode* newP = new ListNode(dataIn);
        while (current != end){
            if ((newP->data < current->next->data) && (newP-> data >= current->data)){
                ListNode* next = current->next;
                current->next = newP;
                newP->next = next;
                break;
            }
            current = current->next;
        }
    }
    }

}

void List::print(){
    if (isEmpty()){
        cout<<"The list is empty"<<endl;
    }else{
        ListNode* current = start;
        cout<<"The contents of the list is: ";
        while (current != NULL){
            cout<<current->data<<' ';
            current = current->next;
        }
        cout<<endl;
    }
}

ListNode* List::search(int key){
    ListNode* node;
    bool found = false;
    node = start;

    while ((!found) && (node != NULL)){
        if (node->data == key) found = true;
        else node = node->next;
    }
    return node;
}

class TreeNode{
    public:
        TreeNode(int);
        int getData();
        friend class Tree;
    private:
        int data;
        TreeNode* left;
        TreeNode* right;
};

TreeNode::TreeNode(int DataIn){
    data = DataIn;
    left = 0;
    right = 0;
}

int TreeNode::getData(){
    return data;
}

class Tree {
    public:
        Tree();
        void insertNewNode(int);
        void preOrderPrint();
        void inOrderPrint();
        void postOrderPrint();
        TreeNode* search(int);
    private:
        TreeNode *root;
        bool isEmpty();
        void insertNewNodeUtility(TreeNode**, int);
        void preOrderPrintUtility(TreeNode*);
        void inOrderPrintUtility(TreeNode*);
        void postOrderPrintUtility(TreeNode*);
        TreeNode* searchUtility(TreeNode*, int);
};

Tree::Tree(){
    root = 0;
}

void Tree::insertNewNode(int dataIn){
    insertNewNodeUtility(&root, dataIn);
}

void Tree::insertNewNodeUtility(TreeNode** temp, int dataIn){
    if (*temp == 0) *temp = new TreeNode(dataIn);
    else{
        if (dataIn < (*temp)->data) insertNewNodeUtility(&((*temp)->left), dataIn);
        else{
            if (dataIn > (*temp)->data) insertNewNodeUtility(&((*temp)->right), dataIn);
            else cout<<dataIn<<" is a duplicate value "<<endl;
        }
    }
}

void Tree::preOrderPrint(){
    preOrderPrintUtility(root);
}

void Tree::preOrderPrintUtility(TreeNode* temp){
    if (temp != 0){
        cout<<temp->data<<' ';
        preOrderPrintUtility(temp->left);
        preOrderPrintUtility(temp->right);
    }
}

void Tree::inOrderPrint(){
    inOrderPrintUtility(root);
}

void Tree::inOrderPrintUtility(TreeNode* temp){
    if(temp != 0){
        inOrderPrintUtility(temp->left);
        cout<<temp->data<<' ';
        inOrderPrintUtility(temp->right);
    }
}

void Tree::postOrderPrintUtility(TreeNode* temp){
    if (temp != 0){
        postOrderPrintUtility(temp->left);
        postOrderPrintUtility(temp->right);
        cout<<temp->data<<' ';
    }
}

TreeNode* Tree::search(int key){
    return searchUtility(root,key);
}

TreeNode* Tree::searchUtility(TreeNode* leaf, int key){
    if (leaf != NULL){
        if (key == leaf->data) return leaf;
        if (key < leaf->data) return searchUtility(leaf->left, key);
        else return searchUtility(leaf->right, key);
    }
    else return NULL;
}

int main(){
    int choice = 0;
    const int size = 10;
    int arr[size];
    srand(time(0));
    for (int i = 0; i < size; i++){
        arr[i] = rand() %101;
    }
    List aList;
    for (int i = 0; i < size; i++){
        aList.insertNewNode(arr[i]);
    }
    Tree aTree;
    for (int i = 0; i < size; i++){
        aTree.insertNewNode(arr[i]);
    }

	while (choice != 7)
	{
		//displays initial array of values
		cout << "Initial Array of Values" << endl;
		cout << "-----------------------" << endl;
		for(int i = 0; i <= size-1;  i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl << endl;

		//menu of options to perform 
		cout << "Linked Lists and Trees" << endl;
		cout << "-----------------------" << endl;
		cout << "1. Print Linked List" << endl;
		cout << "2. Search For Entry In Linked List" << endl;
		cout << "3. Print Pre-Ordered Traverseal of Tree" << endl;
		cout << "4. Print In-Order Traversal of Tree" << endl;
		cout << "5. Print Post-Order Traversal of Tree" << endl;
		cout << "6. Search For Entry In Tree" << endl;
		cout << "7. EXIT" << endl;
		cout << "Enter Choice: ";
		cin >> choice;
		system("cls");

		int key; //search key used for both the search of linked list and binary tree
		
		ListNode* posList; //node pointer used to store a pointer to node returned from the linked list search function

		TreeNode* posTree; //node pointer used to store a pointer to node returned from the binary tree search function

		switch(choice)
		{
		case 1:
			cout << "Output of a Sorted Linked List" << endl;
			cout << "------------------------------" << endl;
			aList.print(); //prints contents of linked list
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "Searching In a Linked List" << endl;
			cout << "--------------------------" << endl;
			//prompt for search key
			cout << "Enter a a search key: ";
			cin >> key;
			posList = aList.search(key); //stores pointer to list node object
			cout << "The value of pointer is " << posList << endl;
			if(posList != NULL) //if not null then the value was found
				cout << "The value stored at this posistion is " << posList->getData() << endl;
			else
				cout << "The pointer to this position is NULL so there can be no value stored" << endl;
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "Pre-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			aTree.preOrderPrint(); //print pre ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "In-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			aTree.inOrderPrint(); //print in ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			cout << "Post-Ordered Traverseal of Tree" << endl;
			cout << "------------------------------" << endl;
			aTree.postOrderPrint(); //print post ordered traversal of binary tree
			cout << endl;
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "Searching In a Tree" << endl;
			cout << "-------------------" << endl;
			//prompt for search key
			cout << "Enter a a search key: ";
			cin >> key;
			posTree = aTree.search(key); //stores pointer to tree node object
			cout << "The value of pointer is " << posTree << endl;
			if(posTree != NULL) //if not null then the value was found
				cout << "The value stored at this posistion is " << posTree->getData() << endl;
			else
				cout << "The pointer to this position is NULL so there can be no value stored" << endl;
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "Thanks for using my test program for Linked Lists and Trees" << endl;
			system("pause");
			system("cls");

		}
	}
}