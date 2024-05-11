// =========================================================
// File: main.cpp
// Authors:
//  Ana Karen López Baltazar - A01707750
// Date: 02/09/2022
// Description:
//          Big-O Complexity Analysis:
//          ■ main(): O(n*m)
//          ■ convert(): O(n)
//          ■ ASCIISum(): O(n)
//
//          Execution Command (Linux Shell):
//          ■ g++ -std=c++11 main.cpp -o app
//          ■ ./app < inputX.txt > resultX.txt
//          ■ diff resultX.txt outputX.txt
// =========================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// Auxiliary Functions -----------------------------

// Print Matrix (char)
void print(vector<vector<char>> input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
        if(input[i][j] == '\n') {
            cout << "\\n";
        } else {
            cout << input[i][j];
        }
    }
    cout << endl;
  }
}

// Conversion to UPPERCASE
void convert(string& str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = toupper(str[i]);
    }
}

// ASCII Sum (string)
int ASCIISum(string str) {
    int ASCII_sum = 0;
    int size = str.size();

    for (int i = 0; i < size; i++) {
        ASCII_sum += str[i];
    }

    return ASCII_sum;
}

// Main Function -------------------------------------
int main(int argc, char* argv[]) {
    // Variable Declarations
    vector<vector<char>> matrix;
    string filename; cin >> filename; 
    int n; cin >> n;

    // File Reading
    ifstream file(filename);
    string str, file_contents;

    vector<int> txt;
    char c;
    while (file.get(c)) {
        txt.push_back(c);
    }
    
    file.close();

    // Characters in a Matrix
    int size = txt.size();

    for (int i = 0; i < size; i++){
        vector<char> aux;
        for (int j = 0; j < n; j++) {
            if (i >= size) {
                aux.push_back(char(n));
            } else {
                aux.push_back(txt[i]);
            }

            if(j + 1 < n){
               i++; 
            }
        }
        matrix.push_back(aux);
    }

    // Hash Function
    int msize = matrix.size();
    vector<int> ascii;

    for (int i = 0; i < msize; i++) {
        vector<char> v = matrix[i];
        string str(v.begin(), v.end());

        ascii.push_back((ASCIISum(str) % 256));
    }

    // Results
    stringstream res;
    string in;

    for (int i = 0; i < msize; i++) {
        stringstream inter;
        inter << hex << ascii[i];
        if ((inter.str()).size() == 1) {
            res << "0";
            res << hex << ascii[i];
        } else {
            res << hex << ascii[i];
        }
    }
    
    string r = res.str();
    convert(r);
    cout << r;

    return 0;
}