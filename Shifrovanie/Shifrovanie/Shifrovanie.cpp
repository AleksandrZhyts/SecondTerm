#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

char CodChar(char ch)
{
	return ~(((ch & 0xE0) >> 1) | ((ch & 0x10) << 3) | ((ch & 0x8) >> 3) | ((ch & 0x07) << 1));
}
char EnCodChar(char ch)
{
	return ~(((ch & 0x70) << 1) | ((ch & 0x80) >> 3) | ((ch & 0x1) << 3) | ((ch & 0xE) >> 1));
}


void foo(const char * inputfile, const char * outputfile, bool encode = false) {
	std::fstream file(inputfile, std::ios::in | std::ios::binary);
	file.seekg(0, std::ios::end);
	std::vector<char> vec(file.tellp().seekpos());
	file.seekg(0, std::ios::beg);
	file.read(&vec[0], vec.size());
	file.close();
	file.open(outputfile, std::ios::out | std::ios::binary);
	std::transform(vec.begin(), vec.end(), vec.begin(), encode ? EnCodChar : CodChar);
	file.write(&vec[0], vec.size());
}


int main() {
	foo("d:\\input.txt", "d:\\output.txt");//Шифруем
	foo("d:\\output.txt", "d:\\decod.txt", true);//Дешифруем
	return 0;
}
