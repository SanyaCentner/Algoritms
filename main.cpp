//Требуется отыскать самый выгодный маршрут между городами.
//Требования: время работы O((N+M)logN), где N-количество городов, M-известных дорог между ними.


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <set>

struct ToEdge {
    ToEdge() = default;
    ToEdge(int to, int weight): to(to), weight(weight)
    {}

    int to;
    int weight;
};

struct IGraph {

    virtual ~IGraph() {}

    virtual void AddEdge(int from, int to, int weight) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<ToEdge> GetNextVertices(int vertex) const = 0;

    virtual std::vector<ToEdge> GetPrevVertices(int vertex) const = 0;
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
                    if (!visited[nextVertex.to]) {
                        queue.push(nextVertex.to);
                        visited[nextVertex.to] = true;
                    }
                }
            }
        }
    }
}

class ListGraph : public IGraph {
public:
    explicit ListGraph(int size);

    explicit ListGraph(const IGraph& igraph);

    virtual void AddEdge(int from, int to, int weight) override;

    virtual int VerticesCount() const override;

    virtual std::vector<ToEdge> GetNextVertices(int vertex) const  override;

    virtual std::vector<ToEdge> GetPrevVertices(int vertex) const override;

    virtual ~ListGraph() override = default;

private:
    std::vector<std::vector<ToEdge> > graph;
};

ListGraph::ListGraph(int size) {
    graph.resize(size);
}

void ListGraph::AddEdge(int from, int to, int weight) {
    assert(from >= 0 && from < graph.size());
    assert(to >= 0 && to < graph.size());
    graph[from].emplace_back(to, weight);
    graph[to].emplace_back(from, weight);

}

int ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<ToEdge> ListGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < graph.size());
    std::vector<ToEdge> result;
    result.resize(graph[vertex].size());
    std::copy(graph[vertex].begin(), graph[vertex].end(), result.begin());
    return result;
}

std::vector<ToEdge> ListGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < graph.size());
    std::vector<ToEdge> result;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (auto child : graph[i]) {
            if (child.to == vertex) {
                result.push_back(child);
                break;
            }
        }
    }
    return result;
}

struct Distance {
    Distance(int vertex, int dist): vertex(vertex), dist(dist)
    {}

    int vertex;
    int dist;

    bool operator()(const Distance &left, const Distance &right) {
        return left.dist <= right.dist;
    }
    bool operator<(const Distance & rhs) const {
        return (this->dist <= rhs.dist);
    }
};

int ShortWay(IGraph &graph, int begin, int end) {
    std::set<Distance> queue;
    queue.emplace(begin, 0);

    std::vector<int> distance;
    distance.resize(graph.VerticesCount(), 0);

    std::vector<bool> visited;
    visited.resize(graph.VerticesCount(), false);

    visited[begin] = true;

    while(!queue.empty()) {
        Distance dist = *queue.begin();
        queue.erase(queue.begin());
        for (auto nextVertex: graph.GetNextVertices(dist.vertex)) {
            if (!visited[nextVertex.to]) {
                distance[nextVertex.to] = nextVertex.weight + dist.dist;
                queue.emplace(nextVertex.to, distance[nextVertex.to]);
                visited[nextVertex.to] = true;
            } else if (distance[dist.vertex] + nextVertex.weight < distance[nextVertex.to]) {
                queue.erase(Distance(nextVertex.to, distance[nextVertex.to]));
                distance[nextVertex.to] = distance[dist.vertex] + nextVertex.weight;
                queue.emplace(nextVertex.to, distance[nextVertex.to]);
            }
        }
    }
    return distance[end];
}

void run(std::istream& input, std::ostream& output) {
    int vertex, edge;
    input >> vertex >> edge;
    ListGraph graph(vertex);
    for (int i = 0; i < edge; ++i) {
        int from, to, weight;
        input >> from >> to >> weight;
        graph.AddEdge(from, to, weight);
    }
    int begin, end;
    input >> begin >> end;
    output << ShortWay(graph, begin, end);
}
int main() {
    run(std::cin, std::cout);
    return 0;
}
