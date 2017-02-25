#pragma once

using namespace std;
	class Hash
	{
	public:
		Hash();

		string getHash(string);
		
		bool is_File_Shifr(string inputfile);
				
		void shifrFile(string inputfile, bool encode = false);

		~Hash();
		
	private:
		string hash;
		int receivingExistCode(int);
		int getControlSum(string str);
		char CodChar(char ch);
		char EnCodChar(char ch);
	
	};