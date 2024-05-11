## Graph Coloring using Adjacency Matrix
This program implements a solution for the Graph Coloring problem using an adjacency matrix representation of an undirected graph.

### Problem Description
The Graph Coloring problem involves assigning colors to vertices of a graph in such a way that no two adjacent vertices have the same color. The goal is to minimize the number of colors used while ensuring this condition.

### Input
The program expects the following input:
- An undirected graph represented as an adjacency matrix. The first line of input contains an integer n, indicating the number of vertices in the graph. The next n lines contain n numbers each. The j-th value in the i-th line is 1 if vertex i is connected to vertex j, and 0 otherwise.

### Output
The program should output the colors assigned to each vertex.

### Time Complexity
The time complexity of the Welsh Powell Variation algorithm for Graph Coloring is O(n³), where n is the number of vertices in the graph.

### Usage
To compile the program, use the following command:
`g++ -std=c++11 main.cpp -o app`

To execute the program, run:
`./app < inputX.txt > resultX.txt`

To verify the correctness of the output, you can use the `diff` command:
`diff resultX.txt outputX.txt`

If no output is shown, the results are as expected.