### Compilación y Ejecución

1. **Compilar el programa**:
```bash
g++ -o dijkstra_experiment dijkstra_experiment.cpp -std=c++11
```

2. **Ejecutar el programa**:
```bash
./dijkstra_experiment
```

3. **Graficar los resultados**:
```bash
gnuplot -e "
set datafile separator ',';
set xlabel 'Number of Edges (e)';
set ylabel 'Average Execution Time (seconds)';
set title 'Dijkstra Algorithm Performance';
plot 'results.csv' using 2:3 with lines title 'Heap', \
     'results.csv' using 2:4 with lines title 'FibHeap';
pause -1;"
```

