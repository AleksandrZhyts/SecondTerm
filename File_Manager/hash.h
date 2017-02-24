#pragma once
using namespace std;
	class Hash
	{
	public:
		string getHash(string);
	private:
		string hash;
		int receivingExistCode(int);
		int getControlSum(string str);
	
	};