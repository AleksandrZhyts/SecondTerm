#include "stdafx.h"

using namespace std;

bool parse_string(string& math_expr)
{
	string out_str = "";
	char   temp;

	bool flag = false;
	int i = 0,
		j = 0;

	if (math_expr.at(0) == '-') math_expr.insert(0, 1, '0');
	
	while (i < math_expr.length() && !flag)
	{
		if (math_expr.at(i) == '(')
		{
			out_str.append(1, math_expr.at(i));
			math_expr.erase(i, 1);
			if (math_expr.at(i) == '-') math_expr.insert(i++, 1, '0');
			j++;
		}
		else if (math_expr.at(i) == ')')
		{
			math_expr.erase(i, 1);
			while (j > 0 && out_str.at(j - 1) != '(')
			{
				math_expr.insert(i++, 1, out_str.at(--j));
				out_str.erase(j, 1);
			}
			out_str.erase(--j, 1);
		}
		else if (math_expr.at(i) == '*' || math_expr.at(i) == '/')
		{
			if (j > 0 && (out_str.at(j - 1) == '*' || out_str.at(j - 1) == '/' || out_str.at(j - 1) == '^'))
			{
				temp = out_str.at(j - 1);
				out_str.replace(j - 1, 1, 1, math_expr.at(i));
				math_expr.replace(i++, 1, 1, temp);
			}
			else
			{
				out_str.append(1, math_expr.at(i));
				math_expr.replace(i++, 1, 1, ',');
				j++;
			}
		}
		else if (math_expr.at(i) == '+' || math_expr.at(i) == '-' || math_expr.at(i) == '^')
		{
			if (j == 0 || out_str.at(j - 1) == '(' || math_expr.at(i) == '^')
			{
				out_str.append(1, math_expr.at(i));
				math_expr.replace(i++, 1, 1, ',');
				j++;
			}
			else
			{
				temp = math_expr.at(i);
				math_expr.erase(i, 1);
				while ((j > 0) && (out_str.at(j - 1) != '('))
				{
					math_expr.insert(i++, 1, out_str.at(--j));
					out_str.erase(j, 1);
				}
				out_str.append(1, temp);
				j++;
			}
		}
		else if ((int)math_expr.at(i) > 47 && (int)math_expr.at(i) < 58 || (int)math_expr.at(i) == 46) i++;
		else flag = true;
	}
	if (!flag)
	{
		while (j > 0) math_expr.append(1, out_str.at(--j));
		return !flag;
	}
	else return false;
}

int main()
{
	string math_expr;
	cout << "\nEnter mathematical expression : \n";
	cin >> math_expr;
	
	//string math_expr = "(8+2*5)/(1+3*2-4)";//"(9+2.4*5)/(-4+1*2/2)";//"3+4*2/(1-5)^2";//"-4+3";
	
	if (!parse_string(math_expr))
	{
		cout << "\nError in mathematical expresion\n";
		return 0;
	}

	bool flag = false;
	
	int i = 0,
		index = 0;
	
	vector <double> steck;
	steck.reserve(50);
	
	float operand1 = 0,
		  operand2 = 0;

	while (i < math_expr.length() && !flag)
	{
		if ((int)math_expr.at(i) > 47 && (int)math_expr.at(i) < 58 || (int)math_expr.at(i) == 46)
		{
			index = i;
			while (i < math_expr.length() && (int)math_expr.at(i) > 47 && (int)math_expr.at(i) < 58 || (int)math_expr.at(i) == 46)
			{
				i++;
			}
			steck.push_back(atof(math_expr.substr(index, i).c_str()));
		}
		if (math_expr.at(i) == ',') i++;
		
		switch (math_expr.at(i))
		{
			case '+':
					{
						operand1 = steck.at(steck.size() - 2);
						operand2 = steck.at(steck.size() - 1);
						steck.pop_back();
						steck.pop_back();
						steck.push_back(operand1 + operand2);
						i++;
						break;
					}
			case '-':
					{
						operand1 = steck.at(steck.size() - 2);
						operand2 = steck.at(steck.size() - 1);
						steck.pop_back();
						steck.pop_back();
						steck.push_back(operand1 - operand2);
						i++;
						break;
					}
			case '*':
					{
						operand1 = steck.at(steck.size() - 2);
						operand2 = steck.at(steck.size() - 1);
						steck.pop_back();
						steck.pop_back();
						steck.push_back(operand1 * operand2);
						i++;
						break;
					}
			case '/':
					{
						operand1 = steck.at(steck.size() - 2);
						operand2 = steck.at(steck.size() - 1);
						if (operand2) 
						{
							steck.pop_back();
							steck.pop_back();
							steck.push_back(operand1 / operand2);
							i++;
						}
						else
						{
							flag = true;
							cout << "\nDivision by 0\n";
						}
						break;
					}
			case '^':
					{
						operand1 = steck.at(steck.size() - 2);
						operand2 = steck.at(steck.size() - 1);
						steck.pop_back();
						steck.pop_back();
						steck.push_back(pow(operand1,operand2));
						i++;
						break;
					}
			default:
				break;
		}
	}

	if (!flag) cout << "\nResult = " << steck.at(0) << endl;
	
	system("pause");
	return 0;
}

