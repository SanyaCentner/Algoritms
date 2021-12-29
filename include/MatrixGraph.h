
#ifndef ALGORITMS_MATRIXGRAPH_H
#define ALGORITMS_MATRIXGRAPH_H

#include "IGraph.h"

class MatrixGraph: public IGraph {
public:
    explicit MatrixGraph(int size);

    explicit MatrixGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;

    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> graph;
};

#endif //ALGORITMS_MATRIXGRAPH_H
