## Randomized Binary Search Algorithm
This program implements the Randomized Binary Search Algorithm to determine if an integer is in a set of integers. It utilizes the Las Vegas Randomized Algorithm method, a technique commonly employed in randomized algorithms.

### Problem Description
The Randomized Binary Search Algorithm involves searching for a target integer in a sorted array by repeatedly dividing the search interval in half. It uses randomization to select a pivot element.

### Input
The program expects the following input:
- An integer, N, indicating the number of integers to read.
- N integers representing the set of integers.
- An integer, Q, indicating the number of integers to search for.
- Q integers to search for.

### Output
The program should display the number of searches performed using traditional binary search and the number of searches performed using the randomized binary search algorithm. If a search does not find the number, it should return -1.

### Time Complexity
- Binary Search: O(log n)
- Randomized Binary Search: O(log n)

### Usage
To compile the program, use the following command:
`g++ -std=c++11 main.cpp -o app`

To execute the program, run:
`./app < inputX.txt > resultX.txt`

To verify the correctness of the output, you can use the `diff` command:
`diff resultX.txt outputX.txt`

If no output is shown, the results are as expected.