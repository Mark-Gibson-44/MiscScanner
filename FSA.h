#pragma once
#include <vector>
#include <iostream>

class fsaNode{
	
	
	std::vector<char> characters;
	public:

	bool acceptState;
	std::vector<fsaNode*> links;
	fsaNode(bool accept, std::vector<char>  elements)
	{
		acceptState = accept;
		characters = elements;
	}
	void addNode(fsaNode *link){
		links.push_back(link);
	}
	void printChars()
	{
		for(auto x : characters)
		{
			std::cout << x << std::endl;
		}
	}
	void traverse(fsaNode *start)
	{
		std::cout << "NEW Node" << std::endl;
		if(!start->links.size())
			std::cout << "empty" << std::endl;
		for(int i = 0; i < start->links.size(); i++)
		{
			start->links[i]->printChars();
			traverse(start->links[i]);
		}

			
	}
	bool Valid(char a, int distance, fsaNode *start)
	{
		//traverse to node X
		//then check the characters within that state
		for(int o = 0; o < start->links.size(); o++)
		{
			//if(node->links[i] == a)
			//{
				return true;
			//}
		}
		return false;
	}
	bool validString(std::string lexeme)
	{
		for(int i = 0; i < lexeme.size(); i++)
		{
			//Check if character fits into StateMachine
			//Takes character and posistion
		}
		return false;
	}
};

