#include "mst.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

// Estructura para Unión-Find (Disjoint Set)
class UnionFind {
    std::vector<int> parent, rank;
public:
    UnionFind(int n) : parent(n+1), rank(n+1, 0) {
        for (int i = 0; i <= n; ++i) parent[i] = i;
    }

    int find(int u) {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else {
            parent[pv] = pu;
            if (rank[pu] == rank[pv]) rank[pu]++;
        }
        return true;
    }
};

void kruskal_mst(const Grafo& g) {
    std::vector<std::tuple<int, int, int>> aristas;
    const auto& adj = g.obtenerAdyacencia();

    // Recopilar todas las aristas (sin duplicados)
    std::set<std::pair<int, int>> ya_agregadas;
    for (const auto& [u, vecinos] : adj) {
        for (const auto& [v, peso] : vecinos) {
            if (ya_agregadas.count({v, u}) == 0) {
                aristas.emplace_back(peso, u, v);
                ya_agregadas.insert({u, v});
            }
        }
    }

    std::sort(aristas.begin(), aristas.end()); // Menor peso primero

    UnionFind uf(100); // Usa suficiente tamaño
    std::vector<std::tuple<int, int, int>> mst;

    std::cout << "Ejecutando Kruskal paso a paso:\n";

    for (const auto& [peso, u, v] : aristas) {
        std::cout << "Considerando arista (" << u << ", " << v << ") con peso " << peso << "... ";

        if (uf.unite(u, v)) {
            mst.emplace_back(peso, u, v);
            std::cout << "AGREGADA al MST.\n";
        } else {
            std::cout << "DESCARTADA (forma ciclo).\n";
        }
    }

    std::cout << "\nÁrbol de expansión mínima:\n";
    int total = 0;
    for (const auto& [peso, u, v] : mst) {
        std::cout << "(" << u << ", " << v << ") peso " << peso << "\n";
        total += peso;
    }
    std::cout << "Peso total del MST: " << total << "\n";
}
