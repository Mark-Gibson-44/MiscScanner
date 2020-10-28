#pragma once
#include <vector>


class fsaNode{
	
	
	std::vector<char> state;
	public:

	bool acceptState;
	std::vector<fsaNode*> links;
	fsaNode(bool accept, std::vector<char>  elements)
	{
		acceptState = accept;
		state = elements;
	}
	void addNode(fsaNode *link){
		links.push_back(link);
	}
};

