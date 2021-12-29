//Дан невзвешенный неориентированный граф. В графе может быть несколько кратчайших
//путей между какими-то вершинами. Найдите количество различных кратчайших путей между заданными вершинами.
//Требования: сложность O(V+E).


#include <iostream>
#include <vector>
#include <queue>
#include <functional>


struct IGraph {
    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

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

class ListGraph : public IGraph {
public:
    explicit ListGraph(int  size);

    explicit ListGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const  override;

    virtual std::vector<int> GetPrevVertices(int vertex) const override;

    virtual ~ListGraph() override = default;

private:
    std::vector<std::vector<int> > graph;
};

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
    assert(from >= 0 && from < graph.size());
    assert(to >= 0 && to < graph.size());
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


int count_ways(const IGraph& graph, const int begin, const int end) {
    std::vector<int> ways;
    std::vector<int> dist;
    std::vector<bool> visited;
    std::queue<int> queue;
    ways.resize(graph.VerticesCount(), 0);
    dist.resize(graph.VerticesCount(), 0);
    visited.resize(graph.VerticesCount(), false);
    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (i == begin) {
            queue.push(i);
            ways[i] = 1;
            while (!queue.empty()) {
                int vertex = queue.front();
                queue.pop();
                for (auto child : graph.GetNextVertices(vertex)) {
                    if (!visited[child]) {
                        queue.push(child);
                        ways[child] += ways[vertex];
                        dist[child] += dist[vertex] + 1;
                        visited[child] = true;
                    } else if (dist[child] == dist[vertex] + 1) {
                        ways[child] += ways[vertex];
                    }
                }
            }
        }
    }
    return ways[end];
}

void run(std::istream& input, std::ostream& output) {
    int vertex;
    int edge;
    std::cin >> vertex >> edge;

    ListGraph graph(vertex);
    for (int i = 0; i < edge; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.AddEdge(from, to);
    }

    int begin, end;
    std::cin >> begin >> end;
    int ways = count_ways(graph, begin, end);
    std::cout << ways << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}
