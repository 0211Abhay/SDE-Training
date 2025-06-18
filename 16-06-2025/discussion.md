Short-Circuiting 

https://www.geeksforgeeks.org/javascript/javascript-short-circuiting/

https://www.geeksforgeeks.org/short-circuiting-in-c-and-linux/

(1 && 2) --> true
(0 && 2) --> false
(1 || 2) --> true
(0 || 2) --> true


x = 0 , y = 4
bool a = x++ || x++ 

x++ || x++ --> x = 2, a = 1
++x || ++x --> x = 1, a = 1

x = 1 , y = 1
bool a = --x && --y
bool b = x ++ && y++


x = 1 , y = 1
bool a = --x && --y
bool b = x ++ && y++

x = 1 , y = 1
bool a = --x || --y
bool b = x ++ || y++


Sorting:
    Bubble 
    Insertion
    Selection

    Merge
    Quick

        Count
        Heap
        BOGO 
        Bucket
        Radix
        Shell


