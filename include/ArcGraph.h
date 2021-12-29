

#ifndef ALGORITMS_ARCGRAPH_H
#define ALGORITMS_ARCGRAPH_H

#include "IGraph.h"

struct Edge {
    Edge() = default;
    explicit Edge(int from, int to): from(from), to(to) {};
    int from;
    int to;
};

class ArcGraph: public IGraph {
public:
    explicit ArcGraph(int size);

    explicit ArcGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;

    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<Edge> graph;
};

#endif //ALGORITMS_ARCGRAPH_H
