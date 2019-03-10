//Assignment #8

#include<iostream>
#include<cmath>
using namespace std;

bool ok(int q[], int col);
void print(int q[]);
void backtrack(int& col);



int main() {
  int q[8] = {};
  int c = 0;
  q[0]=1;
  while (c >= 0){
    ++c; // moves to the next element in the array.
    if (c == 8){
      print(q);
      backtrack(c);
    }
    else q[c] = 0; //sets the current element to 0 so it can try numbers 1-8 in the next while loop. 

    while (c >= 0){
      ++q[c]; // will keep adding element till 8. At first it is 1 (cuz set q[c] = 0) , then it will test 1, then 2, 3...8. If it reaches 9 -->
      if (q[c] == 9) backtrack(c); // if ++q[c] adds the current element to 8, call the backtrack function 
      else if (ok(q,c)) break;  //if there is no conflict break the loop
    }
  }
  return 0;
}


//__________________FUNCTIONS___________________//


bool ok(int q[], int col) {
  
	static int checkList[8][5] = {
		{-1},
		{0,-1},
		{1,-1},
		{0,1,2,-1},
		{1,2,3,-1},
		{2,4,-1},
		{0,3,4,-1},
		{3,4,5,6,-1},
	};
  //row test
	for (int i = 0; i < col; i++){
    if (q[i] == q[col]) return false; // if the number in the current element being tested  was used already , dont break the loop.
  }
  
  //consecutive  number test 
  for (int i = 0; checkList[col][i] != -1; ++i){
    if ( abs(q[col]- q[checkList[col][i]]) == 1) return false; //if difference between current element and neighbor element is 1, return false. 
  }
  return true;

} 

void print(int q[] ) {
	static int count = 0;
	cout << " Soultion number: " << ++count << endl;
  cout <<endl;
	cout << " " << " " << q[1] << q[2] << endl;
	cout << " " << q[0] << q[3] << q[4] << q[5] << endl;
	cout << " " << " " << q[6] << q[7] << endl;
  cout <<endl;
	return;
}

void backtrack(int& col){
  // Go back to the previous column
  --col;
  if (col == -1) exit(0);
}
