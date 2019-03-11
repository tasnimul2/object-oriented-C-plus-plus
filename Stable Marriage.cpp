//Assignment #9

#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c);
void print(int q[]);
void backtrack (int &c);

int main(){
  // c = man , q[c] = woman. 
  int q[3] ={};
  int c = 0;
  q[0]= 0;
  while (c >=0){
    ++c; //move to next man (move to next element)
    if (c == 3){ // if all men have a woman, print solution and go back and look for other combinations
      print(q);
      backtrack(c);
    }
    else q[c] = -1; // set the next mans (element #) woman preference (element value) to -1 so it tests woman 0,1,2 for him
    while (c >=0){
      ++q[c];//increment element value (q[c]) of the current element number (c) to test if there is a match
      if (q[c]==3) backtrack(c); //if all 3 woman were tested, start over
      else if (ok(q,c)) break; // test if there is incompatibility. If so, sart program over from top(break). 
    }
  }
  return 0;
}

//_______________________FUNCTIONS_____________________//
/*
Current Man = i
Current Woman = q[i]
New Man = c
New Woman = q[c]
*/

bool ok(int q[], int c){
  
  int mp[3][3] ={{0,2,1}
                ,{0,2,1},
                 {1,2,0}};
  
  int wp[3][3] ={{2,1,0},
                 {0,1,2},
                 {2,0,1}};
for (int i = 0; i < c; i++){
  if (q[c] == q[i] ) return false; //if new woman has already been assigned to some man then return false
  if (mp[i][q[c]] < mp[i][q[i]] && wp[q[c]][i] < wp[q[c]][c]) return false; //if the current man prefers the new woman to his partner and if the new woman prefers the current man to her partner, marriage unstabe, return false.
  if (mp[c][q[i]] < mp[c][q[c]] && wp[q[i]][c] < wp[q[i]][i]) return false; // if the new man prefers the current woman to his partner and if the current woman prefers the new man to her partner, marriage unstabe, return false.
  }
  return true;

}

void print(int q[]){
  static int solution = 0;
  cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
  for (int i = 0; i < 3; ++i)
  cout << i << "\t" << q[i] << "\n";
  cout << "\n";
}


void backtrack (int &c){
  --c;
  if (c == -1) exit(0);
}
