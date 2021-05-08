#include "FSA.h"
#include <iostream>


int main(){
    auto node1 = create(false, {'a', 'b', 'c'});
    auto node2 = create(false, {'e', 'a', 'd'});
    node2->add_node(create(true, {'t', 'e', 'f'}));
    node1->add_node(node2);
    auto machine = Fsa_graph(node1);
    std::string cat = "ade";
    std::cout << machine.valid_string(cat);
    

}