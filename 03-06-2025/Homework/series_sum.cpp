#include<iostream>
using namespace std;
int seriesSum(int n) {
        return (n*(n+1))/2;
    }
int main(){
    int n;
    cin >> n;
    int seriesSumtillN = seriesSum(n);
    cout << seriesSumtillN;
}