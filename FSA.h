#pragma once
#include <vector>
#include <iostream>

class fsaNode{
	
	//List of characters for a given state
	std::vector<char> characters;
	public:
	//Is the node an Accepting state or not
	bool acceptState;
	//Links to connecting states
	std::vector<fsaNode*> links;
	//Creation of object with relevant params
	fsaNode(bool accept, std::vector<char>  elements)
	{
		acceptState = accept;
		characters = elements;
	}
	//adds a node to this
	void addNode(fsaNode *link){
		links.push_back(link);
	}
	//for a node prints out its characters
	void printChars()
	{
		for(auto x : characters)
		{
			std::cout << x << std::endl;
		}
	}
	//Iterates over a node and their children printing out its contents
	//TODO Have a check if nodes loop
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
	//TODO
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
	//TODO
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

