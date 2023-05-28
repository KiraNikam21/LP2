#include<iostream>
using namespace std;

int isVisited(bool visited[], int vertex)
{
	for (int i = 0; i < vertex; i++)
	{
		if (visited[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int vertex = 5;
	int graph[][5] = {
		{0,10,0,0,30},
		{10,0,40,0,0},
		{0,40,0,50,0},
		{0,0,50,0,20},
		{30,0,0,20,0}
	};


	for (int i = 0; i < vertex; i++)
	{
		for (int j = 0; j < vertex; j++)
		{
			cout << graph[i][j] << " ";
		}
		cout << endl;
	}

	bool visited[5];
	int shortest[5];

	for (int i = 0; i < vertex; i++)
	{
		shortest[i] = 1000;
	}

	int ver = 0, cost = 0;
	shortest[ver] = 0;
	visited[ver] = 1;

	for (int i = 1; i < vertex; i++)
	{
		visited[i] = 0;
	}

	while (isVisited(visited, vertex))
	{
		visited[ver] = 1;

		for (int i = 0; i < vertex; i++)
		{
			if (graph[ver][i] != 0 && shortest[i] > (graph[ver][i] + cost))
			{
				shortest[i] = graph[ver][i] + cost;
			}
		}
		int min = 10000;
		int minIndex = 0;
		for (int i = 0; i < vertex; i++)
		{
			if (shortest[i] < min && visited[i] == 0)
			{
				min = shortest[i];
				minIndex = i;
			}
		}
		ver = minIndex;
		cost = min;
	}

	cout << "Shortest Paths:" << endl;
	for (int i = 0; i < vertex; i++)
	{
		cout << i << "->" << shortest[i];
		cout << endl;
	}

	return 0;
}
