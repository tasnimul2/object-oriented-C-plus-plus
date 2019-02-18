
//Assignment #4 - 2D Eight Queens

#include <iostream>
using namespace std;

int main() {
   // Initialize the board to 0
   int q[8][8] = {};

   // Start in the 1st row, 1st column, and place a queen there
   int r = 0, c = 0;
   q[r][c] = 1;

nextCol:
   // Move to the next column
   c++;

   if (c == 8)//you have passed the last column
      goto print;

   // Move to one before the first row
   r = -1;

nextRow:
   // Move to the next row
   r++;

   if (r == 8)//you have passed the end of the column
      goto backtrack;

   // If there is a queen in the same row (to the left), goto nextRow
   for (int x = 0; x < c ; x++) //each square to the left of the current square
      if (q[r][x]== 1)//there is a queen on that square
         goto nextRow;

   // If there is a queen in the upper-left diagonal, goto nextRow
   for (int y = 1; (r-y) >= 0 && (c-y)>=0; y++) // End the loop when you are above or left of the chessboard
      if (q[r-y][c-y] ==1) //there is a queen i spots above and left of the current square
         goto nextRow;

   // If there is a queen in the lower-left diagonal, goto nextRow
   for (int i = 1; (r+i) <= 7 && (c-i) >=0; i++) // End the loop when you are below or left of the chessboard
      if (q[r+i][c-i]==1)//there is a queen i spots below and left of the current square
         goto nextRow;

   // Place a queen in the current square (2D version only)
   q[r][c] = 1;


   goto nextCol;

backtrack:
   // Move to the previous column
   c--;


   if (c == -1)//you have moved to the left of the chessboard
      return 0; //exit the program
      
   // Find the square in the column with a queen in it and set r to the row number of that square
   r=0;
   while (q[r][c] !=1 )
   r++;
   // Remove the queen from the current square
   q[r][c] = 0;

   goto nextRow;

print:
   static int numSolutions = 0; //numSolutions is declared only once and only executed once by using "static"
   cout << "Solution #" << ++numSolutions << ":\n";// if this was numSolutions++ , it would print numSolutions and then increment

   // nested loop to print the chessboard
   for (int r = 0; r <= 7; r ++) {
     for (int c = 0; c <=7; c++){
       cout << q[r][c];
     }
     cout <<endl; 
   }
   goto backtrack;
}
