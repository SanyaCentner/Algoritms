#include "SetGraph.h"
#include "utils.h"

SetGraph::SetGraph(int size) {
    graph.resize(size);
}

SetGraph::SetGraph(const IGraph &igraph) {
    graph.resize(igraph.VerticesCount());
    BFS(igraph, [&](int v) {
        std::vector<int> next = igraph.GetNextVertices(v);
        for (auto i: next) {
            graph[v].insert(i);
        }
    });
}

void SetGraph::AddEdge(int from, int to) {
    assert( from >= 0 && from < graph.size());
    assert( to >= 0 && to < graph.size());

    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert( vertex >= 0 && vertex < graph.size());
    std::vector<int> result;
    std::for_each(graph[vertex].begin(), graph[vertex].end(), [&](auto &n) { result.push_back(n); });
    return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert( vertex >= 0 && vertex < graph.size());
    std::vector<int> result;
    for (const auto &i : graph) {
        auto search = i.find(vertex);
        if (search != i.end()) {
            result.push_back(*search);
        }
    }
    return result;
}

