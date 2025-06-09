#include<iostream>
using namespace std;
int alternateDigitSum(int n) {
        int res = 0;
       while(n>0){
        res = n % 10 - res;
        n/=10;
       }
            
        return res;
    }
int main(){
    int n;
    cin >> n;
    int result = alternateDigitSum(n);
    cout << result;
}