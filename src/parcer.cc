#include "parser.h"

// void Parser::LoadGraph(std::ifstream& in) {
//   std::string line;
//   std::map<std::string, int> vertexes;
//   while (std::getline(in, line) && line != "}") {
//     line = removeSpaces(line);
//     int pos = 0;
//     if ((pos = line.find("->")) != std::string::npos) {
//       std::string from = line.substr(0, pos);
//       // std::string to = line.substr(pos + 2);
//       if (!vertexes.count(from)) {
//         vertexes[from] = count_vertexes_++;
//       }
//       int pos_weight = line.find("label");
//       // adjacency_list_[vertexes[from]].push_back(vertexes[to], weight);
//       // std::cout << v1 << adjacency_list_[v1] << std::endl;
//     }
//   }
// }

void Parser::LoadGraph(std::ifstream& in) {}

void Parser::ParseGraphFromFile(const std::string& filename) {
  std::string line;
  std::ifstream in(filename);

  if (!in.is_open()) {
    throw std::runtime_error("Could not open the file.");
  }

  std::map<std::string, int> vertexes;
  while (std::getline(in, line) && line != "}") {
    line = removeSpaces(line);
    int pos = 0;
    for (size_t i = 0; i != line.size(); ++i) {
      if (line[i] == '-' || line[i] == '[') {
        std::string v = line.substr(pos, i - pos);
        if (!vertexes.count(v)) {
          vertexes[v] = count_vertexes_++;
        }
        pos = i + 2;
        // std::cout << v << vertexes[v] << std::endl;
      } else if (line[i] == 'l') {
      }
    }
  }
  in.close();
}

// void Paresr::WriteGraphToFile(const std::string* filename) {}

std::string Parser::removeSpaces(const std::string& str) {
  std::string result;
  for (char c : str) {
    if (!std::isspace(c)) {
      result += c;
    }
  }
  return result;
}

// if (line.find("digraph") != std::string::npos) {
//   LoadDigraph(in);
// } else if (line.find("graph") != std::string::npos) {
//   LoadGraph(in);
// }

// int pos_weight = line.find("label");
// adjacency_list_[vertexes[from]].push_back(vertexes[to], weight);
// std::cout << v1 << adjacency_list_[v1] << std::endl;
// }