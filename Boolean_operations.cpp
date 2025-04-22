#include <iostream>
#include <vector>
using namespace std;


string and_operation(vector<string> s)
{
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
			if (s[i][j] == '1' && output[j] == '1')
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
	return not_operation(and_operation({s}));
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


string nor_operation(string s)
{
	return not_operation(or_operation({s}));
}

string xor_operation(vector<string> s)
{
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
			if (s[i][j] != output[j])
				temp += "1";
			else
				temp += "0";
		}
		output = temp;
	}
	return output;
}

string xnor_operation(vector <string> s)
{
	return not_operation(xor_operation(s));
}