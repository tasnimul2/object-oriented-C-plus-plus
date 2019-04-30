//unassigned

#include <iostream>

using namespace std;


int fib(int n);

int main(){
  int n;
  while (true){
  cout << "Fibonacci of what numbers? \n";
  cin >> n;
  cout << "The fibonacci of " << n << " is  " << fib(n) << endl;
  cout << endl;
}

}

int fib(int n){
  static int memo[1000] = {};
  if (n == 1 || n == 2) return 1;

  if (memo[n] != 0) return memo[n];
  memo[n] = fib(n-2) + fib (n-1);
  return memo[n];
  
}
