#include <iostream>
using namespace std;

typedef double (*func)(double); //declares type func. 
                               //func is a type that declares a variable that takes a double and returns a double 

double integrate (func f, double a, double b);
double line(double x);
double square(double x);
double cube(double x);

int main(){
  cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line,1,5)<<endl; //11.99
  cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square,1,5)<<endl;//41.33
  cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube,1,5)<<endl;//155.99
}

//______________FUNCTIONS__________________//

double line(double x){
  return x;
}
double square(double x){
  return x*x;
}
double cube(double x){
  return x*x*x;
}

double integrate (func f, double a, double b){
  double delta = .0001;
  double sum = 0;

  while (a < b){
    sum += delta * f(a);//f(a) sends "a" into line square or cube function and returns the  new value of a
    a+= delta;//adds starting point (a) by the width untill it gets to the finishing point (b)
              //so the entire area under the curve has been accounted for. 
  }
  return sum;
}
