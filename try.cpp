#include<iostream>
#include<bits\stdc++.h>
using namespace std;
class Graph
{
    public:
    map<int ,bool> visited;
    map<int ,list<int>> adj;
   void addedge(int v,int w);
   void dfs(int v);
};
void Graph::addedge(int v,int e)
{
   adj[v].push_back(e);
}
void Graph::dfs(int v)
{
   //make the first vertex as visited and print it;
   visited[v]=true;
   cout<<v<<"  ";
   //loop that will perform actual dfs traversal
   list<int> :: iterator i;
   for(i=adj[v].begin();i!=adj[v].end();i++)
   {
     if(!visited[*i])
     {
        dfs(*i);
      }
    }
}
int main()
{
   Graph g;
   int vertex,edge,start;
   cout<<"enter the no of vertices";
   cin>>vertex;
   cout<<"enter the no of edges";
   cin>>edge;
   int v,w;
   for(int i=0;i<edge;i++)
   {
     cin>>v>>w;
     g.addedge(v,w);
   }
   cout<<"enter the starting vertex"<<endl;
   cin>>start;
   g.dfs(start);
return 0;
}


s