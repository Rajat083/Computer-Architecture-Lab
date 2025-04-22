#include "Boolean_operations.cpp"
#include <iostream>
#include <math.h>
using namespace std;

class Result{
public:
	string sum;
	string carry;
	Result(){}
    Result(Result const &r){
        this->sum = r.sum;
        this->carry = r.carry;
    }
	Result(string sum, string carry){
		this->sum = sum;
		this->carry = carry;
	}
};

Result half_adder(string A, string B){
    string sum = xor_operation({A, B});
    string carry = and_operation({A, B});

    return Result{sum, carry};
}

Result full_adder(string A, string B, string C){
    Result r1 = half_adder(A, B);
    Result r2 = half_adder(r1.sum, C);
    string carry = or_operation({r1.carry, r2.carry});

    return Result{r2.sum, carry};
}

Result add(string A, string B){
    string sum = "";
    string carry = "0";
    if(A.length() != B.length()){
        for(int i=0; i<abs(A.length()-B.length()); i++){
            if(A.length() > B.length()){
                B = "0" + B;
            }
            else{
                A = "0" + A;
            }
        }
    }
    for(int i=A.length()-1; i>=0; i--){
        Result r = full_adder(A.substr(i, 1), B.substr(i, 1), carry);
        sum = r.sum + sum;
        carry = r.carry;
    }

    return Result{sum, carry};
}
