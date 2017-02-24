#include "stdafx.h"
//#include "encryption.h"

bool encryption::encoding(const string _inString, string _outString) { return 0; }
bool encryption::decoding(const string _inString, string _outString) { return 0; }
string encryption::hash(const string _in)
{
	_inString = _in;
	Hash _hash;
	_outString = _hash.getHash(_inString);
	return _outString;
}
bool encryption::check_hash(const string _inString)
{

	return false;
}