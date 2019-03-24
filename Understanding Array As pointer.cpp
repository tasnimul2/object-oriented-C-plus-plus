//Assignment #10

#include <iostream>
using namespace std;

int main( )
{int b[3][2];

cout<<sizeof(b)<<endl; 
//24 bytes. The reason being is that each row  is 4 bytes. 
//There are 3 rows, so 4*3 = 12. There are 2 columns per row so that's (12 bytes * 2 col) = 24 bytes

cout<<sizeof(b+0)<<endl;
//8 Bytes. The reason being is that sizeof(b+0) is another 
//way of saying sizeof(the pointer that points to row 0 if b[3][2]). 
//Since I am using a 64 bit system, it gives me 8. 
//If I was using a 32 bit system then it would return 4 bytes. 

cout<<sizeof(*(b+0))<<endl;
//8 bytes. The reason is that *b+0 points to b[0][i]. In row 0 there are 2 elements (2 col).
//Each element is 4 bytes. 4(bytes)*2(elements) = 8 bytes. 


// the next line prints 0012FF68

cout<<"The address of b is: "<<b<<endl;
//0012FF68. This is the return value because this is the name of the memory location of array b is 0012FF68. 

cout<<"The address of b+1 is: "<<b+1<<endl;
//0012FF70. This is the return value because 0012FF68 + 8 = 0012FF70. 
//We are adding by 8 because there are 2 elements in row 1 of b (b+1). So 4*(2*1)= 8. 

cout<<"The address of &b is: "<<&b<<endl;
//0012FF68. This is the same thing as cout << b << endl;

cout<<"The address of &b+1 is: "<<&b+1<<endl<<endl;
//0012FF80. This is the answer because 4*(3*2)*1 = 24 and adding it with 
//the address of b is  0012FF80. (bytes per element * row * col * offset)
//Unlike (b+1), &(b+1) takes row into account. 

return 0;
}
