#include "parser.h"

void Parser::LoadDigraph(std::ifstream& in) {
  std::string line;
  std::map<std::string, int> vertexes;
  while (std::getline(in, line) && line != "}") {
    line = removeSpaces(line);
    int pos = 0;
    if ((pos = line.find("->")) != std::string::npos) {
      std::string from = line.substr(0, pos);
      std::string to = line.substr(pos + 2);
      adjacency_list_[from].push_back(to);
        // std::cout << v1 << adjacency_list_[v1] << std::endl;
    }
  }
}

void Parser::LoadGraph(std::ifstream& in) {
    
}
  

void Parser::ParseGraphFromFile(const std::string& filename) {
  std::string line;
  std::ifstream in(filename);

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }

  while (std::getline(in, line)) {
      if (line.find("digraph") != std::string::npos) {
        LoadDigraph(in);
      } else if (line.find("graph") != std::string::npos) {
        LoadGraph(in);
      }
    }
  in.close();
}

void Paresr::WriteGraphToDot(const std::string* filename) {

}

std::string Parser::removeSpaces(const std::string& str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(c)) {
      result += c;
    }
  }
  return result;
}
