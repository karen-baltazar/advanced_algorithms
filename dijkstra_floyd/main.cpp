// =========================================================
// File: main.cpp
// Authors:
//  Ana Karen López Baltazar - A01707750
// Date: 29/09/2022
// Description:
//          Big-O Complexity Analysis:
//          ■ DJ - Dijkstra: O(V²)
//          ■ FW - Floyd – Warshall: O(V³)
//
//          Execution Command (Linux Shell):
//          ■ g++ -std=c++11 main.cpp -o app
//          ■ ./app < inputX.txt > resultX.txt
//          ■ diff resultX.txt outputX.txt
// =========================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// Auxiliary functions
void print(vector<vector<int>> input) {
  int size = input.size();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((j + 1) == size) {
        cout << input[i][j];
      } else {
        cout << input[i][j] << " ";
      }
    }
    cout << endl;
  }
}

void inf(vector<vector<int>> &input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      if (input[i][j] == -1) {
        input[i][j] = 100000;
      }
    }
  }
}

// Dijkstra (DJ)
void dijkstra_solution(int start, vector<int> c, vector<int> p) {
  if (start == 0) {
    cout << "Dijkstra :" << endl;
  }
  int noVertices = c.size();
  for (int index = 0; index < noVertices; index++) {
    if (index != start) {
      cout << "node " << start + 1 << " to node " << index + 1 << " : " << c[index] << endl;
    }
  }
}

void dijkstra(vector<vector<int>> matrix, int node) {
  int noVertices = matrix[0].size();
  vector<int> c(noVertices);
  vector<int> p(noVertices);
  vector<bool> add_cond(noVertices);

  for (int index = 0; index < noVertices; index++) {
    c[index] = 100000;
    add_cond[index] = false;
  }

  c[node] = 0; 
  p[node] = -1;

  for (int i = 1; i < noVertices; i++) {
    int next = -1;
    int dis = 100000;
    for (int index = 0; index < noVertices; index++) {
      if (!add_cond[index] && c[index] < dis) {
        next = index;
        dis = c[index];
      }
    }
    add_cond[next] = true;

    for (int index = 0; index < noVertices; index++) {
      int end = matrix[next][index];

      if (end > 0 && ((dis + end) < c[index])) {
        p[index] = next;
        c[index] = dis + end;
      }
    }
  }
  dijkstra_solution(node, c, p);
}

// Floyd – Warshall (FW)
void floyd_w(vector<vector<int>> matrix) {
  int nodes = matrix.size();
  for (int k = 0; k < nodes; k++) {
    for (int i = 0; i < nodes; i++) {
      for (int j = 0; j < nodes; j++) {
        matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
      }
    }
  }
  cout << "Floyd :" << endl;
  print(matrix);
}

int main(int argc, char *argv[]) {
  // Declaration of variables
  vector<vector<int>> matrix;
  int n, nodes;

  // Reading input data
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> aux;
    for (int j = 0; j < n; j++) {
      cin >> nodes;
      aux.push_back(nodes);
    }
    matrix.push_back(aux);
  }

  // Resolution code - Dijkstra
  for (int i = 0; i < matrix.size(); i++) {
    dijkstra(matrix, i);
  }

  // Resolution code - Floyd
  cout << endl;
  inf(matrix); floyd_w(matrix);

  return 0;
}