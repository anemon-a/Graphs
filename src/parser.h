#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "s21_graph.h"

class Parser {
 public:
  Parser() : count_vertexes_(0) {};
  void ParseGraphFromDot(std::ifstream& in, IGraph& graph);
  void WriteGraphToDot(std::ofstream& out, const IGraph& graph);

 private:
  std::string removeSpaces(const std::string& str);
  int count_vertexes_;
  int type_graph_;
};

#endif  // PARSER_H_
