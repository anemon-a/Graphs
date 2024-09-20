#ifndef S21_GRAPH_H_
#define S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class IGraph {
 public:
    virtual int GetVertex(std::string vertex) const = 0;
  virtual void AddVertex(std::string vertex) = 0;
  virtual int GetEdgeWeight(int vertex_from, int vertex_to) const = 0;
  virtual void AddEdge(int vertex_from, int vertex_to, int weight) = 0;
};

class Graph : IGraph {
 public:
  Graph() : count_vertexes_(0) {};
  void LoadGraphFromFile(std::string filename);
  void ExportGraphToDot(std::string filename);

  int GetVertex(std::string vertex) const override;
  void AddVertex(std::string vertex) override;
  int GetEdgeWeight(int vertex_from, int vertex_to) const override;
  void AddEdge(int vertex_from, int vertex_to, int weight) override;

 private:
  int count_vertexes_;
  std::map<std::string, int> vertexes_;
  std::vector<std::vector<int>> adjacency_matrix_;
};

#endif  // S21_GRAPH_H_
