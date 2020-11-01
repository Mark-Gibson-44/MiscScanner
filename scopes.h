#pragma once
#include <vector>//Everyones favourite datastructure
#include <string>


//temp struct for testing
typedef struct{
	std::string name;//variable name
	Type type;//type for semantic analysis
	bool init//is the variable initialised
}variable;


/**
 * Scope used to identify variables within a pair or braces
 */
class Scope
{
	
	std::vector<variable> vars;

	Scope()
	{

	}
	//TODO make function that returns a variables type allowing for semantic analysis when evaluating type operations
	
};
