#include <iostream>
using namespace std;

class B_operations{
public:
	bool and_operation(string s){
		for(int i=0; i<s.length(); i += 2){
			if(s[i] == '0') return 0;
		}
		return 1;
	}
	bool or_operation(string s){
		for(int i=0; i<s.length(); i += 2){
			if(s[i] == '1') return 1;
		}
		return 0;
	}
	string not_operation(string s){
		string output = "";
		for(int i=0; i<s.length(); i += 2){
			if(s[i] == '1') output += "0";
			else output += "1";
		}
		return output;
	}
	bool xor_operation(string s){
		int one_count = 0;
		for(int i=0; i<s.length(); i += 2){
			if(s[i] == '1') one_count++;
		}
		return (one_count%2 == 1);
	}
};

int main(){
	B_operations obj;
	cout<<"1. And\n";
	cout<<"2. Or\n";
	cout<<"3. Not\n";
	cout<<"4. XOR\n";
	while(true){
		cout<<endl;
		string input;
		cout<<"Enter booean values:-\n";
		getline(cin, input);
		int operation;
		cout<<"Enter operation: ";
		cin>>operation;
		switch(operation){
			case 1: cout<<obj.and_operation(input)<<endl;
				break;
			case 2: cout<<obj.or_operation(input)<<endl;
                                break;
			case 3: cout<<obj.not_operation(input)<<endl;
                                break;
			case 4: cout<<obj.xor_operation(input)<<endl;
                                break;
			default: exit(0);
		}
	}

}
	
	
