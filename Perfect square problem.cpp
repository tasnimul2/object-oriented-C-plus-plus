//Cs 211-22C
//Assignment #1 - Perfect Square

#include <iostream>

using namespace std;



 int main(){
    for(int i =1; ; i++){
      if(i*i%2 !=0 && i*i/10%2 !=0){
        cout << i*i;
      }
    }
    return 0;
}
