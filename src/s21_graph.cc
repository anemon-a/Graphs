#include "s21_graph.h"

#include "parser.h"

void Graph::LoadGraphFromFile(std::string filename) {
  Parser parser;
  parser.ParseGraphFromFile(filename);
}

void Graph::ExportGraphToDot(std::string filename) {}
