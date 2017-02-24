#include "stdafx.h"
//#include "encryption.h"

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