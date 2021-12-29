//

#ifndef ALGORITMS_SETGRAPH_H
#define ALGORITMS_SETGRAPH_H

#include <unordered_set>
#include "IGraph.h"

class SetGraph: public IGraph {
public:
    explicit SetGraph(int size);

    explicit SetGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;

    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::unordered_set<int>> graph;
};

#endif //ALGORITMS_SETGRAPH_H
