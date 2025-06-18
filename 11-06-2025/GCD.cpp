#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b == 0){
        cout << a << " " << b << "\n";
        return a;
    }
    cout << a << " " << b << "\n";
    return gcd(b,a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    int ans = gcd(a,b);
    cout << ans;
}