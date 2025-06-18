#include<bits/stdc++.h>
using namespace std;

double mypow(double x, int n){
    if(n==1){
        return x;
    }
    if(n%2==1){
        return x * mypow(x*x, n/2);
    }
    return mypow(x*x,n/2);
 
}
int main()
{
    double x;
    int n;
    cin >> x;
    cin >> n;
    cout << mypow(x,n);
}