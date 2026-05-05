#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
int binomialCoeff(int n, int k) {
  	

    if (k > n || k < 0)
        return 0;
  

    if (k == 0 || k == n)
        return 1;


    return binomialCoeff(n - 1, k - 1)
           + binomialCoeff(n - 1, k);
}
int getnCk(int n, int k, vector<vector<int>> &memo) {
  

    if (k > n || k<0)
        return 0;
  

    if (k == 0 || k == n)
        return 1;
  	if(memo[n][k] != -1) return memo[n][k];
    return memo[n][k] = getnCk(n - 1, k - 1, memo) 
      					+ getnCk(n - 1, k, memo);
}
int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int>> memo(n + 1, vector<int> (k + 1, -1));
    // cout << binomialCoeff(n, k);
    cout << getnCk(n,k,memo);
    return 0;
}