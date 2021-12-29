#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <set>
#include <cassert>
#include <algorithm>

#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"
#include "utils.h"

int main() {
    ListGraph list(7);

    list.AddEdge(0, 1);
    list.AddEdge(0, 5);
    list.AddEdge(1, 2);
    list.AddEdge(1, 3);
    list.AddEdge(1, 5);
    list.AddEdge(1, 6);
    list.AddEdge(3, 2);
    list.AddEdge(3, 4);
    list.AddEdge(3, 6);
    list.AddEdge(5, 4);
    list.AddEdge(5, 6);
    list.AddEdge(6, 4);

    std::cout << "List" << std::endl;
    BFS(list, [](int vertex) {
        std::cout  <<  vertex << std::endl;
    });

    assert(list.VerticesCount() == 7);

    MatrixGraph matr(list);
    std::cout << "Matrix" << std::endl;
    BFS(matr, [](int vertex) {
        std::cout << vertex << std::endl;
    });

    assert(matr.VerticesCount() == 7);

    ArcGraph arc(matr);
    std::cout << "Arc" << std::endl;
    BFS(arc, [](int vertex) {
        std::cout << vertex << std::endl;
    });

    assert(arc.VerticesCount() == 7);

    SetGraph set(arc);
    std::cout << "Set" << std::endl;
    BFS(arc, [](int vertex) {
        std::cout << vertex << std::endl;
    });

    assert(set.VerticesCount() == 7);

    return 0;
}
