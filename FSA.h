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
	fsaNode* Valid(char a, fsaNode *node)
	{
		//Looks through all of a nodes neighbouring nodes characters
		//returns a pointer to the node with the character desired
		//else return nullptr
		for(int i=0; i < node->links.size();i++)
		{
			for(auto x: node->links[i]->characters)
			{
				if(x == a)
					return node.links[i];
			}
		}
		return nullptr;
	}
	//TODO
	bool validString(std::string lexeme, fsaNode &node)
	{
		//constantly traverses the string passing in the starting node
		//TODO implement some sort of error state;
		//if it doesnt end up in the error state return true else return false
		int iter = 0;
		return true;
	}
};

