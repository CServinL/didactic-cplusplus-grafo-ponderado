#include "grafo.hpp"
#include "dfs.hpp"
#include "mst.hpp"
#include "shortest.hpp"


int main() {
    Grafo g;

    g.agregarArista(1, 2, 6);
    g.agregarArista(1, 4, 7);
    g.agregarArista(2, 3, 1);
    g.agregarArista(2, 8, 8);
    g.agregarArista(3, 7, 2);
    g.agregarArista(1, 5, 9);
    g.agregarArista(6, 7, 4);
    g.agregarArista(6, 8, 2);
    g.agregarArista(6, 9, 9);
    g.agregarArista(7, 8, 3);
    g.agregarArista(7, 14, 2);
    g.agregarArista(8, 9, 9);
    g.agregarArista(8, 10, 6);
    g.agregarArista(10, 11, 8);
    g.agregarArista(10, 12, 7);
    g.agregarArista(11, 5, 9);
    g.agregarArista(11, 13, 2);
    g.agregarArista(14, 10, 4);

    g.imprimir();

    std::cout << "DFS desde nodo 1:\n";
    dfs(g, 1);

    std::cout << "\nDFS detallado desde nodo 1:\n";
    dfs_detallado(g, 1);

    std::cout << "\nKruskal MST:\n";
    kruskal_mst(g);

    std::cout << "\nCaminos más cortos desde nodo 3 (Dijkstra):\n";
    shortest_dijkstra(g, 3);

    return 0;
}
