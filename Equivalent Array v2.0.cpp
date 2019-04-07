
//Assignment #5 - Equivalent Arrays 2.0 (Updated version)


#include <iostream>
using namespace std;


bool equivalent (int a[],int  b[], int n);


int main(){
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
bool equivalent (int a[],int  b[], int n){
  int offset;
  for (int i = 0; i < n; i++)
    if (a[0] == b[i]) offset = i; //when it finds the offset, it sets that value to offset;
    for (int j = 1; j <n; j++){
      if (a[j] != b[(j+offset)%n]) break; // %n is used to loop back to the begninning.  . Ex if size of array is 5:
                                     //1%5 = 1, 2%5 = 2 .... 4%5 = 4 and when it reaches outside the array
                                     //5%5 = 0, when goes back to the begenning.
      if (j == (n-1)) return true; // when loop reaches to the last number in the array without breking,
                                  // return true because  the array are equibalent.
    }
    return false;
}
