#pragma once
#include "stdafx.h"
#include "User.h"

class Policy_User
{
public:
	Policy_User(void);
	
	~Policy_User(void);
private:
	map<string,vector<string>> list_Policy;
};

