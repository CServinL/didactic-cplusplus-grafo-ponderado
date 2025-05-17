#include "shortest.hpp"
#include <queue>
#include <map>
#include <set>
#include <iostream>

void shortest_dijkstra(const Grafo& g, int inicio) {
    const auto& adj = g.obtenerAdyacencia();
    std::map<int, int> distancia;
    std::map<int, int> anterior;

    // Inicializar distancias a infinito
    for (const auto& [nodo, _] : adj) {
        distancia[nodo] = INT_MAX;
    }
    distancia[inicio] = 0;

    // Min-heap: (distancia, nodo)
    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int>>,
                        std::greater<>> pq;

    pq.emplace(0, inicio);

    std::cout << "Dijkstra desde nodo " << inicio << ":\n";

    while (!pq.empty()) {
        auto [dist, u] = pq.top();
        pq.pop();

        if (dist > distancia[u]) continue;

        std::cout << "Nodo " << u << " con distancia " << dist << "\n";

        for (const auto& [v, peso] : adj.at(u)) {
            if (distancia[u] + peso < distancia[v]) {
                distancia[v] = distancia[u] + peso;
                anterior[v] = u;
                pq.emplace(distancia[v], v);
                std::cout << "  Actualizamos camino a nodo " << v << " con nueva distancia " << distancia[v] << " vía " << u << "\n";
            }
        }
    }

    std::cout << "\nDistancias finales desde nodo " << inicio << ":\n";
    for (const auto& [nodo, dist] : distancia) {
        std::cout << "Nodo " << nodo << ": ";
        if (dist == INT_MAX) std::cout << "infinito\n";
        else std::cout << dist << "\n";
    }
}
