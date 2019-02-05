//Mohammed Chowdhury
// CS 211 - 22C
// HW#2 - Equivalent arrays

/** write a function bool equivalent(int a[], int b[], int n) which takes two arrays a and b of
length n and returns true is they are shift equivalent and false otherwise.**/

#include <iostream>
using namespace std;

bool equivalent (int a[],int  b[], int n);

int main(){
	int a[] = {1,2,3,4,5};
	int b[] = {3,4,5,1,2};
	bool answer = equivalent ( a,b, 5);
	cout << answer << endl;
	return 0;
}

bool equivalent (int a[],int  b[], int n){
	bool same = true;
	bool answer = false;
	int temp;
	for (int k = 0; k < n; k++) {
		if (a[k] != b[k]) {
			same = false;
			break;
		}
	}
	for (int j = 0; j  < n; j++){
            for (int i = 0 ; i < n ; i++){
                temp = b[0];
                b[i] = b[i+1];
                b[n-1] = temp;
			}
		if (same) {
			answer = true;
			break;
		}
	}
	return answer;
}
