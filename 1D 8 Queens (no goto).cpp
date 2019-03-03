
//Assignment #7

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c);
void print(int q[]);
void backtrack(int& col);

int main() {
  int q[8] = {};
  // Initialize the array to 0.
  int c = 0;
  // Start in the 1st row, 1st column
  q[0]= 0;
  
  while (c >= 0) {
    // End the loop if you backtrack from the first column
    // Move to the next column
    ++c;
    // If you have passed the last column, Call the print function and backtrack
    if (c == 8){
      print(q);
      backtrack(c);
    }
    // Otherwise, move to one before the first row
    else q[c]= -1;
    
    while (c >= 0) {
      // Move to the next row
      ++q[c];
      // If you have passed the end of the column, backtrack
      if (q[c] == 8) backtrack(c);
      // Otherwise, call the ok function. If it returns
      //true, go back to the beginning of the outer loop.
      else if (ok(q,c)) break;
    }
  }
      return 0;
}


/* ------------------- FUNCTIONS-------------------*/


// Returns true if the queen in column c is ok

bool ok(int q[], int c) {
  for (int i = 0; i < c; i++)
  // if there is a conflict between the queens in columns i and c (row and col test)
  if (q[c] == q[i] || ((c-i) == abs(q[c] - q[i]))){
    return false;
    }
    return true;
}

void print(int q[]) {
  static int numSolutions = 0;
  cout << "Solution #" << ++numSolutions << ": ";
  for (int i = 0; i < 8; i++)
  cout << q[i];
  cout << "\n";

}

void backtrack(int& col){
  // Go back to the previous column
  --col;
  if (col == -1) exit(0);
}
