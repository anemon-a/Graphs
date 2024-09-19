#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>
#include <iostream>
#include <map>
#include <vector>

class Parser {
 public:
  Parser() : count_vertexes_(0) {};
  void ParseGraphFromFile(const std::string& filename);
  // void WriteGraphToFile(const std::string* filename);

 private:
  std::string removeSpaces(const std::string& str);
  void LoadGraph(std::ifstream& in);
  //   void addEdge()
  int count_vertexes_;
  int type_graph_;
  std::vector<std::pair<int, int>> adjacency_list_;
};

#endif  // PARSER_H_
