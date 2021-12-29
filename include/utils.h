

#ifndef ALGORITMS_UTILS_H
#define ALGORITMS_UTILS_H

#include "IGraph.h"

void bfs(const IGraph& graph, const std::function<void(int)>& callback);

#endif //ALGORITMS_UTILS_H
