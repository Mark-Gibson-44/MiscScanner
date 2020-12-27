#pragma once
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <fstream>

class Grammar
{
	std::vector<std::regex> fullGrammar;
	public:
	/**
	 * Constructor should only be called once, here it reads in the BNF
	 * And creates a list of all valid sentences within language
	 */
	Grammar()
	{
		std::fstream f;
		f.open("Spec.txt");
		std::string t;
		while(std::getline(f,t))
		{
			

			std::regex l(t);
			fullGrammar.push_back(l);
		}
		
	}		
	bool inGrammar(std::string code)
	{
	
		std::cout << std::regex_match(code, fullGrammar[0]) << std::endl;
		return true;
	}

};
