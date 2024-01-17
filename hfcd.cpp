#include <iostream>
#include <string>
#include <map>
using namespace std;

#define MAX_TREE_HEIGHT 999

int t_char = 0;

struct Node{
	char ch;
	int freq;
	struct Node *left, *right;
};

struct MinHeap{
	int cSize;
	int cap;
	struct Node **array;
};

struct Node *nwNode(char character, int frequency){
	struct Node *nwNode = (struct Node *)malloc(sizeof(struct Node));
	nwNode->ch = character;
	nwNode->freq = frequency;
	nwNode->left = nwNode->right = NULL;

	return nwNode;	
}

struct MinHeap *cMinHeap(int cap){
	struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
	minHeap->cSize = 0;	
	minHeap->cap = cap;
	minHeap->array = (struct Node **)malloc(sizeof(struct Node *)*cap);

	return minHeap;
}

void swap(struct Node **y, struct Node **b){
	struct Node *tmp = *y;
	*y = *b;
	*b = tmp;
}

bool sizechk(struct MinHeap *minHeap){
	return (minHeap->cSize == 1);
}

void minHeapify(struct MinHeap *minHeap, int d){
	int smallest = d, left = 2*d+1, right = 2*d+2;
	if(left < minHeap->cSize && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
		smallest = left;
	if(right < minHeap->cSize && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
		smallest = right;
	if(smallest != d){
		swap(&minHeap->array[smallest], &minHeap->array[d]);
		minHeapify(minHeap, smallest);
	}
}

struct Node *eMin(struct MinHeap *minHeap){
	struct Node *min_node = minHeap->array[0];
	minHeap->array[0] = minHeap->array[minHeap->cSize-1];
	minHeap->cSize--;
	minHeapify(minHeap, 0);

	return min_node;
}

void insert(struct MinHeap *minHeap, struct Node *nwNode){
	minHeap->cSize++;
	int i = minHeap->cSize -1;

	while(i && nwNode->freq < minHeap->array[(i-1)/2]->freq){
		minHeap->array[i] = minHeap->array[(i-1)/2];
		i = (i-1)/2;
	}
	minHeap->array[i] = nwNode;
}

void bMinHeap(struct MinHeap *minHeap){
 	int i;
 	for(i=minHeap->cSize/2; i >= 0; i--)
 		minHeapify(minHeap, i);
}

struct MinHeap *cNb_minheap(char *characters, int *frequencies, int size){
	struct MinHeap *minHeap = cMinHeap(size);
	int i;
	for(i=0; i < size; i++)
		minHeap->array[i] = nwNode(characters[i], frequencies[i]);
	minHeap->cSize = size;
	bMinHeap(minHeap);

	return minHeap;
}

struct Node *bHuffTree(char *characters, int *frequencies, int size){
 	struct Node *left, *right, 	*top;
 	struct MinHeap *minHeap = cNb_minheap(characters, frequencies, size);

 	while(!sizechk(minHeap)){
 		left = eMin(minHeap);
 		right = eMin(minHeap); 

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
 	return eMin(minHeap);
 }

bool leafChk(struct Node *root){
	return !(root->left) && !(root->right);
}

void printSq(int *arr, int n){
	for(int i = 0; i < n; i++)
		cout<<arr[i];
	cout<<endl;
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
 	if(leafChk(root)){
 		cout<<root->ch<<"  :  ";
 		printSq(arr, top);
 		t_char += (top*root->freq);	
 	}
 	return;
}

void hffMCall(char *characters, int *frequencies, int size){
 	struct Node *root = bHuffTree(characters, frequencies, size); 	
 	int arr[MAX_TREE_HEIGHT], top = 0;
 	cout<<"\nChar  HuffmanCode"<<endl;
 	cout<<"----  -----------"<<endl;
 	printA(root, arr, top);	
}

int main(int argc, char const *argv[]){	
	string text;
	cout<<"Enter the text string: "<<endl;
	getline(cin, text);
	
	map<char, int> charD;
	map<char, int>::iterator itr;
	for(int i = 0; i < text.length(); i++){
		itr = charD.find(text[i]);
		if(itr != charD.end()){
			(itr->second)++;
		}
		else{
			charD.insert(pair<char, int>(text[i], 1));
		}
	}
	int nChar = charD.size();
	char chars[nChar];
	int freqs[nChar];
	int d = 0;
	for(map<char,int>::iterator it = charD.begin(); it != charD.end(); it++){
		chars[d] = it->first;
		freqs[d++] = it->second;
	}
	hffMCall(chars, freqs, nChar);
    cout<<endl;
	return 0;
}