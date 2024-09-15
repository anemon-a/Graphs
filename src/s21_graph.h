#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class Graph {
 public:
  void LoadGraphFromFile(std::string filename);
  void ExportGraphToDot(std::string filename);

 private:
  void LoadDigraph(std::ifstream& in);
  void LoadGraph(std::ifstream& in);
  size_t rows_ = 0;
  size_t cols_ = 0;
  int type_graph_;
  std::vector<std::vector<int>> matrix_;
};

#endif  // S21_GRAPH_H_