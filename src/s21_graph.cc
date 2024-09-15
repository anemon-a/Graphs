#include "s21_graph.h"

std::string removeSpaces(const std::string& str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(c)) {
      result += c;
    }
  }
  return result;
}

void Graph::LoadDigraph(std::ifstream& in) {
  std::string line;
  std::map<std::string, int> vertexes;
  while (std::getline(in, line) && line != "}") {
    line = removeSpaces(line);
    int pos = line.find("->");
    if (pos != std::string::npos) {
        }
  }
}

void Graph::LoadGraphFromFile(std::string filename) {
  std::string line;

  std::ifstream in(filename);
  if (in.is_open()) {
    while (std::getline(in, line)) {
      if (line.find("digraph") != std::string::npos) {
        LoadDigraph(in);
      } else if (line.find("graph") != std::string::npos) {
        LoadGraph(in);
      }
    }
  }
  in.close();
}

void Graph::ExportGraphToDot(std::string filename) {}