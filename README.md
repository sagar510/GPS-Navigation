
## Introduction

Dijkstra's algorithm is a widely-used algorithm for finding the shortest path in a graph. This program is designed to find the shortest path in a directed graph where each edge has an associated cost. It takes user input to define the graph's structure and then calculates the shortest path between a specified source and destination node.

## Usage

### Input Format

The program expects the following input format:

1. The number of nodes with zero indegree (starting nodes).
2. A list of starting nodes.
3. The total number of nodes in the graph.
4. For each node, the program expects the following information:
   - Node data (an integer).
   - The number of nodes it is connected to (in_degree).
   - For each connected node, the following details are required:
     - Connected node data.
     - The cost associated with the connection.

### Running the Program

1. Compile the program using a C++ compiler, for example:
   ```sh
   g++ -o dijkstra dijkstra.cpp
   ```

2. Run the compiled program:
   ```sh
   ./dijkstra
   ```

3. Follow the prompts to input the graph structure, source node, and destination node.

4. The program will calculate and display the shortest path between the source and destination nodes.

## Algorithm Explanation

Dijkstra's algorithm is used to calculate the shortest path from the source node to the destination node in a directed graph. It explores all possible paths, backtracking when it reaches a dead end. The program uses a custom depth-first search (DFS) function to find nodes with specific data values within the graph.

## Assumptions

- The code assumes that both the source and destination nodes are present in the graph.
- The input format must be correct for the program to function accurately.

## Code Structure

- The code uses custom data structures (`struct Node` and `struct Graph`) to represent nodes and the graph structure.
- It defines a `shortestPath` function to initiate the shortest path calculation.
- The program includes a custom depth-first search (DFS) function to find nodes within the graph.
- The main function orchestrates the input, graph construction, and shortest path calculation.

## Improvements

- The code lacks proper error handling and user-friendly prompts. It could be enhanced to provide clear instructions and handle erroneous input.
- Memory management should be improved, ensuring that memory allocated for nodes is freed when no longer needed.

## Contributing

Contributions to this project are welcome. If you find issues, have suggestions for improvements, or would like to contribute code enhancements, please follow the code of conduct and guidelines for contributors.

## License

This program is open-source and distributed under the MIT License. You are free to use, modify, and distribute it according to the terms of the license.

Enjoy using Dijkstra's algorithm for finding the shortest path in your directed graph!
