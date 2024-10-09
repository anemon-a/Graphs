#include "s21_graph_algorithms.h"

#include <optional>

std::vector<Vertex> GraphAlgorithms::DepthFirstSearch(
    const IGraph &graph, const Vertex &start_vertex) {
  std::stack<Vertex> stack;
  std::vector<Vertex> result;
  std::unordered_set<Vertex> visited;
  stack.push(start_vertex);
  while (!stack.empty()) {
    Vertex v_from = stack.top();
    stack.pop();
    if (!visited.count(v_from)) {
      visited.insert(v_from);
      result.push_back(v_from);
      auto neighbours = graph.GetNeighbourVertices(v_from);
      for (auto v_to = neighbours.rbegin(); v_to != neighbours.rend(); v_to++) {
        if (!visited.count(*v_to)) {
          stack.push(*v_to);
        }
      }
    }
  }

  return result;
}

std::vector<Vertex> GraphAlgorithms::BreadthFirstSearch(
    const IGraph &graph, const Vertex &start_vertex) {
  std::queue<Vertex> queue;
  std::vector<Vertex> result;
  std::unordered_set<Vertex> visited;
  queue.push(start_vertex);
  while (!queue.empty()) {
    Vertex v_from = queue.front();
    if (!visited.count(v_from)) {
      for (const auto &v_to : graph.GetNeighbourVertices(v_from)) {
        if (!visited.count(v_to)) {
          queue.push(v_to);
        }
      }
      visited.insert(v_from);
      result.push_back(v_from);
    }
    queue.pop();
  }
  return result;
}

int GraphAlgorithms::GetShortestPathBetweenVertices(const IGraph &graph,
                                                    const Vertex &vertex1,
                                                    const Vertex &vertex2) {
  std::map<Vertex, int> shortest_path;
  std::unordered_set<Vertex> unvisited;
  for (const auto &vertex : graph.GetAllVertices()) {
    shortest_path[vertex] = infinity;
    unvisited.insert(vertex);
  }
  shortest_path[vertex1] = 0;
  while (!unvisited.empty()) {
    int min_path = infinity;
    Vertex min_path_vertex = -1;

    for (const auto &[vertex, distance] : shortest_path) {
      if (distance < min_path && unvisited.count(vertex)) {
        min_path = distance;
        min_path_vertex = vertex;
      }
    }
    unvisited.erase(min_path_vertex);
    if (min_path_vertex == Vertex(-1)) break;

    for (const auto &neighbour_vertex :
         graph.GetNeighbourVertices(min_path_vertex)) {
      int new_path =
          min_path + graph.GetEdgeWeight(min_path_vertex, neighbour_vertex);

      if (new_path < shortest_path[neighbour_vertex]) {
        shortest_path[neighbour_vertex] = new_path;
      }
    }
  }
  return shortest_path[vertex2];
}

std::vector<std::vector<std::optional<int>>>
GraphAlgorithms::GetShortestPathsBetweenAllVertices(const IGraph &graph) {
  int vertex_count = graph.GetVertexCount();
  const auto &vertices = graph.GetAllVertices();
  std::vector<std::vector<std::optional<int>>> shortest_paths(
      vertex_count,
      std::vector<std::optional<int>>(vertex_count, std::nullopt));

  int i = 0, j = 0, weight = 0;
  for (const auto &v_from : vertices) {
    j = 0;
    for (const auto &v_to : vertices) {
      if (i == j) {
        shortest_paths[i][j] = 0;
      } else if ((weight = graph.GetEdgeWeight(v_from, v_to))) {
        shortest_paths[i][j] = weight;
      }
      j++;
    }
    i++;
  }
  for (int k = 0; k < vertex_count; ++k) {
    for (int i = 0; i < vertex_count; ++i) {
      for (int j = 0; j < vertex_count; ++j) {
        if (shortest_paths[i][k].has_value() &&
            shortest_paths[k][j].has_value())
          if (!shortest_paths[i][j].has_value() ||
              shortest_paths[i][j].value() > (shortest_paths[i][k].value() +
                                              shortest_paths[k][j].value())) {
            shortest_paths[i][j] =
                shortest_paths[i][k].value() + shortest_paths[k][j].value();
          }
      }
    }
  }
  return shortest_paths;
}

std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(
    const IGraph &graph) {
  int vertex_count = graph.GetVertexCount();
  std::map<Vertex, std::pair<Vertex, int>> shortest_edges;
  std::map<Vertex, int> vertex_index;
  int index = 0;
  for (const auto &vertex : graph.GetAllVertices()) {
    shortest_edges[vertex] = std::pair(vertex, infinity);
  }

  Vertex min_path_vertex = 1;  // из произвольной вершины графа
  shortest_edges[min_path_vertex] = std::pair(0, 0);
  while (vertex_index.size() != vertex_count) {
    vertex_index[min_path_vertex] = index++;

    for (const auto &neighbour_vertex :
         graph.GetNeighbourVertices(min_path_vertex)) {
      if (!vertex_index.count(neighbour_vertex)) {
        int path = shortest_edges[neighbour_vertex].second;
        int new_path = graph.GetEdgeWeight(min_path_vertex, neighbour_vertex);
        if (new_path < path) {
          shortest_edges[neighbour_vertex] =
              std::pair(min_path_vertex, new_path);
        }
      }
    }
    int min_path = infinity;
    for (const auto &[vertex, path] : shortest_edges) {
      if (!vertex_index.count(vertex) && (path.second < min_path)) {
        min_path = path.second;
        min_path_vertex = vertex;
      }
    }
  }

  std::vector<std::vector<int>> matrix_tree(vertex_count,
                                            std::vector<int>(vertex_count, 0));
  for (const auto &[vertex, path] : shortest_edges) {
    // std::cout << vertex_index[vertex] << ' ' << vertex_index[path.first] << '
    // '
    //           << path.second << std::endl;
    matrix_tree[vertex_index[vertex]][vertex_index[path.first]] = path.second;
    matrix_tree[vertex_index[path.first]][vertex_index[vertex]] = path.second;
  }

  return matrix_tree;
}
