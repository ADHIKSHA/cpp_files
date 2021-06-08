// C++ program to print connected components in
// an undirected graph
#include <iostream>
#include <list>
using namespace std;

// Graph class represents a undirected graph
// using adjacency list representation
class Graph {
	int V; // No. of vertices

	// Pointer to an array containing adjacency lists
	list<int>* adj;
	// A function used by DFS
	void DFSUtil(int v, bool visited[],int arr[],int &sum);

public:
	Graph(int V); // Constructor
	~Graph();
	void addEdge(int v, int w);
	int connectedComponents(int arr[]);
};

// Method to print connected components in an
// undirected graph
int Graph::connectedComponents(int arr[])
{
	// Mark all the vertices as not visited
	int max=INT_MIN;
	bool* visited = new bool[V];
	for (int v = 0; v < V; v++)
		visited[v] = false;

	for (int v = 0; v < V; v++) {
		if (visited[v] == false) {
			// print all reachable vertices
			// from v
			int sum=0;
			DFSUtil(v, visited,arr,sum);
			if(sum>max)max=sum;
			//cout << "\n";
		}
	}
	delete[] visited;
	return max;
}

void Graph::DFSUtil(int v, bool visited[],int arr[],int &sum)
{
	// Mark the current node as visited and print it
	visited[v] = true;
//	cout << v << " ";
	sum+=arr[v];
	// Recur for all the vertices
	// adjacent to this vertex
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
		if (!visited[*i])
			DFSUtil(*i, visited,arr,sum);
}

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

Graph::~Graph() { delete[] adj; }

// method to add an undirected edge
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

// Driver code
int main()
{
	// Create a graph given in the above diagram
	int n,w;
	cin>>n;
	int arr[n];
	Graph g(n); // 5 vertices numbered from 0 to 4
	for(int i=0;i<n;i++){
		cin>>arr[i];
		
	}
	int p;
	cin>>p;
	int a,b;
	for(int i=0;i<p;i++){
		cin>>a>>b;
		g.addEdge(a-1, b-1);
	}

//	cout << "Following are connected components \n";
	int max=g.connectedComponents(arr);
	cout<<max;
	return 0;
}

