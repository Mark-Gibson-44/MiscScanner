#include <iostream>
#include "FSA.h"
#include <vector>


int main()
{
	std::vector<char> placeholder;
	placeholder.push_back('a');
	placeholder.push_back('c');
	
	fsaNode test(false, placeholder);
	placeholder.push_back('L');
	fsaNode added(true, placeholder);
	fsaNode deep(false, placeholder);
	
	test.addNode(&added);
	added.addNode(&deep);
	test.traverse(&test);
	std::string a = "ax";
	std::cout <<test.validString(a, test) << std::endl; 
}	
