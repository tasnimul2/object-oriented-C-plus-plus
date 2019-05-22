#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c, int n) {
   // Fill in.
   for(int i=0; i < c; i++){
     if((q[c]/n - q[i]/n) == abs(q[c]%n - q[i]%n))//q[c]/n gives row , q[c]%n give you col. if row = col,
      return false; // conflict.
    }
   return true;
}

// The function below is from a working n queens program.
// Add a 2nd parameter, k, and modify the function so that it will work for the k bishops program.
// You will have to change the board representation,
// the conditions for when you've found a solution and when to backtrack, and the ok function call.

int kbishops(int n, int k) { //n == board size, k = number of bishops. Also chaged title of function  to kbishops from nQueens.
   int* q = new int[k];//There is one element for every bishob
                      //since size of board & size of array can be differnt
   q[0] = 0;
   int c = 0, solutions = 0;
   while (c >= 0) {
      ++c;
      if (c == k) { //if on the last col of the array, aa soultion is found.
         ++solutions; //add to soltions
         --c;//backtrack and find  new solution
      }
      else
         q[c] = q[c-1];//test again from previous row.
      while (c >= 0) {
         ++q[c];
         if (q[c] == n*n) //this is a n*n board. Each box is counted separately. (on 5*5 , there are 25 boxes)
            --c;
         else if (ok(q, c ,n)) // need to and n into funtion
            break;
      }
   }
   delete[] q;
   return solutions;
}

int main() {
   int n, k;
   while (true) {
      cout << "Enter value of n: ";
      cin >> n;
      if (n == -1)
         break;
      cout << "Enter value of k: ";
      cin >> k;
      cout << "number of solutions: " << kbishops(n, k) << "\n";
   }
   return 0;
}
