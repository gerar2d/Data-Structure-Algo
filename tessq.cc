#include <iostream>

#define MAX_SIZE 100

class Stack {
private:
    int top;
    int stackArray[MAX_SIZE];

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }
        stackArray[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow" << std::endl;
            return -1;
        }
        return stackArray[top--];
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return stackArray[top];
    }
};

void calculateSpan(int price[], int n, int span[]) {
    Stack stack;
    stack.push(0);
    span[0] = 1;

    for (int i = 1; i < n; i++) {
        while (!stack.isEmpty() && price[stack.peek()] <= price[i])
            stack.pop();

        span[i] = (stack.isEmpty()) ? (i + 1) : (i - stack.peek());
        stack.push(i);
    }
}

int main() {
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    int span[n];

    calculateSpan(price, n, span);

    std::cout << "Day\tPrice\tSpan" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << "\t" << price[i] << "\t" << span[i] << std::endl;
    }

    return 0;
}