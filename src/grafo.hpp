#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <map>
#include <iostream>

class Grafo {
public:
    void agregarArista(int u, int v, int peso);
    void imprimir() const;
    const std::map<int, std::vector<std::pair<int, int>>>& obtenerAdyacencia() const;

private:
    std::map<int, std::vector<std::pair<int, int>>> adyacencia;

};

#endif
