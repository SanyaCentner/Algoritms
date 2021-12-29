
#ifndef ALGORITMS_LISTGRAPH_H
#define ALGORITMS_LISTGRAPH_H

#include "IGraph.h"

class ListGraph : public IGraph {
public:
    explicit ListGraph(int size);

    explicit ListGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const  override;

    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    virtual ~ListGraph() override = default;

private:
    std::vector<std::vector<int> > graph;
};

#endif //ALGORITMS_LISTGRAPH_H
