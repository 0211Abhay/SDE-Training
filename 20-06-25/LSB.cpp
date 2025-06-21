#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 6;
    int b = log2(n & -n);
    cout << (n & -n) << endl;
    cout << b;
}