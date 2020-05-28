#include<memory>
#include<list>
#include<array>

#define SIZE 26

class Trie{

 public:	
  /**
   * constructor
   */ 
  Trie();

  /**
   * @brief for adding word to trie
   * 
   * @param word data to be added
   * 
   * @return 0 for success 1 for failure
   */ 
  int addData(std::string word);

  /**
   * @brief for deletion of word in trie
   * 
   * @param word word to be added
   * 
   * @return 0 for success 1 for failure
   */ 
  int deleteData(std::string data);

  /**
   * @brief to search word for passed keyword
   * 
   * @param keyword
   * 
   * @return 0 for success 1 for failure
   */ 
  int searchData(std::string keyword) const;

  /**
   * @brief get all suggestion trailing with passed keyword
   * 
   * @param keyword
   * 
   * @return list of suggestions
   */ 
  std::list<std::string> getAllSuggestions(std::string keyword) const;
 
 private:

  struct Node{
    std::array<std::unique_ptr<Node>,26> child; 
    bool endOfWord = false;
  };
	std::unique_ptr<Node> root;

  /**
   * @brief utility function for getting all suggestions
   * recursively called for all suggestions
   * 
   * @param keyword
   * @param cur_node pointer to trie node
   * 
   * @return list of all suggestion from their child node
   */
  std::list<std::string> suggestionsUtil(
    std::string keyword,
    std::unique_ptr<Node>::pointer cur_node
  ) 
  const;
};