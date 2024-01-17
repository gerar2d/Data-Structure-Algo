#include <iostream>
using namespace std;
#define MAX_SIZE 100

class Stack{
    public:
        Stack();
        bool empty();
        bool full();
        void push(int value);
        int pop();
        int top();
    private:
        int front;
        int stackArr[MAX_SIZE];
};

Stack::Stack()
    { front = -1; }

bool Stack::empty(){
    return front == -1;
}

bool Stack::full(){
    return front == MAX_SIZE - 1;
}

void Stack::push(int value){
    if (full()){
        cout<<"stack is full."<<endl;
        return;
    }
    stackArr[++front] = value; 
}

int Stack::pop(){
    if (empty()){
        cout<<"stack is empty."<<endl;
        return -1;
    }
    return stackArr[front--];
}

int Stack::top(){
    if (empty()){
        cout<<"stack is empty."<<endl;
        return -1;
    }
    return stackArr[front];
}

void calculateSpan(double price[], int n, int s[]){
    Stack st;
    st.push(0);

    s[0] = 1;
    for (int i = 1; i < n; i++){
        while (!st.empty() && price[st.top()] <= price[i])
        {st.pop();}

        s[i] = (st.empty()) ? (i + 1) : (i - st.top());

        st.push(i);
    }
}

int main(){
    // AAPL Historical Data 10/12/2023 - 11/06/2023
    double price[] = {176.38, 174.24, 175.52, 171.00, 169.35, 169.02, 166.91,
    170.37, 171.88, 173.05, 170.91, 175.31, 176.04, 175.58, 176.65, 176.75,
    181.42, 180.07, 178.20, 178.10, 176.81}; 
    int size = 21; // sizeof(price)/sizeof(price[0])
    int span[size];
    calculateSpan(price,size,span);

    cout<<"Day\tPrice\t\tSpan"<<endl;
    for (int i = 0; i < size; i++) {
        cout<<i + 1<<"\t$"<<price[i]<<"\t\t"<<span[i]<<endl;
    }
}