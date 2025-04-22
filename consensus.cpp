#include <iostream>
#include "Boolean_operations.cpp"
using namespace std;

void consensus(string X, string Y, string Z){
	string XY = and_operation({X, Y});
	string XcZ = and_operation({not_operation(X), Z});
	string YZ = and_operation({Y, Z});

	string raw = or_operation({XY, XcZ ,YZ});
	string proof = or_operation({XY, XcZ});
	cout<<"Raw result: "<<raw<<endl;
	cout<<"Proof : "<<proof<<endl;
	cout<<endl;
}
