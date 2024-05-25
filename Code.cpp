#include <bits/stdc++.h>
using namespace std;

class Person{
    public:
    string name;
    int totalAmount;
};


int getMin(int numPerson,Person array[])
{
    int index = 0;
    for (int i = 1; i < numPerson; i++)
        if (array[i].totalAmount < array[index].totalAmount)
            index = i;
    return index;
}

int getMax(int numPerson,Person array[])
{
    int index = 0;
    for (int i = 1; i < numPerson; i++)
        if (array[i].totalAmount > array[index].totalAmount)
            index = i;
    return index;
}


void minimizeFlow(int numPerson,Person array[]){
     int miniAmount = getMin(numPerson,array);
     int maxiAmount = getMax(numPerson,array);
     
     if(array[miniAmount].totalAmount==0&&array[maxiAmount].totalAmount==0) return;
     
     int mini = min(-array[miniAmount].totalAmount,array[maxiAmount].totalAmount);
     
     array[miniAmount].totalAmount += mini;
     array[maxiAmount].totalAmount -= mini;
     
     cout<<array[maxiAmount].name <<" Pays Rs."<<mini<<" to "<<array[miniAmount].name<<endl;
     
     minimizeFlow(numPerson,array);
}

int main() {
	// your code goes here
	
	int numPerson;
	cin>>numPerson;
	cout<<"Enter the number of Person involve in Transactions: "<<numPerson<<endl;
	Person array[numPerson];
	
	unordered_map<string,int>mp;  //map--> name with index
	
	for(int i=0;i<numPerson;i++){
	    string s1;
	    cin>>s1;
	    cout<<"Enter the name of "<<(i+1)<<"th Person: "<<s1<<endl;
	    array[i].name = s1;
	    mp[s1] = i;
	}
	
	vector<vector<int>>transactions(numPerson,vector<int>(numPerson,0));
	int numberOfTransactions;
	cin>>numberOfTransactions;
	cout<<endl<<"Enter the number of Transactions: "<<numberOfTransactions<<endl;
	
	for(int i=0;i<numberOfTransactions;i++){
	     
	    string from,to;
	    int amount;
	    cin>>from>>to>>amount;
	    cout<<(i+1)<<"th Transaction --> "<<from<<" Pays Rs."<<amount<<" to "<<to<<endl;
	    
	    transactions[mp[from]][mp[to]] = amount;
	}
	
	for(int i=0;i<numPerson;i++){
	     int value = 0;
	     for(int j=0;j<numPerson;j++){
	          value = value + transactions[j][i] - transactions[i][j];
	     }
	     array[i].totalAmount = value;
	}
	
	cout<<endl<<"Minimum Required transactions:"<<endl;
	minimizeFlow(numPerson,array);
	return 0;

}

/* Input Format
5
Punit
Saumy
Aryan 
Vishal
Anoop
7
Punit Aryan 1000
Punit Anoop 2000
Saumy Vishal 3000
Aryan Anoop 4000
Vishal Punit 5000
Anoop Saumy 6000
Aryan Saumy 7000
*/
