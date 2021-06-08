#include <bits/stdc++.h>
using namespace std;

void print_order(vector<pair<string, string> > &info, int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        // taking input of n people and p pair
        int n, p;
        cin >> n >> p;
        // array of pair of string
        vector<pair<string, string> > info;
        
        while (p--) {
            // input two space seprated string 
            string a, b;
            cin >> a >> b;
            // array of pair
            info.push_back(pair<string, string>(a, b));
        }
        // order print function
        print_order(info, n);
        cout << endl;
    }
    return 1;
}
// } Driver Code Ends


// User function Template for C++
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}
 
// A utility function to do DFS of graph
// recursively from a given vertex u.
void topologicalSortUtil(vector<int> adj[],int v, bool visited[],
                                stack<int>& Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    vector<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(adj,*i, visited, Stack);
 
    // Push current vertex to stack
    // which stores result
    Stack.push(v);
}
 
// The function to do Topological Sort.
// It uses recursive topologicalSortUtil()
void topologicalSort(vector<int> adj[],int V, map<int,string> mapname)
{
    stack<int> Stack;
 
    // Mark all the vertices as not visited
    bool* visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function
    // to store Topological
    // Sort starting from all
    // vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(adj,i, visited, Stack);
 
    // Print contents of stack
    while (Stack.empty() == false) {
        cout << mapname[Stack.top()+1] << " ";
        Stack.pop();
    }
}
 
 
void print_order(vector<pair<string, string> > &info, int n) {
    vector<int> adj[n];
    map<string,int> mapname;
    int fl=1;
    for(int i=0;i<info.size();i++){
        if(mapname[info[i].first]==0){
            mapname[info[i].first]=fl;
            ++fl;
           // cout<<info[i].first<<mapname[info[i].first]<<endl;
        }
        if(mapname[info[i].second]==0){
            mapname[info[i].second]=fl;
            ++fl;
            //cout<<info[i].first<<mapname[info[i].first]<<endl;
        }
    }
    for(int i=0;i<info.size();i++){
        addEdge(adj,mapname[info[i].first]-1,mapname[info[i].second]-1);
    }
    map<int,string> mapn;
    map<string,int>::iterator it;
    for(it=mapname.begin();it!=mapname.end();it++){
        mapn[it->second]=it->first;
        //cout<<it->second<<" "<<it->first<<endl;
    }
    
    topologicalSort(adj,n,mapn);
}

