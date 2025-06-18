#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
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
    int rows , cols;
    cin >> rows >> cols;
    int count =1;
    vvi matrix(rows, vector<int>(cols,0));

    cout << rows << " " << cols << "\n";



     cout << "horizontal" << "\n";
    for(int i = 0 ; i < rows ; i++){
        for ( int j = 0 ; j < cols ; j ++){
            matrix[i][j] = i*matrix[0].size() + j + 1 ;
        }
    }

    for(int i = 0 ; i < rows ; i ++){
        for ( int j = 0 ; j < cols ; j ++){
            cout << matrix[i][j] << "\t";
        }
        cout <<"\n";
    }

    vector<int> vi;

    for(int i = 0 ; i < rows ; i ++){
        for ( int j = 0 ; j < cols ; j ++){
            vi.push_back(matrix[i][j]); 
        }
        cout <<"\n";
    }
    int data;
    cin >> data;
    int result = binarysearch(vi,0,vi.size(),data);

    cout << result;
}