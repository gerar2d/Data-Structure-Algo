#include <iostream>

using namespace std;

unsigned long fib(int n){
    if (n < 2) return n;
    int fib[n+1], i;
    fib[0] = 0;
    fib[1] = 1;

    for (i = 2; i <= n; i++) 
        { fib[i] = fib[i-1] + fib[i-2]; }
    return fib[n];
}

int main(){
    int x=6;
    cout<<"Fib("<<x<<") is "<<fib(x)<<endl;
}