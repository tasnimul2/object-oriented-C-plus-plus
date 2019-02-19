//Mohammed Chowdhury
//CS211- 22C
//Assignment #5 - Equivalent Arrays 2.0


#include <iostream>
using namespace std;



bool equivalent(int a[], int b[], int n);
bool CompareArray(int a[], int b[], int n, int SpacesMoved);

int main() {
   cout << boolalpha; // to print bool values as true/false instead of 1/0

   int a1[5] = {1, 2, 3, 4, 5};
   int a2[5] = {3, 4, 5, 1, 2};

   cout << equivalent(a1, a2, 5) << endl; // true

   int b1[3] = {1, 2, 3};
   int b2[3] = {2, 3, 3};

   cout << equivalent(b1, b2, 3) << endl; // false

   int c1[4] = {2, 3, 4, 1};
   int c2[4] = {1, 4, 3, 2};

   cout << equivalent(c1, c2, 4) << endl; // false

   int d1[4] = {3, 2, 3, 1};
   int d2[4] = {3, 1, 3, 2};

   cout << equivalent(d1, d2, 4) << endl; // true

   int e1[5] = {1, 1, 1, 1, 2};
   int e2[5] = {1, 1, 1, 2, 1};

   cout << equivalent(e1, e2, 5) << endl; // true

   return 0;
}
bool CompareArray(int a[], int b[], int n, int SpacesMoved) {
   for (int i = 0; i < n; i++){
      if (a[i] != b[(i+SpacesMoved) % n])// % n to loop back to the beginning of the array
         return false;
   }
   return true;

}

bool equivalent(int a[], int b[], int n) {
   for (int SpacesMoved = 0; SpacesMoved < n; SpacesMoved++){ //counts the amount of spaces moved
      if (CompareArray(a, b, n, SpacesMoved))  //Shift the array SpacesMoved amount of spots to see if array A and B match.
         return true;
   }
   return false;
}
