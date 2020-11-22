#pragma once
#include <vector>
#include <iostream>

class semantics{


	//Strings of lexemes that need semanticly checking
	std::vector<std::string> l;

	//TODO needs typeChecking
	//Needs decl checking
	//scope checking
	//

	//INITS lexemes generated from lexer  (Which should probably be called parser
	semantics(std::string parsed)
	{
		l = parsed;
	}
	void evalInit(std::string a)
	{
		//find first space which would separeate type from the var declr
		int pos = a.find(' ') + 1;
		std::string temp = a.substr(pos, a.end()-1);



	}	
	void eval(std::string a)
	{
		switch(a)
		{
			//suggests the declaraction of variable
			case(a.find("integer")):
			case(a.find("boolean")):
				
				evalInit(a); break;
			default: 
				//if the lexeme doesn't start with a type it should be 
				//an operation/definition on an already declared variable. 
				evalVarOp(a); break;
		}
						
				
	}

	void evalWords()
	{
		for(auto &a: l)
		{
			eval(a);
		}
	}

};
