#include <iostream>
#include "FSA.h"
#include <vector>


int main()
{
	std::vector<char> placeholder;
	placeholder.push_back('a');
	placeholder.push_back('c');
	fsaNode test(false, placeholder);
	fsaNode added(true, placeholder);
	test.addNode(&added);
	test.addNode(&added);
	
	for(auto x: test.links)
	{
		std::cout << x->acceptState << std::endl;
	}
}	
