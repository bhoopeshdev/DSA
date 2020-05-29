#include <iostream>

#include "trie.h"

Trie::Trie(){
  root = std::unique_ptr<Node>(new Node());
  root->endOfWord = false;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////

int Trie::addData(std::string keyword) {
  if(keyword.length() == 0)
    return 1;
  auto crawl = root.get();
  for(char c : keyword){
    if(
      crawl->child.at(static_cast<unsigned int>(c - 'a')) ==
      std::unique_ptr<Node>(nullptr)
    ){
      crawl->child[static_cast<unsigned int>(c - 'a')] =
        std::unique_ptr<Node>(new Node());
    }
    crawl = crawl->child.at(static_cast<unsigned int>(c - 'a')).get();
  }
  crawl->endOfWord = true;
  std::cout<<keyword<<" added"<<std::endl;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////

int Trie::searchData(std::string keyword) const{
  auto crawl = root.get();
  for(auto c : keyword){
    if(
      crawl->child.at(static_cast<unsigned int>(c - 'a')) ==
      std::unique_ptr<Node>(nullptr)
    ){
      return 1;
    }
    crawl = crawl->child.at(static_cast<unsigned int>(c - 'a')).get();
  }
  if(!crawl->endOfWord)
    return 1;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////

int Trie::deleteData(std::string keyword){
  auto crawl = root.get();
  for(auto c : keyword){
    if(
      crawl->child.at(static_cast<unsigned int>(c - 'a')) ==
      std::unique_ptr<Node>(nullptr)
    ){
      return 1;
    }
    crawl = crawl->child.at(static_cast<unsigned int>(c - 'a')).get();
  }
  if(!crawl->endOfWord){
    return 1;
  }
  crawl->endOfWord = false;
  std::cout<<keyword<<" deleted"<<std::endl;
  return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////

std::list<std::string> Trie::getAllSuggestions(std::string keyword) const{
  auto crawl = root.get();
  for(auto c : keyword){
    if(
      crawl->child.at(static_cast<unsigned int>(c - 'a')) == 
      std::unique_ptr<Node>(nullptr)
    ){
      return std::list<std::string>();
    }
    crawl = crawl->child.at(static_cast<unsigned int>(c - 'a')).get();
  }

  return suggestionsUtil(keyword,crawl);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////

std::list<std::string> Trie::suggestionsUtil(
    std::string keyword,
    std::unique_ptr<Node>::pointer cur_node
) const 
{
  std::list<std::string> results;
  if(cur_node->endOfWord)
    results.push_back(keyword);

  for(int ind = 0; ind < cur_node->child.size();ind++){
    if(cur_node->child.at(ind) != std::unique_ptr<Node>(nullptr)){
      
      results.splice(
        results.end(),
        suggestionsUtil(
          keyword+static_cast<char>(ind + 'a'),
          cur_node->child.at(ind).get()
        )
      );
    
    }
  }  
  return results;
} 

///////////////////////////////////////////////////////////////////////////////////////////////////
/////                                                                                         /////
///////////////////////////////////////////////////////////////////////////////////////////////////
