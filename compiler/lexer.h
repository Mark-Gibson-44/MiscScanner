#pragma once

#include <iostream>
#include <fstream>

class lexer
{
	std::fstream f;
	bool begin = false;
	char prevChar;
	char current;
	std::string curLexeme;
	//std::vector<lexeme>
	public:
	void read()
	{
		
		f.open("./test.txt");
		while(f.get(current)){
		//grab next character
		curLexeme += current;
		processChar(current);// will only do something if char = { or ; currently
		
		if(!begin)//if begin is false prevChar doesn't exist
		{
			
			prevChar = current;
		}
		//Read first character -> process character
		}
	}

	//reads from after an openning brace
	//Will be responsible for scope management to some extent, could potentially be used in semantic segmentation rather than 
	//lexing
	//if another opening brace appears recursively calls the function
	//takes a pointer to a position in a file?
	void closingBrace(std::fstream &b)
	{
		std::string innerLex;
		while(b.get(current))
		{
			
			curLexeme += current;
			innerLex += current;
			if(current == '{')//just recursively go through the file for now
				closingBrace(b);
			if(current == '}')
			{
				std::cout << innerLex << std::endl;
				return;
			}
		}

	}
	//Just processes special characters
	void processChar(char c)
	{
		switch(c)
		{
			case ';'://stmt endings
				processLexeme();
				curLexeme = ""; //reset currentLexeme
				break;
			case '{'://scope initialising
				closingBrace(f);
				break;
			case '+'://arithmetic operations
			case '-':
			case '/':
			case '*':
							
				finishLexeme(f); //indicates a mathematical operation (if concat isnt allowed) have function that checks theres a value after
				break;
		}

	}
	//Uses a grammar of lexemes to deteremine if the current is valid
	//Will have to generate a grammar.h to generate valid strings
	bool validLexeme()
	{
	//
	//
		return true;
		
	}
	//Error checking of the current lexeme;
	
	void processLexeme()
	{
		std::cout << curLexeme;
		if(!validLexeme())
			std::cerr << "Invalid Lexeme" << std::endl;
		
	}
	//Run through the current string
	//check that its either TYPE var1 operator
	//then peek ahead to the next character up until a ;
	
	void finishLexeme(std::fstream& b)
	{	
		
		while(b.get(current))
		{
		curLexeme += current;
		
			if(current == ';')
				break;
		}	
		
	}

};
