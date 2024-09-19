#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Graph {
 public:
  Graph() : count_vertexes_(0) {};
  void LoadGraphFromFile(std::string filename);
  void ExportGraphToDot(std::string filename);

 private:
  int count_vertexes_;
  std::vector<std::vector<int>> adjacency_matrix_;
};

#endif  // S21_GRAPH_H_
