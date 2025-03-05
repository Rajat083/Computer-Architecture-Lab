#include <iostream>
#include <algorithm>
using namespace std;

string ones_comp(string number){
	string res = "";
	for(int i=0; i<number.length(); i++){
		if(number[i] == '0') res += "1";
		else res += "0";
	}
	return res;
}

string bin_to_dec(string number){
	int res = 0;
	for(int i=0; i<number.length(); i++){
		res = res*2 + (number[i] - '0');
	}
	return to_string(res);
}

string add_binary(string a, string b){
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
	string res = ones_comp(number);
	if(res.length() == 1){
		res[0] = (res[0] == '0') ? '1' : '0';
		return res;
	}		
	if(res[number.length() - 1] == '0'){
		res[number.length() - 1] = '1';
		return res;
	}
	res[number.length() - 1] = '0';
	for(int i=number.length()-2; i>=0; i--){
		if(res[i] == '0'){
			res[i] = '1';
			return res;
		}
		else res[i] = '0';
	}
	return res;
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

// int main(){
// 	string inp;
// 	string bias;
// 	cout<<"1. ones comp"<<endl;
// 	cout<<"2. twos comp"<<endl;
// 	cout<<"3. signed rep"<<endl;
// 	cout<<"4. Bias rep"<<endl;
// 	cout<<"5. enter input"<<endl;
// 	int n;
// 	cout<<"Enter input: ";
// 	cin>>inp;
// 	while(true){
// 		cout<<endl<<"Enter choice: ";
// 		cin >>n;
// 		switch(n){
// 			case 1:cout<<"ones comp: "<<ones_comp(inp)<<endl;
// 				break;
// 			case 2:cout<<"twos comp: "<<twos_comp(inp)<<endl;
// 				break;
// 			case 3:cout<<"signed rep: "<<signed_rep(inp)<<endl;
// 				break;
// 			case 4:
// 				cout<<"Enter bias: ";
// 				cin>>bias;
// 				cout<<"Bias rep: "<<bias_rep(inp, bias)<<endl;
// 				break;
// 			case 5:cout<<"Enter input: ";
// 				cin >> inp;
// 				break;
// 		}
// 	}
// 	return 0;
// }

	
