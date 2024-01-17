#include <iostream>
#include <vector>
using namespace std;

class VectorCompleteTree{
    public:
        VectorCompleteTree() {}
        void create(vector<int>& arr, int n, int i);
        void maxheapsort(vector<int>& arr, int n);
};

void VectorCompleteTree::create(vector<int>& arr, int n, int i){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    if(leftChild < n && arr[leftChild] < arr[largest]){
        largest = leftChild;
    }
    
    if(rightChild < n && arr[rightChild] < arr[largest]){
        largest = rightChild;
    }
  
    if(largest != i){
        swap(arr[i], arr[largest]);
        create(arr, n, largest);
    }
}
void VectorCompleteTree::maxheapsort(vector<int>& arr, int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        create(arr, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(arr[0], arr[i]);
        create(arr, i, 0);
    }
}

int main(){
    VectorCompleteTree vt;
    srand(1);
    vector<int> arr;
    int size = 20;
    for (int i = 0; i < 20; i++){
        int element = 1 + (rand() % 100);
        arr.push_back(element);
    }
    cout<<"Original---"<<endl;
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
    
    vt.maxheapsort(arr,size);
    cout<<"Sorted--- maxheap."<<endl;
    for(int i = 0; i < size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}