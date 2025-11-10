#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct Item{
    int wgt;
    int value;
};

struct cmp{
  bool operator()(Item a, Item b){
      return (double) (a.value/a.wgt) > (double)(b.value/b.wgt);
  }  
};

double fractionalKnapsack(int W, vector<Item> items,int n){
    sort(items.begin(),items.end(),cmp());
    cout<<"Hello";
    double profit=0;
    for(int i=0;i<n;i++){
        if(items[i].wgt<=W){
            profit += items[i].value;
            W -= items[i].wgt;
        }
        else{
            profit += items[i].value * ((double)W / items[i].wgt);
            break;
        }
    }
    return profit;
}

int main(){
    int n;  // Number of items
    cout << "Enter number of items: ";
    cin >> n;

    vector<Item> items(n);
    cout << "Enter value and weight of each item:\n";
    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].wgt;

    int W;  // Knapsack capacity
    cout << "Enter capacity of knapsack: ";
    cin >> W;
    cout<<"NAMASTE ";
    double maxValue = fractionalKnapsack(W, items, n);
    cout << "\nMaximum value in Knapsack = " << maxValue << endl;

    return 0;
}