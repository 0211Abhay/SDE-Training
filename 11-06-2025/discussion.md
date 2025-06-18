HCF or GCD 

https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/



Row major and column major matrix 

matrices are usually row major and implemented with array of arrays or vector of vectors
they are  2 dimensional m x n  m - rows and n cols

vvi m;
 v.size() gives the number of rows
 v[0].size() gives the number of cols




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