# didactic-cplusplus-grafo/ponderado
Fundamentos - Algoritmos - C++ - Grafo ponderado

Modelamos un grafo en C++ con agregamos un para de funciones DFS para retornar solo los nodos y otra mas detallada que demuestra los caminos posibles y cual esta explorando en ese momento.

Usando el algoritmo de Kruskal armamos un árbol de expansión mínima (MST) e imprimimos paso a paso como se va armando.

Usando el Djiksta encontramos los caminos mas cortos desde el nodo 3.

```
1: (2, 6) (4, 7) (5, 9) 
2: (1, 6) (3, 1) (8, 8) 
3: (2, 1) (7, 2) 
4: (1, 7) 
5: (1, 9) (11, 9) 
6: (7, 4) (8, 2) (9, 9) 
7: (3, 2) (6, 4) (8, 3) (14, 2) 
8: (2, 8) (6, 2) (7, 3) (9, 9) (10, 6) 
9: (6, 9) (8, 9) 
10: (8, 6) (11, 8) (12, 7) (14, 4) 
11: (10, 8) (5, 9) (13, 2) 
12: (10, 7) 
13: (11, 2) 
14: (7, 2) (10, 4) 
DFS desde nodo 1:
1 2 3 7 6 8 9 10 11 5 13 12 14 4 

DFS detallado desde nodo 1:
Exploramos 1, vemos salidas a nodo 2 con peso 6, nodo 4 con peso 7, nodo 5 con peso 9.
Exploramos 2, vemos salidas a nodo 1 con peso 6, nodo 3 con peso 1, nodo 8 con peso 8.
Exploramos 3, vemos salidas a nodo 2 con peso 1, nodo 7 con peso 2.
Exploramos 7, vemos salidas a nodo 3 con peso 2, nodo 6 con peso 4, nodo 8 con peso 3, nodo 14 con peso 2.
Exploramos 6, vemos salidas a nodo 7 con peso 4, nodo 8 con peso 2, nodo 9 con peso 9.
Exploramos 8, vemos salidas a nodo 2 con peso 8, nodo 6 con peso 2, nodo 7 con peso 3, nodo 9 con peso 9, nodo 10 con peso 6.
Exploramos 9, vemos salidas a nodo 6 con peso 9, nodo 8 con peso 9.
Exploramos 10, vemos salidas a nodo 8 con peso 6, nodo 11 con peso 8, nodo 12 con peso 7, nodo 14 con peso 4.
Exploramos 11, vemos salidas a nodo 5 con peso 9, nodo 10 con peso 8, nodo 13 con peso 2.
Exploramos 5, vemos salidas a nodo 1 con peso 9, nodo 11 con peso 9.
Exploramos 13, vemos salidas a nodo 11 con peso 2.
Exploramos 12, vemos salidas a nodo 10 con peso 7.
Exploramos 14, vemos salidas a nodo 7 con peso 2, nodo 10 con peso 4.
Exploramos 4, vemos salidas a nodo 1 con peso 7.

Kruskal MST:
Ejecutando Kruskal paso a paso:
Considerando arista (2, 3) con peso 1... AGREGADA al MST.
Considerando arista (3, 7) con peso 2... AGREGADA al MST.
Considerando arista (6, 8) con peso 2... AGREGADA al MST.
Considerando arista (7, 14) con peso 2... AGREGADA al MST.
Considerando arista (11, 13) con peso 2... AGREGADA al MST.
Considerando arista (7, 8) con peso 3... AGREGADA al MST.
Considerando arista (6, 7) con peso 4... DESCARTADA (forma ciclo).
Considerando arista (10, 14) con peso 4... AGREGADA al MST.
Considerando arista (1, 2) con peso 6... AGREGADA al MST.
Considerando arista (8, 10) con peso 6... DESCARTADA (forma ciclo).
Considerando arista (1, 4) con peso 7... AGREGADA al MST.
Considerando arista (10, 12) con peso 7... AGREGADA al MST.
Considerando arista (2, 8) con peso 8... DESCARTADA (forma ciclo).
Considerando arista (10, 11) con peso 8... AGREGADA al MST.
Considerando arista (1, 5) con peso 9... AGREGADA al MST.
Considerando arista (5, 11) con peso 9... DESCARTADA (forma ciclo).
Considerando arista (6, 9) con peso 9... AGREGADA al MST.
Considerando arista (8, 9) con peso 9... DESCARTADA (forma ciclo).

Árbol de expansión mínima:
(2, 3) peso 1
(3, 7) peso 2
(6, 8) peso 2
(7, 14) peso 2
(11, 13) peso 2
(7, 8) peso 3
(10, 14) peso 4
(1, 2) peso 6
(1, 4) peso 7
(10, 12) peso 7
(10, 11) peso 8
(1, 5) peso 9
(6, 9) peso 9
Peso total del MST: 62

Caminos más cortos desde nodo 3 (Dijkstra):
Dijkstra desde nodo 3:
Nodo 3 con distancia 0
  Actualizamos camino a nodo 2 con nueva distancia 1 vía 3
  Actualizamos camino a nodo 7 con nueva distancia 2 vía 3
Nodo 2 con distancia 1
  Actualizamos camino a nodo 1 con nueva distancia 7 vía 2
  Actualizamos camino a nodo 8 con nueva distancia 9 vía 2
Nodo 7 con distancia 2
  Actualizamos camino a nodo 6 con nueva distancia 6 vía 7
  Actualizamos camino a nodo 8 con nueva distancia 5 vía 7
  Actualizamos camino a nodo 14 con nueva distancia 4 vía 7
Nodo 14 con distancia 4
  Actualizamos camino a nodo 10 con nueva distancia 8 vía 14
Nodo 8 con distancia 5
  Actualizamos camino a nodo 9 con nueva distancia 14 vía 8
Nodo 6 con distancia 6
Nodo 1 con distancia 7
  Actualizamos camino a nodo 4 con nueva distancia 14 vía 1
  Actualizamos camino a nodo 5 con nueva distancia 16 vía 1
Nodo 10 con distancia 8
  Actualizamos camino a nodo 11 con nueva distancia 16 vía 10
  Actualizamos camino a nodo 12 con nueva distancia 15 vía 10
Nodo 4 con distancia 14
Nodo 9 con distancia 14
Nodo 12 con distancia 15
Nodo 5 con distancia 16
Nodo 11 con distancia 16
  Actualizamos camino a nodo 13 con nueva distancia 18 vía 11
Nodo 13 con distancia 18

Caminos más cortos desde nodo 3:
→ Nodo 1: 3 -> 2 -> 1 (distancia: 7)
→ Nodo 2: 3 -> 2 (distancia: 1)
→ Nodo 3: 3 (distancia: 0)
→ Nodo 4: 3 -> 2 -> 1 -> 4 (distancia: 14)
→ Nodo 5: 3 -> 2 -> 1 -> 5 (distancia: 16)
→ Nodo 6: 3 -> 7 -> 6 (distancia: 6)
→ Nodo 7: 3 -> 7 (distancia: 2)
→ Nodo 8: 3 -> 7 -> 8 (distancia: 5)
→ Nodo 9: 3 -> 7 -> 8 -> 9 (distancia: 14)
→ Nodo 10: 3 -> 7 -> 14 -> 10 (distancia: 8)
→ Nodo 11: 3 -> 7 -> 14 -> 10 -> 11 (distancia: 16)
→ Nodo 12: 3 -> 7 -> 14 -> 10 -> 12 (distancia: 15)
→ Nodo 13: 3 -> 7 -> 14 -> 10 -> 11 -> 13 (distancia: 18)
→ Nodo 14: 3 -> 7 -> 14 (distancia: 4)
```