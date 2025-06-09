#include <bits/stdc++.h>
using namespace std;

void Nto1(int n){
    static int i = 1;
    if(i == n){
        cout << i << endl;
        return;
    }
    cout << i++ << " ";
    Nto1(n);
}


int main(){
    int limit;
    cin >> limit;
    Nto1(limit);

}