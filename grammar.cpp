#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <assert.h>
#include "ast.h"

std::vector<std::string> keywords;



std::vector<std::string> getKeywords()
{
	std::vector<std::string> ret;
	std::fstream in_file {"./grammar.txt", std::ios::in};
	assert(in_file);
	std::string temp;
	getline(in_file,temp);
	while(getline(in_file,temp))
	{
//		std::cout << temp << std::endl;	
		temp.erase(temp.size()-2, temp.size()-1);
		ret.push_back(temp);	
		
	}

	return ret;
}	


bool isValid(std::string lexeme)
{
	for(auto x: keywords)
	{
		if(x == lexeme)
			return true;
	}
	return false;
}

void REPL()
{
	while(true)
	{
		std::string line;
		std::cout << "Mlang>>  ";
		std::cin >> line;
		if(line == "q")
			return;
		if(isValid(line))
		{
			std::cout << line << " Keyword" << std::endl;
		}
		else
	       	{
			std::cout << "invalid keyword"  << std::endl;
		}
	}
}
		
int main()
{
	keywords = getKeywords();
	REPL();
		
	return 0;
}





