Array :

Time Complexity:
 Insert : O(1)
 Remove : O(1)
 Update : O(1)
 Pushing : O(n)
 Pop : O(n)


Pushing : 
    Steps : Reserve n+1 slots in memory ---->  O(1)
            Copy n elements ----> O(n)
            Insert n+1 th element O(1)
                    Over all : O(n+2) ----> that is O(n)



Popping : 
    Steps : Reserve n-1 slots in memory ---->  O(1)
            Copy n-1 elements ----> O(n)
                    Over all : O(n+1) ----> that is O(n)

Array :

Time Complexity:
 Insert : O(1)
 Remove : O(1)
 Update : O(1)
 Pushing : O(1)
 Pop : O(1)

Ammotization :

    Vectors are made of arrays, when we create a vector and we fill it with n elements. Once we try to add the n+1 element, we will create a 2n size array this 2n size array we can add the n+1 th element. for the remaining n-1 spaces we will have a O(1) insertion. Which averages to a over all amotized complexity of O(1).




Vector Decleration: 
    vector<int> v;  ----> calls default constructor of the vector class  for the object v
    vector<int> v(n); ----> calls parameterized constructor of the vector class  for the object v with size n
    vector<int> v(n,0); ----> calls parameterized constructor of the vector class  for the object v with size n and inital values as 0



v.size() gives us the size of the vector v 



segmentation fault occurs when there is a memory read / write for a non allocated memory space

v.push_back  is a function that performs push operation for vectors
v.pop is a function that performs pop operation for vectors

TODO : 
    Max element of array and vectors
    Max element of array and vectors in functional / modular programming
        modules: input, output, logic
    Reverse a Vector -> 2 pointer approach
    Rotate a vector by k elements ---> clockwise and anticlockwise


Pass by value
pass by reference
pass by pointer


