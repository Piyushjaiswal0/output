#include <bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> adj, int visited[], vector<int> &ls){
  
  visited[node] = 1;
  ls.push_back(node);
  
  for(auto i: adj[node]){
    if(visited[i]==0){
      dfs(i,adj,visited,ls);
    }
  }
  
}

int main() 
{
    vector<vector<int>> adj = {
        {1, 2},      
        {0, 4, 5},  
        {0, 3, 6},    
        {2, 7},   
        {1},      
        {1},
        {2,7}, 
        {3,6}
    };
    
    int n = adj.size();
    int visited[7] ={0};
    vector<int > ls;
    int node = 0;
    dfs(node,adj,visited,ls);
    
    for(auto p:ls){
      cout<<p<<" ";
    }
}