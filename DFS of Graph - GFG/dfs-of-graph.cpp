//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfsTraversal;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, dfsTraversal);
            }
        }

        return dfsTraversal;
    }

private:
    void dfs(int node, vector<bool>& visited, vector<int> adj[], vector<int>& dfsTraversal) {
        visited[node] = true;
        dfsTraversal.push_back(node);

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, dfsTraversal);
            }
        }
    }
};
  

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends