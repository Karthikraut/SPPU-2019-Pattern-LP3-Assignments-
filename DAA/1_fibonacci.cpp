#include<iostream>
using namespace std;
void fib_iter(int n){
    int a =0,b=1;
    int steps = 0;
    for(int i=0;i<n;i++){
        int c  = a+b;
        a = b;
        b =c;
        cout<<c<<" ";
        steps++;
    }
    cout<<"Iterative steps: "<<steps<<endl;
}
int steps =0;
int fib_recur(int n){
    steps++;
    if(n<=0) return 0;
    if(n==1) return 1;
    return fib_recur(n-1)+fib_recur(n-2);
}
int main(){
    fib_iter(5);
    fib_recur(5);
    cout<<"Recursive steps: "<<steps;
    
}