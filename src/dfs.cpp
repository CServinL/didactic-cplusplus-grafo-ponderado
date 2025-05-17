#include "dfs.hpp"
#include <set>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

void dfs(const Grafo& g, int inicio) {
    std::set<int> visitado;

    std::function<void(int)> dfsRec = [&](int nodo) {
        visitado.insert(nodo);
        std::cout << nodo << " ";

        const auto& lista = g.obtenerAdyacencia();
        if (lista.count(nodo)) {
            std::vector<int> vecinos;
            for (const auto& [vecino, _] : lista.at(nodo)) {
                vecinos.push_back(vecino);
            }
            std::sort(vecinos.begin(), vecinos.end());

            for (int vecino : vecinos) {
                if (!visitado.count(vecino)) {
                    dfsRec(vecino);
                }
            }
        }
    };

    dfsRec(inicio);
    std::cout << std::endl;
}

void dfs_detallado(const Grafo& g, int inicio) {
    std::set<int> visitado;

    std::function<void(int)> dfsRec = [&](int nodo) {
        visitado.insert(nodo);

        const auto& lista = g.obtenerAdyacencia();
        if (!lista.count(nodo)) return;

        std::cout << "Exploramos " << nodo << ", vemos salidas a ";
        const auto& vecinos_pesados = lista.at(nodo);

        std::vector<std::pair<int, int>> vecinos_ordenados = vecinos_pesados;
        std::sort(vecinos_ordenados.begin(), vecinos_ordenados.end());

        for (size_t i = 0; i < vecinos_ordenados.size(); ++i) {
            const auto& [vecino, peso] = vecinos_ordenados[i];
            std::cout << "nodo " << vecino << " con peso " << peso;
            if (i + 1 < vecinos_ordenados.size()) std::cout << ", ";
        }
        std::cout << ".\n";

        for (const auto& [vecino, _] : vecinos_ordenados) {
            if (!visitado.count(vecino)) {
                dfsRec(vecino);
            }
        }
    };

    dfsRec(inicio);
}
