## Dijkstra and Floyd Algorithms
This program implements the Dijkstra and Floyd algorithms to find the shortest path between a pair of vertices in a directed graph.

### Problem Description
The Dijkstra and Floyd algorithms are fundamental in graph theory and network optimization. They are used to find the shortest path between two nodes in a directed graph, where each edge has a non-negative weight. Dijkstra's algorithm focuses on finding the shortest path from a single source node to all other nodes, while Floyd's algorithm computes the shortest paths between all pairs of nodes in the graph. These algorithms are crucial in various applications such as network routing, transportation planning, and computer networks.

### Input
The program receives an integer, *N*, followed by *N* x *N* integer values representing an adjacency matrix of a directed graph. The first number, *N*, represents the number of nodes. The following values represent the values in the matrix. The value at position (*i*, *j*) represents the weight of the arc from node *i* to node *j*. If there is no arc between node *i* and node *j*, the value in the matrix will be -1.

### Output
The output of the program is, first, the result of the Dijkstra algorithm, showing the distance from node *i* to node *j* for all nodes. Next, it should display the result matrix of the Floyd algorithm.

### Time Complexity
- Dijkstra Algorithm (DJ): O(V²)
- Floyd–Warshall Algorithm (FW): O(V³)

### Usage
To compile the program, use the following command:
`g++ -std=c++11 main.cpp -o app`

To execute the program, run:
`./app < inputX.txt > resultX.txt`

To verify the correctness of the output, you can use the `diff` command:
`diff resultX.txt outputX.txt`

If no output is shown, the results are as expected.