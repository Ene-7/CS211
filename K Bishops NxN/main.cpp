#include <iostream>
#include <cmath>
using namespace std;

bool ok(int *q, int now, int n){
	for (int i = 0; i<now; i++) {//Find if bishops are on the same diagonal
	  if(q[now] < q[i]) return false; // Prevent Duplicates	
		if(q[i]/n+q[i]%n==q[now]/n+q[now]%n || q[i]/n-q[i]%n==q[now]/n-q[now]%n) 
			return false; //if on positive diagonal or if on negative diagonal
	
	}
		return true;
};

void move(int *q, int i, int k, int n, int &count){
	if(i == k){ //good
	  ++count;
	  return;
	}
	for(int m = 0; m < (n*n); m++){
	  q[i] = m; // Set up array with size bishop(s) assign the Number of the space it is in 0 to n -1.
	  if(ok(q,i,n))
	    move(q,i+1,k,n,count);
	}
	return;
};

int main(){
	int i_n, i_k; //i_n is the size of board, i_k is the # of bishops

	do{
	  while(true){
		  cout << "Enter value of i_n: ";
		  cin >> i_n;
		  if(i_n == -1)
			  return 0;
		  cout << "Enter value of i_k: ";
		  cin >> i_k; 
		  if(i_n>=i_k) break; // Check if Input Is Valid. Break if it is loop if it's not.
		  else{
		    cout << "\n" <<"i_n needs to be >= to i_k!"<<endl;
		    continue;
		  }
	  }
		int count = 0;
		int *q = new int[i_k];
		move(q, 0, i_k, i_n, count);
		cout << "Number of solutions: " << count << endl;
		delete []q;
	}while(true);
	
	return 0;
}