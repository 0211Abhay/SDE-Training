#include<iostream>
using namespace std;
int reverseDigits(int n) {
        int temp=0;
        while(n>0){
            temp*=10;
            temp+=(n%10);
            n/=10;
        }
        return temp;
    }
int main(){
    int n;
    cin >> n;
    int reversed_n = reverseDigits(n);
    cout << reversed_n;
}