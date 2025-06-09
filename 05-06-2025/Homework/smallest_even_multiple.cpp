#include<bits/stdc++.h>
using namespace std;
int smallestEvenMultiple(int n) {
        return n%2==0 ? n : n*2;
    }
int main(){
    int n;
    cin >> n;

    cout << smallestEvenMultiple(n);
}