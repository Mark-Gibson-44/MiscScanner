#pragma once
#include <vector>
#include <string>
class Type
{
	public:
	//used to identify the type name (int, char...)
		std::string name;
	//list of regex used to indicate what are valid literals of the type
	//int: (1-9)*(0-9)
	//bool: true | false
	std::vector<std::string> validDefinition;
	//size in bytes of the type (char 1 byte...)
	int size;
	//List of characters that can perform legal operations on the type
	//EG: allowing int - int but not allowing char - char
	std::vector<char> operators;

	int sizeOf()
	{
		return size;
	}
	bool legalOp(char op)
	{
		for(auto a: operators)
		{
			if(a == op)
				return true;
		}
		return false;
	}
	std::string getTypeName()
	{
		return name;
	}
};

class integer : public Type
{
	public:
	integer()
	{
		name = "int";
		size = 4;
		operators = {'+', '/', '*', '-', '^'};
	}

};
class boolean : public Type
{
	boolean()
	{
		name = "boolean";
		size = 1;
		operators = {'|', '&', '>', '<'};
	}
};

