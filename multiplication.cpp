#include <iostream>
#include "adders.h"
using namespace std;


void right_shift(string& u, string& v){
	v = u[u.length()-1] + v;
	u.pop_back();
	u = "0" + u;
	v.pop_back();
}


string multiplication(string A, string B){
	string u = "";
	for(int i=0; i<A.length(); i++){
		u += "0";
	}
	// cout<<"u: "<<u<<endl;
	string v = B;
	// cout<<"v: "<<v<<endl;
	for(int i=B.length()-1; i>=0; i--){
		if(B[i] != '0'){
			u = add(u, A);
			// cout<<"u: "<<u<<endl;	
		}
		right_shift(u, v);
		// cout<<"u+v: "<<u+v<<endl;
	}
	return u+v;
}



int main(){
	string A = "1011";
	string B = "101";

	string res = multiplication(A, B);
	cout<< res;
	cout<<endl;
}
