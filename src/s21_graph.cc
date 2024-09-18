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
  int count_vertexes = 0;
  while (std::getline(in, line) && line != "}") {
    line = removeSpaces(line);
    int start = 0, pos = 0;
    while ((pos = line.find("->", start)) != std::string::npos) {
      std::string v1 = line.substr(start, pos - start);
      if (!vertexes.count(v1)) {
        vertexes[v1] = count_vertexes++;
        std::cout << v1 << vertexes[v1] << std::endl;
      }
      start = pos + 2;
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
        // LoadGraph(in);
      }
    }
  }
  in.close();
}

void Graph::ExportGraphToDot(std::string filename) {}