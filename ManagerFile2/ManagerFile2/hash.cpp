#include "stdafx.h"

Hash::Hash() {};

int Hash::receivingExistCode(int x)
	{
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) 
		{
			if (x < 48)
				x += 24;
			else
				x -= 47;
		}
		return x;
	}

	int Hash::getControlSum(string str)
	{
		unsigned int sault = 0, strlen = 0;
		for (; strlen < (str.size()); strlen++)
			sault += int(str[strlen]);
		return sault;
	}

	string Hash::getHash(string userString)
	{
		int lenghtHash = 32;
		unsigned int minLen = 2;
		unsigned int realMinLen = 0;
		unsigned int originalSault = this->getControlSum(userString);
		unsigned int originalLenghtStr = (userString.size());
		hash.clear();

		while (minLen <= lenghtHash)
			realMinLen = (minLen *= 2);

		while (minLen < originalLenghtStr)
			minLen *= 2;

		int addCount = minLen - originalLenghtStr;

		for (int i = 0; i < addCount; i++)
			userString += this->receivingExistCode(userString[i] + userString[i + 1]);
		int maxSault = this->getControlSum(userString);
		int maxLenghtStr = (userString.size());

		while (userString.size() != realMinLen)
		{
			for (int i = 0, center = userString.size() / 2; i < center; i++)
				this->hash += this->receivingExistCode(userString[center - i] + userString[center + i]);

			userString = this->hash;
			this->hash.clear();
		}

		unsigned int rem = realMinLen - lenghtHash;

		for (unsigned int i = 0, countCompress = realMinLen / rem; this->hash.size() < (lenghtHash - 4); i++)
		{

			if (i%countCompress == 0)
				this->hash += this->receivingExistCode(userString[i] + userString[++i]);
			else
				this->hash += userString[i];
		}

		this->hash += this->receivingExistCode(originalSault);
		this->hash += this->receivingExistCode(originalLenghtStr);

		this->hash += this->receivingExistCode(maxSault);
		this->hash += this->receivingExistCode(maxLenghtStr);
		return this->hash;
	}

	

	bool Hash::is_File_Shifr(string inputfile)
	{
		string section1 = "[shifr]",
			section2;
		char temp_str[8];
		int _size = section1.size();

		std::fstream file(inputfile.c_str(), std::ios::in | std::ios::binary);

		file.read((char*)temp_str, _size * sizeof(char));

		temp_str[_size] = '\0';
		section2 = temp_str;

		file.close();
		return (section1.compare(section2) == 0);
	}

	char Hash::CodChar(char ch)
	{
		return ~(((ch & 0xE0) >> 1) | ((ch & 0x10) << 3) | ((ch & 0x8) >> 3) | ((ch & 0x07) << 1));
	}

	char Hash::EnCodChar(char ch)
	{
		return ~(((ch & 0x70) << 1) | ((ch & 0x80) >> 3) | ((ch & 0x1) << 3) | ((ch & 0xE) >> 1));
	}

	void Hash::shifrFile(string inputfile, bool encode)
	{
		std::fstream file(inputfile.c_str(), std::ios::in | std::ios::binary);

		file.seekg(0, std::ios::end);
		std::vector<char> vec(file.tellp().seekpos());
		file.seekg(0, std::ios::beg);   
		file.read(&vec[0], vec.size());
		file.close();
		file.open(inputfile.c_str(), std::ios::out | std::ios::binary);
		//std::transform(vec.begin(), vec.end(), vec.begin(), encode ? EnCodChar : CodChar);
		
		for (int i = 0; i < vec.size(); i++)
		{
		vec.at(i) = encode ? EnCodChar((char)vec.at(i)) : CodChar((char)vec.at(i));
		}
		
		if (!encode) file.write("[shifr]", 7);
		else
			vec.erase(vec.begin(), vec.begin() + 7);

		file.write(&vec[0], vec.size());
		file.close();
	}


	Hash::~Hash() {};