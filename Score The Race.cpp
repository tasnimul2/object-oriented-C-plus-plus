//Mohammed Chowdhury
//CSCI 211-22
//Assignment #3 - Score the Race 


#include<iostream>
#include<iomanip>
#include <algorithm> 
using namespace std;

bool valid (string results);


int main(){
	string results;
	char winnerOfRace=' ';
	double scores[26]={0};
	int AmountOfMembers[26]={0};
	int teams=0,runners=0,score=0;
	
  
	cout<<"What is the result of the race? Enter 'done' when you have finished: ";
	while(cin>>results){
		if(results=="done")break;
		if(valid(results)){ 
			for(int i=0;i<results.size();i++){
				AmountOfMembers[(int)results[i]-65]++; 
				// ^^  this will put each team into one element of an array and add one when there is a new member
				scores[(int)results[i]-65]+=i+1; //adds points for each team depeding on their positions
			}
		}
       else cout << "INVALID\n";
	}
	score=scores[0];
	
	for(int i=0;i<26;i++){
		if(AmountOfMembers[i]>0){    //goes through the alphabet and tells c++ which teams are  contending in the race. 
			teams++;
			runners=AmountOfMembers[i];
		}
	}

	for(int i=0;i<26;i++){
		if(scores[i]>0){
			scores[i]/=runners;
			if(scores[i]<score){
				score=scores[i];
				winnerOfRace=(char)(i+65);
			}
		}
	}
	
	cout<<"Number of teams:  "<<teams<< endl<<endl;
	cout<<"Numver of Runners per team: "<<runners<<endl<<endl;
	cout<<"Team:\t"<<"Score:"<<endl;
	for(int i=0;i<26;i++){
		if(AmountOfMembers[i]>0){
			cout<<(char)(i+65)<<"\t"<<"\t"<<setprecision(2)<<fixed<<scores[i]<<endl;
		}
	}
	cout<<"Team "<<winnerOfRace<<" won with a score of "<<setprecision(2)<<fixed<<scores[(int)(winnerOfRace)-65]<<"."<<endl;

	return 0;
}

bool valid (string results){
  int a[1000] = {};
  int *end = a + results.size();
  bool validity = true;
  int counter = 0;
  for (int i = 0; i < results.size(); i++){
    a[i] = results[i];
  }
  sort(a,end);
  for (int j = 0; j < results.size(); j++){
    if (a[j] == a[j-1]) counter++;
  }
  if (counter > results.size()) validity = false;
  return validity;
}
