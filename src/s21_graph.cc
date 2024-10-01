#include "s21_graph.h"

void Graph::LoadGraphFromFile(std::string filename) {
  // Parser parser;
  std::ifstream in(filename);
  std::string line;

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }

  while (std::getline(in, line) && line != "}") {
    size_t pos = 0;
    if (line.find("digraph") != std::string::npos) {
      SetGraphType(IGraph::GraphType::DIGRAPH);
    } else if (line.find("graph") != std::string::npos) {
      SetGraphType(IGraph::GraphType::GRAPH);
    }
    if (((pos = line.find("->")) != std::string::npos) ||
        ((pos = line.find("--")) != std::string::npos)) {
      std::string v1, v2, sep, label;
      int weight = 1;
      std::stringstream ss(line);

      ss >> v1 >> sep >> v2 >> label;
      int v_from = stoi(v1);
      int v_to = stoi(v2);  // тут может исключенее ебануть, нужно обрабботать

      if ((pos = label.find("label=")) != std::string::npos) {
        weight = std::stoi(label.substr(label.find('=') + 2));
      }
      AddEdge(v_from, v_to, weight);
    }
  }
  in.close();
}

// void Graph::ExportGraphToDot(std::string filename) {}

int Graph::GetVertexIndex(int vertex) const { return vertex_index_.at(vertex); }

const std::vector<std::vector<int>>& Graph::GetAdjacencyMatrix() const {
  return adjacency_matrix_;
}

int Graph::GetEdgeWeight(int vertex_from, int vertex_to) const {
  return adjacency_matrix_[vertex_from][vertex_to];
}

size_t Graph::GetVertexCount() const { return vertex_count_; }

void Graph::AddVertex(int vertex) {
  if (!vertex_index_.count(vertex)) {
    vertex_index_[vertex] = vertex_count_++;
    std::vector<int> v(vertex_count_, 0);
    adjacency_matrix_.push_back(v);
    for (size_t i = 0; i != vertex_count_ - 1; ++i) {
      adjacency_matrix_[i].push_back(0);
    }
  }
}

void Graph::AddEdge(int vertex_from, int vertex_to, int weight) {
  AddVertex(vertex_from);
  AddVertex(vertex_to);
  adjacency_matrix_[GetVertexIndex(vertex_from)][GetVertexIndex(vertex_to)] =
      weight;
  if (graph_type_ == GraphType::GRAPH) {
    adjacency_matrix_[GetVertexIndex(vertex_to)][GetVertexIndex(vertex_from)] =
        weight;
  }
}

void Graph::SetGraphType(GraphType type) { graph_type_ = type; }

void Graph::PrintGraph() const {
  for (size_t i = 0; i != vertex_count_; ++i) {
    for (size_t j = 0; j != vertex_count_; ++j) {
      std::cout << adjacency_matrix_[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

const std::vector<int> Graph::GetNeighbourVertices(int vertex) const {
  int vertex_index = GetVertexIndex(vertex);
  std::vector<int> neighbours;
  for (const auto& [vertex, index] : vertex_index_) {
    if (GetEdgeWeight(vertex_index, index)) {
      neighbours.push_back(vertex);
    }
  }
  return neighbours;
}
