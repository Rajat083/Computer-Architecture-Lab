#include <iostream>
#include <vector>
using namespace std;

string and_operation(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '0')
			return "0";
	}
	return "1";
}

string and_operation(string s1, string s2)
{
	string s = "";
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == '1' && s2[i] == '1')
			s += "1";
		else
			s += "0";
	}
	return s;
}

string or_operation(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
			return "1";
	}
	return "0";
}

string or_operation(vector<string> s){
	string output = "";
	for (int i = 0; i < s[0].length(); i++)
	{
		if (s[0][i] == '1')
			output += "1";
		else
			output += "0";
	}
	for (int i = 1; i < s.size(); i++)
	{
		string temp = "";
		for (int j = 0; j < s[i].length(); j++)
		{
			if (s[i][j] == '1' || output[j] == '1')
				temp += "1";
			else
				temp += "0";
		}
		output = temp;
	}
	return output;
}


string not_operation(string s)
{
	if(s.length() == 0){
		return "0";
	}
	if(s.length() == 1){
		if(s[0] == '0'){
			return "1";
		}
		else{
			return "0";
		}
	}
	string output = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
			output += "0";
		else
			output += "1";
	}
	return output;
}

string nand_operation(string s)
{
	return not_operation(and_operation(s));
}

string nor_operation(string s)
{
	return not_operation(or_operation(s));
}

string xor_operation(string s)
{
	int one_count = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '1')
			one_count++;
	}
	return (one_count % 2 == 1) ? "1" : "0";
}

string xor_operation(string A, string B){
	string output = "";
	for (int i = 0; i < A.length(); i++)
	{
		if (A[i] == B[i])
			output += "0";
		else
			output += "1";
	}
	return output;
}

// int main(){
// 	// string s;
// 	// cout << "Enter the binary string: ";
// 	// cin >> s;
// 	// cout << "1. AND operation: " << endl;
// 	// cout << "2. OR operation: " << endl;
// 	// cout << "3. NOT operation: " << endl;
// 	// cout << "4. NAND operation: " << endl;
// 	// cout << "5. NOR operation: " << endl;
// 	// cout << "6. XOR operation: " << endl;
// 	// cout << "7. Enter input: ";
// 	// int n;
// 	// while(true){
// 	// 	cout << endl << "Enter choice: ";
// 	// 	cin >> n;
// 	// 	switch(n){
// 	// 		case 1: cout << "AND operation: " << and_operation(s) << endl;
// 	// 			break;
// 	// 		case 2: cout << "OR operation: " << or_operation(s) << endl;
// 	// 			break;
// 	// 		case 3: cout << "NOT operation: " << not_operation(s) << endl;
// 	// 			break;
// 	// 		case 4: cout << "NAND operation: " << nand_operation(s) << endl;
// 	// 			break;
// 	// 		case 5: cout << "NOR operation: " << nor_operation(s) << endl;
// 	// 			break;
// 	// 		case 6: cout << "XOR operation: " << xor_operation(s) << endl;
// 	// 			break;
// 	// 		case 7: cout << "Enter input: ";
// 	// 			cin >> s;
// 	// 			break;
// 	// 		default: cout << "Invalid choice" << endl;
// 	// 	}
// 	// }
// 	// return 0;
// }