#include<iostream>
using namespace std;
bool armstrongNumber(int n) {
        int temp = n;
        int sum=0;
        while(temp > 0){
            int remain = temp % 10;
            sum += (remain*remain*remain);
            temp/=10;
        }
        
        if(sum == n ){
            return true;
        }
        else{
            return false;
        }
}

int main()
{
    int n;
    cin >> n;
    cout << armstrongNumber(n);
}