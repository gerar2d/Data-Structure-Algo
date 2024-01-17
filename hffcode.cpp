#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX_TREE_HEIGHT 1000

int t_char = 0;

struct Node{
	char ch;
	int freq;
	struct Node *left, *right;
};

struct MinHeap{
	int cur_size;
	int capacity;
	struct Node **array;
};



struct Node *nwNode(char character, int frequency){
	struct Node *nwNode = (struct Node *)malloc(sizeof(struct Node));
	nwNode->ch = character;
	nwNode->freq = frequency;
	nwNode->left = nwNode->right = NULL;

	return nwNode;	
}


struct MinHeap *createMinHeap(int capacity){
	struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->cur_size = 0;	
	minHeap->capacity = capacity;
	minHeap->array = (struct Node **)malloc(sizeof(struct Node *)*capacity);

	return minHeap;
}




void swap(struct Node **a, struct Node **b){
	struct Node *tmp = *a;
	*a = *b;
	*b = tmp;
}


bool sizechk(struct MinHeap *minHeap){
	return (minHeap->cur_size == 1);
}


void minHeapify(struct MinHeap *minHeap, int ind){
	int smallest = ind, left = 2*ind+1, right = 2*ind+2;
	if(left < minHeap->cur_size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if(right < minHeap->cur_size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if(smallest != ind){
		swap(&minHeap->array[smallest], &minHeap->array[ind]);
		minHeapify(minHeap, smallest);
	}
}


struct Node *extractMin(struct MinHeap *minHeap){
	struct Node *min_node = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->cur_size-1];
	minHeap->cur_size--;
	minHeapify(minHeap, 0);

	return min_node;
}


void insert(struct MinHeap *minHeap, struct Node *nwNode){
	minHeap->cur_size++;
	int i = minHeap->cur_size-1;

	while(i && nwNode->freq < minHeap->array[(i-1)/2]->freq){
		minHeap->array[i] = minHeap->array[(i-1)/2];
		i = (i-1)/2;
	}
	minHeap->array[i] = nwNode;
}


 void buildMinHeap(struct MinHeap *minHeap){
 	int i;
 	for(i=minHeap->cur_size/2; i>=0; i--)
 		minHeapify(minHeap, i);
 }



struct MinHeap *createAndBuildMinHeap(char *characters, int *frequencies, int size){
	struct MinHeap *minHeap = createMinHeap(size);
	int i;
	for(i=0; i<size; i++)
		minHeap->array[i] = nwNode(characters[i], frequencies[i]);
	minHeap->cur_size = size;
	buildMinHeap(minHeap);

	return minHeap;
}


struct Node *bHuffTree(char *characters, int *frequencies, int size){
 	struct Node *left, *right, 	*top;
 	
 	struct MinHeap *minHeap = createAndBuildMinHeap(characters, frequencies, size);

 	
 	while(!sizechk(minHeap)){
 		
 		left = extractMin(minHeap);
 		right = extractMin(minHeap); 

 		if(left->ch > right->ch){
 			struct Node *tmp = left;
 			left = right;
 			right = tmp;
 		}

 		
       
        top = nwNode(right->ch, left->freq + right->freq);
        top->left = left;
        top->right = right;

        insert(minHeap, top);
 	}

 	
 	return extractMin(minHeap);
 }



bool isLeaf(struct Node *root){
	return !(root->left) && !(root->right);
}


void printSq(int *arr, int n){
	int i;
	for(i=0; i<n; i++)
		cout << arr[i];
	cout << endl;
	return;
}


 void printA(struct Node *root, int *arr, int top){
 	
 	if(root->left){
 		arr[top] = 0;
 		printA(root->left, arr, top+1);
 	}
 	 
 	if(root->right){
 		arr[top] = 1;
 		printA(root->right, arr, top+1);
 	}

 	
 	if(isLeaf(root)){
 		cout << root->ch << "  :  ";
 		printSq(arr, top);

 		t_char += (top*root->freq);	
 	}
 	return;
 }

 void HuffmanCodes(char *characters, int *frequencies, int size){
 	struct Node *root = bHuffTree(characters, frequencies, size); 	
 	int arr[MAX_TREE_HEIGHT], top=0;
 	cout << "\nChar  HuffmanCode" << endl;
 	cout << "----  -----------" << endl;
 	printA(root, arr, top);	
 }

int main(int argc, char const *argv[]){	
	string text;
	cout << "Enter the text string: " << endl;
	getline(cin, text);
	
	map<char, int> char_dict;
	map<char, int>::iterator itr;
	for(int i=0; i<text.length(); i++){
		itr = char_dict.find(text[i]);
		if(itr != char_dict.end()){
			(itr->second)++;
		}
		else{
			char_dict.insert(pair<char, int>(text[i], 1));
		}
	}
	int no_of_characters = char_dict.size();
	char characters[no_of_characters];
	int frequencies[no_of_characters];
	int ind = 0;
	for(map<char,int>::iterator it = char_dict.begin(); it != char_dict.end(); it++){
		characters[ind] = it->first;
		frequencies[ind++] = it->second;
	}

	HuffmanCodes(characters, frequencies, no_of_characters);
	cout << "\nTotal number of characters reqired for encoding: " << t_char << endl;
	
	return 0;
}