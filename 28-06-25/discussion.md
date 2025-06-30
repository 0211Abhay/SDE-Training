copy constructor
pass by pointer
pass by address
pass by value

During compile time memory address (depending on the implementation) are reserved and then it saves all the data in the executable like a.out ouptut.exe etc. Once the user runs the executable it runs values are assigned to this reserved memory locations.


CPP uses static scoping that is it first looks into the local scope and then into the global scope 


Proof of floyd warshall in linked list and graph


Slow and Fast Pointer
      while(fast!=null && fast.next!=null){
          slow = slow.next;
          fast = fast.next.next;

          if(slow==fast)return true;
      }
      return false;
