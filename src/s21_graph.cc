#include "s21_graph.h"

#include "parser.h"

int Graph::GetVertex(std::string vertex) const { return vertexes_.at(vertex); }

int Graph::GetEdgeWeight(int vertex_from, int vertex_to) const {
  return adjacency_matrix_[vertex_from][vertex_to];
}

void Graph::AddVertex(std::string vertex) {
  if (!vertexes_.count(vertex)) {
    vertexes_[vertex] = count_vertexes_++;
    std::cout << vertex << ' ' << vertexes_[vertex] << std::endl;
  }
}

void Graph::AddEdge(int vertex_from, int vertex_to, int weight) {
  // adjacency_matrix_[vertex_from][vertex_to];
}

void Graph::LoadGraphFromFile(std::string filename) {
  Parser parser;
  std::ifstream in(filename);

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }
  Graph graph;
  parser.ParseGraphFromDot(in, graph);
  in.close();
}

void Graph::ExportGraphToDot(std::string filename) {}
