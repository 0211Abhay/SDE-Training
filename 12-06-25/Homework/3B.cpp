#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

int  find_element(vvi matrix, int start, int end, int data){
    if(start > end){
        return -1;
    }
    int mid = (start +end) / 2;
    int row = mid / matrix[0].size();
    int cols = mid % matrix[0].size();

    if(matrix[row][cols] == data){
        return mid;
    }
    else if(matrix[row][cols] > data){
        find_element(matrix, start, mid-1, data);
    }else{
        find_element(matrix, mid+1, end, data);
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

    int data;
    cin >> data;


    int result = find_element(matrix, 0, rows*cols, data);
    cout << result; 


}