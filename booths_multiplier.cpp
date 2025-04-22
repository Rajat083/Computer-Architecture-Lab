#include <iostream>
#include "neg_rep.cpp"
#include "adders.cpp"
using namespace std;

void right_shift(Result& A, Result& B) {
    B.sum = A.sum[A.sum.length() - 1] + B.sum;  
    A.sum.pop_back();                           
    A.sum = A.carry + A.sum;                  
    B.sum.pop_back();                         
}

void pad_to_equal_length(string &A, string &B) {
    while (A.length() < B.length()) A = "0" + A;
    while (B.length() < A.length()) B = "0" + B;
}

string booth_multiplier(string multiplicand, string multiplier) {
    pad_to_equal_length(multiplicand, multiplier);
    Result A;
    A.sum = "";
    string B = multiplicand;
    string B_dash = twos_comp(B);
    string Q_prev = "0";
    Result Q;
    Q.sum = multiplier;

    for(int i=0; i<B.length(); i++){
        A.sum = A.sum + "0";
    }
    for (int i = 0; i < multiplicand.length(); i++) {
        if (Q.sum[Q.sum.length() - 1] == '0' && Q_prev == "1") {
            A = add(A.sum, B);
        } else if (Q.sum[Q.sum.length() - 1] == '1' && Q_prev == "0") {
            A = add(A.sum, B_dash);
        }
        right_shift(A, Q);
        Q_prev = Q.sum[Q.sum.length() - 1];
    }
    return A.sum + Q.sum;
}

