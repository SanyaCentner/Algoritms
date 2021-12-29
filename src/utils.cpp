#include <vector>
#include <queue>
#include "utils.h"

void BFS(const IGraph& graph, const std::function<void(int)>& func) {
    std::vector<bool> visited;
    std::queue<int> queue;
    visited.resize(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            queue.push(i);
            visited[i] = true;
            while (!queue.empty()) {
                int vertex = queue.front();
                queue.pop();
                func(vertex);
                for (auto nextVertex : graph.GetNextVertices(vertex)) {
                    if (!visited[nextVertex]) {
                        queue.push(nextVertex);
                        visited[nextVertex] = true;
                    }
                }
            }
        }
    }
}

