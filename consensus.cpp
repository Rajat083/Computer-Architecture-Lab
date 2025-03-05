#include <iostream>
#include "Boolean_operations.h"
using namespace std;

void consensus(string X, string Y, string Z){
	string XY = and_operation(X, Y);
	string XcZ = and_operation(not_operation(X), Z);
	string YZ = and_operation(Y, Z);

	string raw = or_operation({XY, XcZ ,YZ});
	string proof = or_operation({XY, XcZ});
	cout<<"Raw result: "<<raw<<endl;
	cout<<"Proof : "<<proof<<endl;
	cout<<endl;
}

int main(){
	string X, Y, Z;
	char c;
	while(true){
		cout<<endl;
		cout<<"Enter X : ";
		cin>>X;
		cout<<"enter Y : ";
		cin>>Y;
		cout<<"Enter Z : ";
		cin>> Z;

		cout<<endl;

		consensus(X, Y, Z);
		
		cout<<"Still want to continue? (y/n) : ";
		cin >> c;

		if(c == 'n'){
			break;
		}
	}
}
