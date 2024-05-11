// =========================================================
// File: main.cpp
// Authors:
//  Ana Karen López Baltazar - A01707750
// Date: 29/09/2022
// Description:
//          Algorithm:
//          ■ Graph Coloring using Adjacency Matrix
//
//          Big-O Complexity Analysis:
//          ■ WPV - Welsh Powell [Variation]: O(n³)
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
#include <queue>

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

vector<int> degree(vector<vector<int>> input) {
    int size = input.size();
    vector<int> result(size, 0);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(input[i][j] == 1) {
                result[i]++;
            } 
        }
    }
    return result;
}

void pairsort(vector<int> &a, vector<int> &b, int n) {
    pair<int, int> pairt[n];
  
    // Storing the respective array
    // elements in pairs.
    for (int i = 0; i < n; i++) {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }
  
    // Sorting the pair array.
    sort(pairt, pairt + n);
      
    // Modifying original arrays
    for (int i = 0; i < n; i++) {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}

void coloringC(vector<vector<int>> &m, int n, int p, int color) {
    for (int r = 0; r < n; r++) {
        if (m[r][p] >= 1) {
            m[r][p] = color + 5;
        }

        if (m[p][r] >= 1) {
            m[p][r] = color + 5;
        }
    }
}

// Welsh Powell [Variation] - WPV
vector<int> welshP(vector<vector<int>> matrix) {
    int nodes = matrix.size();
    int colorAssigned = 0;
    vector<int> color(nodes, -1);

    // Sort vertices by degree
    vector<int> v(nodes, 0);
    for (int i = 1; i < nodes; i++) {v[i] = i;}
    vector<int> d = degree(matrix);

    // Function calling
    pairsort(d, v, nodes);
    reverse(d.begin(), d.end());
    reverse(v.begin(),v.end());
          
    // Graph Coloring
    for (int i = 0; i < nodes; i++) {
        if(color[i] == -1){
            // Color Vertex
            colorAssigned++;
            color[i] = colorAssigned;

            // Modifications in [colored vertex] connections 
            coloringC(matrix, nodes, v[i], colorAssigned);
 
            // Coloring remaining vertices [IF]
            for (int k = i + 1; k < nodes; k++) {
                if (color[k] == -1) {
                    bool colorIt = true;
                    for (int c = 0; c < nodes; c++) {
                        if (matrix[v[k]][c] == (colorAssigned + 5)) {
                            colorIt = false;
                        }
                    }
                    
                    // IF not colored/ not connected 
                    // to another [node] with Assignedcolor
                    if (colorIt) {
                        color[k] = colorAssigned;
                        coloringC(matrix, nodes, v[k], colorAssigned);
                    }
                }
            }
        }
    }

    pairsort(v, color, nodes);
    return color;
}

// Graph coloring using adjacency matrix
int main(int argc, char *argv[]) {
    // Declaration of variables
    vector<vector<int>> matrix;
    int n, nodes;

    // Reading input data [Adjacency Matrix]
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> aux;
        for (int j = 0; j < n; j++) {
        cin >> nodes;
        aux.push_back(nodes);
        }
        matrix.push_back(aux);
    }

    // Welsh Powell [Variation]
    vector<int> result = welshP(matrix);

    // Show results
    for (int j = 0; j < n; j++) {
        cout << "Node " << j << " <-> Color " << result[j] << endl;
    }

    return 0;
}