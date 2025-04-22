#include <iostream>
#include "Boolean_operations.cpp"
#include <algorithm>
using namespace std;

string ones_comp(string number){
	return not_operation(number);
}

string bin_to_dec(string number){
	int res = 0;
	for(int i=0; i<number.length(); i++){
		res = res*2 + (number[i] - '0');
	}
	return to_string(res);
}

string add_binary(string a, string b){
	if(a.length() < b.length()){
		swap(a, b);
	}
	while(b.length() < a.length()){
		b = '0' + b;
	}
	string res = "";
	int carry = 0;
	for(int i=a.length()-1; i>=0; i--){
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		res = to_string(sum%2) + res;
		carry = sum/2;
	}
	return res;
}

string twos_comp(string number){
	return add_binary(ones_comp(number), "1");
}

string signed_rep(string number){
	string res = "";
	for(int i=0; i<number.length(); i++){
		res += number[i];
	}
	res[0] = (res[0] == '0') ? '1' : '0';
	return res;
}

string bias_rep(string number, string bias){
	string res = "";
	for(int i=0; i<number.length(); i++){
		res += number[i];
	}
	if(res[0] == '0') return add_binary(res, bias);
	else return twos_comp(add_binary(res, bias));
}

	
