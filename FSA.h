#pragma once
#include <vector>


class fsaNode{
	bool acceptState;
	std::vector<fsaNode*> links;
	std::vector<char> state;

	fsaNode(bool accept, std::vector<char>  elements)
	{
		acceptState = accept;
		state = elements;
	}
	void addNode(fsaNode *link){
		links.push_back(link);
	}
};

