#include <iostream>
#include "Boolean_operations.h"
using namespace std;

bool and_operation(string s)
{
	for (int i = 0; i < s.length(); i += 2)
	{
		if (s[i] == '0')
			return 0;
	}
	return 1;
}
bool or_operation(string s)
{
	for (int i = 0; i < s.length(); i += 2)
	{
		if (s[i] == '1')
			return 1;
	}
	return 0;
}
string not_operation(string s)
{
	string output = "";
	for (int i = 0; i < s.length(); i += 2)
	{
		if (s[i] == '1')
			output += "0";
		else
			output += "1";
	}
	return output;
}

bool nand_operation(string s)
{
	return !and_operation(s);
}

bool nor_operation(string s)
{
	return !or_operation(s);
}

bool xor_operation(string s)
{
	int one_count = 0;
	for (int i = 0; i < s.length(); i += 2)
	{
		if (s[i] == '1')
			one_count++;
	}
	return (one_count % 2 == 1);
}

int main(){
	string s;
	cout << "Enter the binary string: ";
	cin >> s;
	cout << "1. AND operation: " << endl;
	cout << "2. OR operation: " << endl;
	cout << "3. NOT operation: " << endl;
	cout << "4. NAND operation: " << endl;
	cout << "5. NOR operation: " << endl;
	cout << "6. XOR operation: " << endl;
	cout << "7. Enter input: ";
	int n;
	while(true){
		cout << endl << "Enter choice: ";
		cin >> n;
		switch(n){
			case 1: cout << "AND operation: " << and_operation(s) << endl;
				break;
			case 2: cout << "OR operation: " << or_operation(s) << endl;
				break;
			case 3: cout << "NOT operation: " << not_operation(s) << endl;
				break;
			case 4: cout << "NAND operation: " << nand_operation(s) << endl;
				break;
			case 5: cout << "NOR operation: " << nor_operation(s) << endl;
				break;
			case 6: cout << "XOR operation: " << xor_operation(s) << endl;
				break;
			case 7: cout << "Enter input: ";
				cin >> s;
				break;
			default: cout << "Invalid choice" << endl;
		}
	}
	return 0;
}