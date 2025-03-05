#include <iostream>
#include "Boolean_operations.h"
using namespace std;

void de_morgan_and(string A){
	string aNd = and_operation(A);
	string dM = not_operation(aNd);
	string proof = "";
	for(int i=0; i<A.length(); i++){
		proof += not_operation(string (1, A[i]));
	}
	proof = or_operation(proof);
	cout<<dM<<endl;
	cout<<proof<<endl;
}

void de_morgan_or(string A){
	string oR = or_operation(A);
	string dM = not_operation(oR);
	string proof = "";
        for(int i=0; i<A.length(); i++){
                proof += not_operation(string (1, A[i]));
        }
        proof = and_operation(proof);
	cout<<dM<<endl;
	cout<<proof<<endl;
}



int main(){
	de_morgan_and("11");
	de_morgan_or("11");
	return 0;
}

