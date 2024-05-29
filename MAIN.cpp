#include <chrono>
#include <fstream>

void runExperiment() {
    vector<tuple<int, int, double>> resultsHeap;
    vector<tuple<int, int, double>> resultsFibHeap;

    for (int i = 10; i <= 14; i += 2) {
        int V = 1 << i;
        for (int j = 16; j <= 22; ++j) {
            int E = 1 << j;
            vector<double> timesHeap;
            vector<double> timesFibHeap;

            for (int k = 0; k < 50; ++k) {
                Graph graph = generateGraph(V, E);
                int startNode = rand() % V;

                vector<double> dist;
                vector<int> prev;

                // Dijkstra con Heap
                auto start = chrono::high_resolution_clock::now();
                graph.dijkstraHeap(startNode, dist, prev);
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> duration = end - start;
                timesHeap.push_back(duration.count());

                // Dijkstra con Cola de Fibonacci
                start = chrono::high_resolution_clock::now();
                dijkstraFibHeap(graph, startNode, dist, prev);
                end = chrono::high_resolution_clock::now();
                duration = end - start;
                timesFibHeap.push_back(duration.count());
            }

            double avgTimeHeap = accumulate(timesHeap.begin(), timesHeap.end(), 0.0) / timesHeap.size();
            double avgTimeFibHeap = accumulate(timesFibHeap.begin(), timesFibHeap.end(), 0.0) / timesFibHeap.size();

            resultsHeap.emplace_back(V, E, avgTimeHeap);
            resultsFibHeap.emplace_back(V, E, avgTimeFibHeap);
        }
    }

    ofstream outFile("results.csv");
    outFile << "V,E,TimeHeap,TimeFibHeap\n";
    for (size_t i = 0; i < resultsHeap.size(); ++i) {
        outFile << get<0>(resultsHeap[i]) << "," << get<1>(resultsHeap[i]) << ","
                << get<2>(resultsHeap[i]) << "," << get<2>(resultsFibHeap[i]) << "\n";
    }
}
