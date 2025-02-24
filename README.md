# Graph Processing & Manipulation Project

## Overview

This project is a C++ application that allows users to create and manipulate an undirected graph using an adjacency matrix. It provides various functionalities to analyze the graph, such as computing node degrees, identifying nodes with the maximum or minimum degree, displaying the raw adjacency matrix, and finding the neighbors of a specific node. The project is designed with an interactive menu-driven interface for ease of use.

## Features

- **Graph Creation:**  
  - Users can specify the number of nodes in the graph.
  - Users can define the graph density (in percentage) to control how many edges are added.

- **Edge Manipulation:**  
  - Adds undirected edges between nodes based on the desired density.

- **Graph Analysis:**  
  - **Node Degree:** Compute and display the degree of any node.
  - **Maximum Degree Node:** Identify the node with the highest degree.
  - **Minimum Degree Node:** Identify the node with the lowest degree.
  - **Adjacency Matrix Display:** Output the raw adjacency matrix representing the graph.
  - **Neighbors Retrieval:** List all the neighboring nodes for a given node.

- **Interactive Menu:**  
  - A user-friendly menu allows users to select the operation they wish to perform on the graph.

## Project Structure

- **Graph Class:**  
  The `Graph` class encapsulates the graph's properties and operations. Key member functions include:
  - `addEdge(int i, int j)`: Adds an edge between nodes `i` and `j`.
  - `getDegree(int node) const`: Returns the degree of the specified node.
  - `getMaxDegreeNode() const`: Finds and returns the node with the maximum degree.
  - `getMinDegreeNode() const`: Finds and returns the node with the minimum degree.
  - `displayMatrix() const`: Prints the graph's adjacency matrix.
  - `getNeighbors(int node) const`: Returns a list of neighbors for the specified node.

- **Main Function:**  
  The `main()` function handles user input for graph configuration (number of nodes and density), creates the graph, and presents an interactive menu for performing various graph operations.

## How to Compile and Run

### Prerequisites

- A C++ compiler (e.g., g++)

### Compilation

Open a terminal in the project directory and run the following command:

```bash
g++ -o GraphManipulation main.cpp
```

### Execution

Run the compiled executable:

```bash
./GraphManipulation
```

Upon running, the application will prompt you to enter:
- The number of nodes for the graph.
- The density of the graph (as a percentage).

After entering the required information, an interactive menu will be displayed, allowing you to perform operations such as viewing node degrees, finding nodes with maximum/minimum degree, displaying the adjacency matrix, or finding the neighbors of a specific node.
