#include "grafo.hpp"

void Grafo::agregarArista(int u, int v, int peso) {
    adyacencia[u].emplace_back(v, peso);
    adyacencia[v].emplace_back(u, peso); // No dirigido
}

void Grafo::imprimir() const {
    for (const auto& [nodo, vecinos] : adyacencia) {
        std::cout << nodo << ": ";
        for (const auto& [vecino, peso] : vecinos) {
            std::cout << "(" << vecino << ", " << peso << ") ";
        }
        std::cout << "\n";
    }
}

const std::map<int, std::vector<std::pair<int, int>>>& Grafo::obtenerAdyacencia() const {
    return adyacencia;
}