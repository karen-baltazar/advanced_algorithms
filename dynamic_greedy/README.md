## Coin Change Problem Solver

This program is designed to solve the coin change problem using Dynamic Programming and Greedy Algorithms techniques.

### Problem Description
The coin change problem involves finding the minimum number of coins required to make change for a given amount of money. Given a set of coin denominations and a target amount, the goal is to determine the minimum number of coins needed to make up that amount.

### Input
The program expects the following input:
- An integer, *N*, representing the number of different coin denominations available.
- *N* integer values representing the available coin denominations.
- An integer, *Q*, representing the number of queries.
- *Q* integer values representing the changes to be calculated.

### Output
For each query, the program will display:
- The number of coins required using the Greedy solution.
- The number of coins required using the Dynamic Programming solution.
- The number of coins of the required denomination, sorted from least to greatest.

## Time Complexity
- Greedy Algorithm: O(n log n), where n is the number of coin denominations
- Dynamic Programming Algorithm: O(n * c), where n is the number of coin denominations and c is the target amount of change

### Usage
To compile the program, use the following command:
`g++ -std=c++11 main.cpp -o app`

To execute the program, run:
`./app < inputX.txt > resultX.txt`

To verify the correctness of the output, you can use the `diff` command:
`diff resultX.txt outputX.txt`

If no output is shown, the results are as expected.

