#include "parser.h"

void Parser::ParseGraphFromDot(std::ifstream& in, IGraph& graph) {
  std::string line;

  while (std::getline(in, line) && line != "}") {
    // line = removeSpaces(line);
    int pos = 0;
    std::stringstream s(line);

    // for (size_t i = 0; i != line.size(); ++i) {
    //   if (line[i] == '-' || line[i] == '[') {
    //     std::string v = line.substr(pos, i - pos);
    //     graph.AddVertex(v);
    //     pos = i + 2;

    //   } else if ((pos = line.find("label=")) != std::string::npos) {
    //     std::string v = line.substr(pos, i - pos);
    //   }
    // }
  }
}

void Parser::WriteGraphToDot(std::ofstream& out, const IGraph& graph) {}

std::string Parser::removeSpaces(const std::string& str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(c)) {
      result += c;
    }
  }
  return result;
}

// int pos_weight = line.find("label");
// adjacency_list_[vertexes[from]].push_back(vertexes[to], weight);
// std::cout << v1 << adjacency_list_[v1] << std::endl;
// }