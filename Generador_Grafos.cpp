#include <cstdlib>
#include <ctime>

Graph generateGraph(int V, int E) {
    Graph graph(V);
    srand(time(nullptr));

    // Crear un árbol para asegurar la conectividad
    for (int i = 1; i < V; ++i) {
        int parent = rand() % i;
        double weight = (rand() % 100 + 1) / 100.0;
        graph.addEdge(i, parent, weight);
    }

    // Agregar aristas adicionales
    int edgesAdded = V - 1;
    while (edgesAdded < E) {
        int u = rand() % V;
        int v = rand() % V;
        if (u != v) {
            double weight = (rand() % 100 + 1) / 100.0;
            graph.addEdge(u, v, weight);
            edgesAdded++;
        }
    }

    return graph;
}
