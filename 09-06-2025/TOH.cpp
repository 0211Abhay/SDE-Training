#include<bits/stdc++.h>
using namespace std;

int TOH(int n){
    if(n==1){
        return 1;
    }
    return 2*TOH(n-1)+1;
}
int main(){
    int n;
    cin >> n;
    int steps = TOH(n);

    cout << steps;
}