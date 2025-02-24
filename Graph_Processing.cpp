#include <iostream>
#include <vector>

using namespace std;

class Graph
{
private:
    int numNodes;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int n)
    {
        numNodes = n;
        adjacencyMatrix = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(int i, int j)
    {
        adjacencyMatrix[i][j] = 1;
        adjacencyMatrix[j][i] = 1;
    }

    int getDegree(int node) const
    {
        int degree = 0;
        for (int i = 0; i < numNodes; ++i)
        {
            degree += adjacencyMatrix[node][i];
        }
        return degree;
    }

    int getMaxDegreeNode() const
    {
        int maxDegree = getDegree(0);
        int maxDegreeNode = 0;

        for (int i = 1; i < numNodes; ++i)
        {
            int degree = getDegree(i);
            if (degree > maxDegree)
            {
                maxDegree = degree;
                maxDegreeNode = i;
            }
        }

        return maxDegreeNode;
    }

    int getMinDegreeNode() const
    {
        int minDegree = getDegree(0);
        int minDegreeNode = 0;

        for (int i = 1; i < numNodes; ++i)
        {
            int degree = getDegree(i);
            if (degree < minDegree)
            {
                minDegree = degree;
                minDegreeNode = i;
            }
        }

        return minDegreeNode;
    }

    void displayMatrix() const
    {
        for (int i = 0; i < numNodes; ++i)
        {
            for (int j = 0; j < numNodes; ++j)
            {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<int> getNeighbors(int node) const
    {
        vector<int> neighbors;
        for (int i = 0; i < numNodes; ++i)
        {
            if (adjacencyMatrix[node][i] == 1)
            {
                neighbors.push_back(i);
            }
        }
        return neighbors;
    }
};

int main()
{
    int nodes;
    double density;

    cout << "********** Graphs manipulation **********" << endl;
    cout << "MADE BY MUAZZAM SHAH \n";

    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the density of the graph (in percentage): ";
    cin >> density;

    Graph myGraph(nodes);

    int desiredEdges = static_cast<int>(0.5 * density * nodes * (nodes - 1) / 100);

    // Fill the graph with edges based on the desired density
    for (int i = 0; i < nodes; ++i)
    {
        for (int j = i + 1; j < nodes; ++j)
        {
            if (desiredEdges > 0)
            {
                myGraph.addEdge(i, j);
                desiredEdges--;
            }
        }
    }

    int choice;
    do
    {
        cout << "\n********** Menu **********" << endl;
        cout << "1. Show node degree\n"
             << "2. Find node with maximum degree\n"
             << "3. Find node with minimum degree\n"
             << "4. Display raw adjacency matrix\n"
             << "5. Find neighbors of a node\n"
             << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int nodeToShowDegree;
            cout << "Enter a node to show its degree: ";
            cin >> nodeToShowDegree;
            cout << "Degree of node " << nodeToShowDegree << ": " << myGraph.getDegree(nodeToShowDegree) << endl;
            break;
        }
        case 2:
        {
            cout << "Node with maximum degree: " << myGraph.getMaxDegreeNode() << endl;
            break;
        }
        case 3:
        {
            cout << "Node with minimum degree: " << myGraph.getMinDegreeNode() << endl;
            break;
        }
        case 4:
        {
            cout << "Raw adjacency matrix:" << endl;
            myGraph.displayMatrix();
            break;
        }
        case 5:
        {
            int nodeToFindNeighbors;
            cout << "Enter a node to find its neighbors: ";
            cin >> nodeToFindNeighbors;

            vector<int> neighbors = myGraph.getNeighbors(nodeToFindNeighbors);
            cout << "Neighbors of node " << nodeToFindNeighbors << ": ";
            for (int neighbor : neighbors)
            {
                cout << neighbor << " ";
            }
            cout << endl;
            break;
        }
        case 6:
            cout << "MADE BY MUAZZAM SHAH & ABDUL MUEED KHAN \n";
            cout << "";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 6);

    return 0;
}
