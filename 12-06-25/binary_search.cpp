#include<bits/stdc++.h>
using namespace std;
int binarysearch(vector<int> &v, int start , int end, int data){
    if(start > end){
        return -1;
    }
    int mid = ( start + end ) / 2;

    if(v[mid] == data){
        return mid;
    }
    else if(data > v[mid]){
        binarysearch(v,mid+1, end, data);
    }
    else{
        binarysearch(v,0, mid-1,data);
    }
}
int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    cout << "Enter n elements";
    for(int i = 0; i< n; i++){
        cin >> v[i];
    }
    cout << "Enter data to find";
    int data;
    cin >> data;
    int index = binarysearch(v, 0 , n-1, data);
    if(index == -1){
        cout << " data not found";
    }
    else{
        cout << " data found at index : " << index;
    }
}