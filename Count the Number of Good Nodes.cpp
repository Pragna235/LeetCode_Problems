#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int dfs(int node, vector<vector<int>>& adj, vector<int>& subtreeSize, int parent) {
        int size = 1;  // Start with size 1 for the current node
        unordered_set<int> childSizes;  // To store the sizes of the child subtrees
        
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;  // Avoid traversing back to the parent
            
            int childSubtreeSize = dfs(neighbor, adj, subtreeSize, node);
            size += childSubtreeSize;
            childSizes.insert(childSubtreeSize);
        }
        
        subtreeSize[node] = size;
        
        // If the node has children and all children's subtrees have the same size
        if (childSizes.size() <= 1) {
            goodNodeCount++;
        }
        
        return size;
    }
    
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;  // Correctly calculate the number of nodes
        vector<vector<int>> adj(n);  // Adjacency list with n nodes
        
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> subtreeSize(n, 0);
        goodNodeCount = 0;
        dfs(0, adj, subtreeSize, -1);  // Start DFS from node 0, root
        
        return goodNodeCount;
    }
    
private:
    int goodNodeCount;
};
