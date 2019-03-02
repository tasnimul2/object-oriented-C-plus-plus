//Assignment #6

#include <iostream>
#include <cmath>
using namespace std;

int main() {

/*BOARD SETUP*/

int q[8], //1D array representation of the chess board
c = 0; //column index, initially 0
q[0] = 0; //putting 1st queen piece on upper-left corner(row 0 col 0) q[c] is row. c is column.


next_col:

++c; // This will take you to the next column.
if(c == 8) goto print; //solutions for element 0 to 7 are found.
q[c]= -1; //if a solution is not found start over from col -1.

next_row:
++q[c];
//after testing every row, if there is no solution, go to backtrack so it can go back a row.
if (q[c]== 8) goto backtrack;

// if the current row # matches row i , go to the next row. Then test diagonally .
//(row[current] == row i *row test* ) || (col-i == abs(current row - row i ) *up and down diagonal test* )
for (int i=0;i<c; i++){
  if (q[c]== q[i] || (c-i) == abs(q[c]-q[i])) goto next_row;
}

goto next_col;

backtrack:
--c; // go back to the previous column.
if (c == -1) return 0; //all the solutions were found, so end program.
goto next_row;


print:
static int count = 0;;
cout << "Solution #"<< ++count << ": ";
for (int i = 0; i < 8; i++)
  cout << q[i];
  cout << endl;

goto backtrack;



}

