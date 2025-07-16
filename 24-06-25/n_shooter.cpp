#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;

    // int MSB = pow(2, floor(log2(n)));
    // int l=n-MSB;
    // cout << (l<<1)+1;

    int index = floor(log2(n));
    int power = pow(2,index);

    int ans =  ( (n ^ power)<<1)|1;
    cout << ans;

}