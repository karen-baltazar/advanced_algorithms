// =========================================================
// File: main.cpp
// Authors:
//  Ana Karen López Baltazar - A01707750
// Date: 20/08/2022
// Description:
//          Big-O Complexity Analysis:
//          ■ GR - Coin Change: O(n)
//          ■ DP - Coin Change: O(n*c)
//
//          Execution Command (Linux Shell):
//          ■ g++ -std=c++11 main.cpp -o app
//          ■ ./app < inputX.txt > resultX.txt
//          ■ diff resultX.txt outputX.txt
// =========================================================
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// Auxiliary Functions -------------------------------------
void print(vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        cout << input.at(i) << ' ';
    }
}

int get_min(int a, int b){
    if (a < 0 && b > 0) {
        return b;
    } 
    else if (b < 0 && a > 0) {
        return a;
    } 
    else { 
        return min(a, b); 
    }
}

// GR - Coin Change ----------------------------------------
void coin_change_gr(int c, vector<int> s) {
    // Calculation of coins to return
    stringstream ss; ss << "";
    int min = 0; int aux = 0; 
    for(int i = 0; i < s.size(); i++) {
        min += c / s[i];
	 	c %= s[i];
        if(min > aux) {
            string temp = ss.str(); ss.seekp(0);
            ss << "CURRENCY = " << s[i] << " AMOUNT = " << min - aux << endl;
            ss << temp;
            aux = min;
        }
    }

    // Results
    cout << "GREEDY SOLUTION, TOTAL COINS = " << min << endl;
    cout << ss.str() << endl;
}

// DP - Coin Change ----------------------------------------
void coin_change_dp(int c, vector<int> s, int n) {
    // Vector of possible change forms
    int c1 = c; vector<int> aux, result;
    for (int i = 0; i <= c; i++) { // O(n)
        aux.push_back(INT_MAX);
	}

    aux[0] = 0;
    for(int i = 1; i <= c; i++) { // O(n*c)
        for(int j = 0; j < n; j++) {
            if (s[j] <= i) {
                // current_c = min(current_c, 1 + (previous_c - coin))
                aux[i] = get_min(aux[i], 1 + aux[i - s[j]]);
            }
        }
        result.push_back(0);
    }

    // Cálculo de monedas a regresar
    float e_coin = (float)c1 / (float)aux[c1];
    bool f = remainder(e_coin, 1) == 0;

    vector<int>::iterator ec = find(s.begin(), s.end(), e_coin);

    if (ec != s.end() && f == true) {
        int index = distance(s.begin(), ec);
        result[index] = aux[c1];    
    } 
    else {
        for(int i = (c - 1); i >= 0; i--) { // O(n*c)
            if(aux[i] == (aux[c] - 1)) {
                int coin = c - i;
                vector<int>::iterator it = find(s.begin(), s.end(), coin);

                if (it != s.end()) {
                    int index = distance(s.begin(), it);
                    result[index]++; c = i;
                }
            }
        }
    }

    // Results
    stringstream ss; ss << "";
    for(int i = 0; i < n; i++) { // O(n)
        if(result[i] > 0) {
            string temp = ss.str(); ss.seekp(0);
            ss << "CURRENCY = " << s[i] << " AMOUNT = " << result[i] << endl;
            ss << temp;
        }
    }

    cout << "DP SOLUTION, TOTAL COINS = " << aux[c1] << endl;
    cout << ss.str();
}

int main(int argc, char* argv[]) {

	// Data Reading -----------------------------------------
    int n, coin, q, change; // Variables
    vector<int> s, c;

    cin >> n; // Coin denominations
    for (int i = 0; i < n; i++){ // Coin array
        cin >> coin; s.push_back(coin);
    }

    sort(s.begin(), s.end(), greater<int>()); // O(n*log2(n))

    cin >> q; // Number of queries
    for (int i = 0; i < q; i++){ // Change array
        cin >> change; c.push_back(change);
    }

    // Results ----------------------------------------------
    for(int i = 0; i < q; i++) {
        cout << "QUERY #" << i+1 << ", CHANGE = " << c[i] << endl;
        coin_change_gr(c[i], s);
        coin_change_dp(c[i], s, n);
        cout << "---------" << endl;	
    }

	return 0;
}