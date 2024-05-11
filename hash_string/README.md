## Hash String CRC Generator
This program generates a cyclic redundancy check (CRC) code for a text file using a hashing function. CRC is an error-detection code frequently used in digital networks and storage devices to detect accidental changes in data. In this case, a hash function is employed to generate this code.

### Problem Description
The program generates a CRC code for a given text file by applying a hashing function. The CRC code is a hexadecimal representation of the hashing result, which is computed by summing the ASCII values of characters in each row of the text file and applying modular arithmetic.

### Input
The program expects the following input:
- The name of a text file.
- An integer, *N*, which is a multiple of 4, representing the desired length of the CRC code.

### Output
The output is a hexadecimal string representing the CRC code of the text file. The string is generated by applying a hashing function to each row of the text file and concatenating the hexadecimal representations of the hash values.

### Time Complexity
The time complexity of the CRC generation code is O(n * m), where n is the number of characters in the file and m is the size of the matrix generated to apply the hash function.

### Usage
To compile the program, use the following command:
`g++ -std=c++11 main.cpp -o app`

To execute the program, run:
`./app < inputX.txt > resultX.txt`

To verify the correctness of the output, you can use the `diff` command:
`diff resultX.txt outputX.txt`

If no output is shown, the results are as expected.