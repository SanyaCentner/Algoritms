#include <set>

#include "ArcGraph.h"
#include "utils.h"


ArcGraph::ArcGraph(int size) {
    graph.resize(2 * size);
}

ArcGraph::ArcGraph(const IGraph &igraph) {
    graph.resize(2 * igraph.VerticesCount());
    BFS(igraph, [&](int v) {
        std::vector<int> next = igraph.GetNextVertices(v);
        for (int i: next) {
            graph.emplace_back(v, i);
        }
    });
}

void ArcGraph::AddEdge(int from, int to) {
    graph.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    std::set<int> uniq_vertices;
    for (auto edge: graph) {
        uniq_vertices.insert(edge.from);
        uniq_vertices.insert(edge.to);
    }
    return uniq_vertices.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> result;
    for (auto edge: graph) {
        if (edge.from == vertex) {
            result.push_back(edge.to);
        }
    }
    return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result;
    for (auto edge: graph) {
        if (edge.to == vertex) {
            result.push_back(edge.from);
        }
    }
    return result;
}
