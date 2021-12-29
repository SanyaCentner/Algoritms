#include "MatrixGraph.h"
#include "utils.h"

MatrixGraph::MatrixGraph(int size) {
    graph.resize(size);
    for (auto gr: graph) {
        gr.resize(size);
    }
}

MatrixGraph::MatrixGraph(const IGraph &igraph) {
    graph.resize(igraph.VerticesCount());
    for (auto &gr: graph) {
        gr.resize(igraph.VerticesCount());
    }
    BFS(igraph, [&](int v) {
        std::vector<int> next = igraph.GetNextVertices(v);
        for (auto i: next) {
            graph[v][i] = 1;
        }
    });
}

void MatrixGraph::AddEdge(int from, int to) {
    assert( from >= 0 && from < graph.size());
    assert( to >= 0 && to < graph.size());
    graph[from][to] = 1;
}

int MatrixGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < graph.size());
    std::vector<int> result;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i]) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < graph.size());
    std::vector<int> result;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[i][vertex]) {
            result.push_back(i);
        }
    }
    return result;
}

