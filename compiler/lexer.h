#pragma once
#include <fstream>

class lexer
{
	bool begin = false;
	char prevChar;
	char current;
	std::string curLexeme;
	void read()
	{
		current = //grab next character
		processChar(current)// will only do something if char = { or ; currently
		if(!begin)//if begin is false prevChar doesn't exist
		{
			
			prevChar = current;
		}
		//Read first character -> process character
	}
	//reads from after an openning brace
	//returns true if there is a corresponding closing brace
	//if another opening brace appears recursively calls the function
	//takes a pointer to a position in a file?
	bool closingBrace()
	{
		char next;
		if(next == '{')//just recursively go through the file for now
			closeBrace();
		if(next == '}')
			return true;
	}

	void processChar(char c)
	{
		switch(c)
		{
			case ';':
				processLexeme(curLexeme);
				curLexeme = ""; //reset currentLexeme
				break;
			case '{':
				closingBrace();
				break;
			case '+':
			case '-':
			case '/':
			case '*':
				evalOp(); //indicates a mathematical operation (if concat isnt allowed) have function that checks theres a value after
				break;
		}

	}
	//probably takes another pointer to a point in a file
	//reads up until a ;
	void finishLexeme()
	{
		char pos;
		while(pos != ';')
		{
			curLexeme += pos;
			pos = getChar();
		}
		
	}
	//Run through the current string
	//check that its either TYPE var1 operator
	//then peek ahead to the next character up until a ;
	//return true if all is as should be
	bool evalOp()//decompose the current string and make sure it is a valid expression
	{
		finishLexeme();//finishes the lexeme providing all the information to check if the expr is valid
		//probably use the AST here
			
	}

};
