//Mohammed Chowdhury
//Assignment #12
//CS 211 -22C
#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) ;
int nqueens(int n);

int main() {
   int n;
   cout << "How many Queens Would you like on you n X n board?\n";
   cin >> n;
   cout << "Solutions for 1 to " << n << " queens : \n";

   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}

//______________________________________ FUNCTIONS ______________________________________//


bool ok(int q[], int c) {
  for (int i = 0; i < c; i++)
  // if there is a conflict between the queens in columns i and c (row and col test)
  if (q[c] == q[i] || ((c-i) == abs(q[c] - q[i]))){
    return false;
    }
    return true;
}
// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n and initialize the first element to 0.
   int *q = new int[n];//asks the heap to reserve n spaces for array q[n]
   q[0]=0;
   int c = 0;
   int solution = 0;
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   while (c >= 0){
     if (c == n-1) { //if the array reaches the last column , that means
       ++solution; //there is a solution
       --c; //go back a column

     }
     else q[++c] = -1;//sets next row (next element) to -1 to test 0 to n in the next while loop.

     while (c >=0){
       ++q[c];//increments row up by 1 to test next row.
       if (q[c] == n) --c; //if all the combinations were attempted go back to the previous column (element)
       else if (ok(q,c)) break;
     }

   }
   // Delete the array.
   delete[]q;//returns the memory borrowed from the heap after its use. 
   // Return the number of solutions.
   return solution;
}
