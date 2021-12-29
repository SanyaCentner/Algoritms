

#ifndef ALGORITMS_UTILS_H
#define ALGORITMS_UTILS_H

#include "IGraph.h"

void BFS(const IGraph& graph, const std::function<void(int)>& func);

#endif //ALGORITMS_UTILS_H
