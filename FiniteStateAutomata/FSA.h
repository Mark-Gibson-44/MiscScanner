#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

class Fsa_node{
	bool accepting;
	bool traversed;

	std::vector<Fsa_node*> neighbours;

	std::vector<char> characters;

public:
	Fsa_node(bool accept, std::vector<char> valids) : accepting(accept), characters(valids) {}
	
	void add_node(Fsa_node* n){ neighbours.push_back(n);}
	
	bool valid_state(char transition){
		auto found = std::find(characters.begin(), characters.end(), transition);
		return found != characters.end();
	}

	Fsa_node* transition(char next_state){
		for(auto ptr: neighbours){
			if(ptr->valid_state(next_state))
				return ptr;
		}
		return nullptr;
	}
	bool get_accept(){ return accepting; }
};

Fsa_node* create(bool a, std::vector<char> b){
	return new Fsa_node(a, b);
}


class Fsa_graph{
	Fsa_node* start;
	
	
	
public:
	Fsa_graph(Fsa_node* graph) : start(graph) {}
	bool valid_string(std::string s)
	{	
		
		auto traversal = start;
		auto charptr = 0;
		bool ret = traversal->valid_state(s[charptr]);
		while(traversal->valid_state(s[charptr]) && traversal != nullptr)
		{
			//std::cout << traversal->valid_state(s[charptr]);
			if(charptr == s.size() - 1)
				return traversal->get_accept();
			charptr++;
			traversal = traversal->transition(s[charptr]);
			
		}
		return false;
	}
};


