
//Assignment #1 - Perfect Square

#include <iostream>

using namespace std;



int main()
{
    
    int a[] = {};
    
    
    cout << "these are the perfect squares whose last two digits are both odd :  \n";
    
    for (int i=1; i <= 100000; i++){
        a[i] = i*i;
        if ( (a[i] % 10 ) % 2 != 0 && ( (a[i] %100  ) / 10 ) % 2 != 0){
            cout << a[i] << " ";
             
        }
        else cout << " It appears such number does not exist" << endl;
        break;
        
        
    }
      
   return 0;
}
