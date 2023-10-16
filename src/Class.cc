#include "Class.h"

void Graph::printpath(std::vector<int> &parent, int vertex, int target)
{
    if (vertex == 0)
    {
        return;
    }
    printpath(parent, parent[vertex], target);
    std::cout << vertex << (vertex == target ? "\n" : "--");
}

int Graph::widest_path_problem(std::vector<std::vector<std::pair<int, int>>> &Graph,
                               int src, int target)
{
    std::vector<int> widest(Graph.size(), INT_MIN);
    std::vector<int> parent(Graph.size(), 0);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        container;

    container.push(std::make_pair(0, src));
    widest[src] = INT_MAX;

    while (container.empty() == false)
    {
        std::pair<int, int> temp = container.top();
        int current_src = temp.second;
        container.pop();
        for (auto vertex : Graph[current_src])
        {
            // Encontrando a maior distância até o vértice usando
            // a maior distância
            // do vértice current_source
            // e sua maior distância até agora
            int distance = std::max(widest[vertex.second], std::min(widest[current_src],
                                                                    vertex.first));

            // Relaxamento da borda e adição na fila prioritária
            if (distance > widest[vertex.second])
            {
                widest[vertex.second] = distance;
                parent[vertex.second] = current_src;
                container.push(std::make_pair(distance, vertex.second));
            }
        }
    }
    // printpath(parent, target, target);
    return widest[target];
}