#pragma once
#include <string>

typedef enum{
	Type,
	arithmeticOp,
	booleanOp,
} nodeType;




class ASTnode{
	std::string lexeme;
	nodeType type;
	ASTnode** children;
	

};
