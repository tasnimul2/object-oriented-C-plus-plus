//Mohammed Chowdhury
//CS 211-22C
//Assignment #14.1
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int costMatrix[NUM_ROWS][NUM_COLS] ={};
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   for (int i =0; i < NUM_ROWS ; i++){
     costMatrix[i][0] = weight[i][0];//Copy the leftmost column of the weight matrix to the cost matrix
     path[i][0] = to_string(i);//initialize the leftmost column of the path matrix.
     }

   // For each remaining column,Calculate the cost of each square in the column (non-recursively),
   for (int j = 1; j < NUM_COLS ; j++){ //for columns remaining (1 to 4)
     for (int k = 0; k < NUM_ROWS; k++){//for every rows
       int up = costMatrix[(k+NUM_ROWS-1)%NUM_ROWS][j-1];
       int down = costMatrix[(k+1)%NUM_ROWS][j-1];
       int left = costMatrix[k%NUM_ROWS][j-1];

       int smallestCost = min(min(up,down),left); //compares up and down and returns x. Then compares x to left
                                                  //and returns the smallest cost between up down and left.

  // and store the correct number in the cost matrix and the correct string in the path matrix.
  if (smallestCost == up)
    path[k][j]= path[(k+NUM_ROWS-1)%NUM_ROWS][j-1] + to_string(k); //if up is the lowest cost then update path matrix
  else if (smallestCost == left)
    path[k][j]=path[k][j-1]+ to_string(k); //if left is the lowest cost then update path matrix
  else
    path[k][j]= path[(k+1)%NUM_ROWS][j-1] + to_string(k);//if down is the lowest cost then update path matrix

  costMatrix[k][j]= smallestCost + weight[k][j]; //adds the smallest cost and weight matrix and puts it into cost costMatrix
    }
        }

   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   for (int i = 1; i<NUM_ROWS; i++){
     if (costMatrix[0][NUM_COLS - 1] > costMatrix[i][NUM_COLS - 1])
     minRow = i;
   }

   cout << "The length of the shortest path is " << costMatrix[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
}
