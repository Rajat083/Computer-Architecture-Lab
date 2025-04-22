#include <iostream>
#include "adders.cpp"
using namespace std;

// class Result {
// public:
//     string sum;
//     string carry;
//     Result() {}
//     Result(string sum, string carry) {
//         this->sum = sum;
//         this->carry = carry;
//     }
//     Result& operator=(const Result& other) {
//         if (this != &other) {
//             this->sum = other.sum;
//             this->carry = other.carry;
//         }
//         return *this;
//     }
// };

// Result addBinaryStrings(string A, string B) {
//     string sum = "";
//     string carry = "0";
//     int lengthDiff = A.length() - B.length();

//     // Pad shorter string with zeros
//     if (lengthDiff > 0) {
//         B = string(lengthDiff, '0') + B;
//     } else {
//         A = string(-lengthDiff, '0') + A;
//     }

//     for (int i = A.length() - 1; i >= 0; i--) {
//         int aBit = A[i] - '0';
//         int bBit = B[i] - '0';
//         int cBit = carry[0] - '0';

//         int sumBit = aBit ^ bBit ^ cBit;
//         carry = ((aBit & bBit) | (bBit & cBit) | (aBit & cBit)) ? "1" : "0";

//         sum = (char)(sumBit + '0') + sum;
//     }

//     return Result(sum, carry);
// }

void right_shift(Result &u, Result &v) {
    v.sum = u.sum[u.sum.length() - 1] + v.sum;  
    u.sum.pop_back();                           
    u.sum = u.carry + u.sum;                    
    v.sum.pop_back();                         
}

void right_shift(string& u, string& v) {
    v = u[u.length() - 1] + v;
    char carry = u[0];
    u.pop_back();
    if(carry == '1'){
        u = "1" + u;
    }
    else {
        u = "0" + u;
    }
    v.pop_back();
}

string multiplication(string A, string B) {
    Result u;
    for (int i = 0; i < A.length(); i++) {
        u.sum += "0";
    }

    Result v;
    v.sum = B;

    for (int i = B.length() - 1; i >= 0; i--) {
        if (B[i] == '1') {  // Add only if B[i] is 1
            u = add(u.sum, A);
        }
        right_shift(u, v);  // Shift both u and v
    }
    return u.sum + v.sum;
}

// int main() {
//     string A = "1010";  // Binary for 10
//     string B = "1101";  // Binary for 13
//     cout << "Product: " << multiplication(A, B) << endl;
//     return 0;
// }
