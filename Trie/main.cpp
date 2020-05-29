#include <iostream>

#include "trie.h"

int main(){
	Trie trie;
	std::string name = "bhoopesh";
	trie.addData(name);
	if(!trie.searchData(name)){
		std::cout<<name<<" is found"<<std::endl;
	}
	else{
		std::cout<<name<<" is not found"<<std::endl;
	}
	trie.addData(name+"dew");
	
	std::cout<<"suggestions for "<<name<<std::endl;
	for(auto sug : trie.getAllSuggestions(name)){
		std::cout<<sug<<std::endl;
	}
	
	trie.deleteData(name);

	if(!trie.searchData(name)){
		std::cout<<name<<" is found"<<std::endl;
	}
	else{
		std::cout<<name<<" is not found"<<std::endl;
	}

	std::cout<<"suggestions for "<<name<<std::endl;
	for(auto sug : trie.getAllSuggestions(name)){
		std::cout<<sug<<std::endl;
	}
	return 0;
}