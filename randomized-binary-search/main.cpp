// =========================================================
// File: main.cpp
// Authors:
//  Ana Karen López Baltazar - A01707750
// Date: 10/11/2022
// Description:
//          Big-O Complexity Analysis:
//          ■ ABS - Binary Search: O(log n)
//          ■ RBS - Randomized Binary Search: O(log n)
//
//          Execution Command (Linux Shell):
//          ■ g++ -std=c++11 main.cpp -o app
//          ■ ./app < inputX.txt > resultX.txt
//          ■ diff resultX.txt outputX.txt
// =========================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

// Binary Search - ABS
int binarySearch(vector<int> &v, int key) {
	int low, high, mid, sb;

	low = 0; sb = 0;
	high = v.size() - 1;

	while (low <= high) {
        sb++;
		mid = low + ((high - low) / 2);
		if (key == v[mid]) {
			return sb;
		} else if (key < v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
    return -1;
}

// Randomized Binary Search - RBS
int sr = 0; 
int randomizedSearch(vector<int> &v, int left, int right, int key) {
    srand(time(NULL)); sr++;

    if (right >= left) {
        // Random index between [left, right]
        int mid = rand() % (right - left + 1) + left;
    
        // If element is present at mid
        if (v[mid] == key) {
            return sr;
        }
            
        // If element is smaller than mid
        if (v[mid] > key) {
            return randomizedSearch(v, left, mid-1, key);
        }
        
        // Else the element present in right subarray
        return randomizedSearch(v, mid+1, right, key);
    }

    return -1;
}

// Binary and Randomized Binary Search
int main(int argc, char *argv[]) {
    // Declaration of variables
    int n, q, c;
    
    // Reading input data
    cin >> n;
    vector<int> v(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> c;
        v[i] = c;
    }

    sort(v.begin(), v.end());

    cin >> q;
    vector<int> k(n, 0);

    for (int i = 0; i < q; i++) {
        cin >> c;
        k[i] = c;
    }

    // Results
    for (int i = 0; i < q; i++) {
        cout << "number = " << k[i];
        cout << " using binary search = " << binarySearch(v, k[i]);
        cout << ", using randomize binary search = " << randomizedSearch(v, 0, n-1, k[i]) << endl; sr = 0;
    }

    return 0;
}