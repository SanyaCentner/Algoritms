#include "IGraph.h"
#include "ListGraph.h"
#include "utils.h"

ListGraph::ListGraph(int size) {
    graph.resize(size);
}

ListGraph::ListGraph(const IGraph &igraph) {
    graph.resize(igraph.VerticesCount());
    BFS(igraph, [&](int v) {
        std::vector<int> next = igraph.GetNextVertices(v);
        for (auto i: next) {
            graph[v].push_back(i);
        }
    });
}

void ListGraph::AddEdge(int from, int to) {
    assert( from >= 0 && from < graph.size());
    assert( to >= 0 && to < graph.size());
    graph[from].push_back(to);
}


int ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < graph.size());
    return graph[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    assert( vertex >= 0 && vertex < graph.size());
    std::vector<int> result;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (auto nextVertex : graph[i]) {
            if (nextVertex == vertex) {
                result.push_back(i);
                break;
            }
        }
    }
    return result;
}

