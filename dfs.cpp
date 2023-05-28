#include <iostream>
#include <list>
#include <vector>

class Graph {
    int vertices;
    std::vector<bool> visited;
    std::list<int> *adjList;

public:
    Graph(int V) {
        vertices = V;
        visited.resize(vertices, false);
        adjList = new std::list<int>[vertices];
    }

    void addEdge(int v, int w) {
        adjList[v].push_back(w);
    }

    void DFS(int v)
	{
        visited[v] = true;
        std::cout << v << " ";

        std::list<int>::iterator i;
        for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
		{
            if (!visited[i])
			{
                DFS(*i);
            }
        }
    }
};

int main() {
    Graph graph(6);  // Create a graph with 6 vertices

    // Add edges between vertices
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    std::cout << "Depth First Traversal (starting from vertex 0): ";
    graph.DFS(0);

    return 0;
}