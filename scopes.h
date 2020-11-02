#pragma once
#include <vector>//Everyones favourite datastructure
#include <string>
#include <iostream>
#define GLOBAL nullptr

//temp struct for testing
typedef struct{
	std::string name;//variable name
	//Type type;//type for semantic analysis
	bool init;//is the variable initialised
}variable;


/**
 * Scope used to identify variables within a pair or braces
 */
class Scope
{
	public:
	std::vector<variable> vars;
	Scope* outer;//Outer scope to identify if a variable declared outside the current scope exists
	Scope(Scope* o = GLOBAL)
	{
		outer = o;
	}
	void consumeVar(variable a)
	{
		vars.push_back(a);
	}
	void dumpVars()
	{
		
		for(auto i: vars)
		{
			std::cout << "Variable " << i.name << std::endl;
		}
		if(outer == GLOBAL)
			return;
		outer->dumpVars();
		
	}
	bool exists(Scope* o,std::string varName)
	{
		for(int i = 0; i < vars.size(); i++)
		{
			if(varName == vars[i].name)
				return true;
		}
		if(o != GLOBAL)
			exists(outer,varName);
	return false;
	}

	//TODO make function that returns a variables type allowing for semantic analysis when evaluating type operations
	
};
