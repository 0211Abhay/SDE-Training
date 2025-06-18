#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;

int main(){
    int rows , cols;
    cin >> rows >> cols;
    int count =1;
    vvi matrix(rows, vector<int>(cols,0));

    cout << rows << " " << cols << "\n";
    // for(int i = 0 ; i < rows ; i++){
    //     for ( int j = 0 ; j < cols ; j ++){
    //         matrix[i][j] = count++;
    //     }
    // }
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
        cout << "vertical" << "\n";

    for(int i = 0 ; i < rows ; i++){
        for ( int j = 0 ; j < cols ; j ++){
            matrix[i][j] = j*matrix.size() + i + 1 ;
        }
    }



    for(int i = 0 ; i < rows ; i ++){
        for ( int j = 0 ; j < cols ; j ++){
            cout << matrix[i][j] << "\t";
        }
        cout <<"\n";
    }
}

