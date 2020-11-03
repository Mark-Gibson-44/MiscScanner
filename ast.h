#pragma once
#include <string>
#include <vector>
#include <iostream>


std::string nodeTypes[] = {"TypeDecl", "ArithOp", "BoolOp"};

std::string chars[][4] = {{"int", "char", "bool"}, {"+","-", "/", "*"}, {"&&", "||"}};

int t(std::string l)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j=0; j < 4; j++)
		{
			if(l == chars[i][j])
				return i;
		}
	}
	return -1;
}


class ASTnode{
	std::string lexeme;
	int type;
	std::vector<ASTnode*> children;
	
	public:
	
       	void consume()
	{
		//read up until whitespace
		//set it as lexeme
		std::cin >> lexeme;
		type = t(lexeme);
		std::cout << lexeme << " is type " << nodeTypes[type] << std::endl;
	}


};
