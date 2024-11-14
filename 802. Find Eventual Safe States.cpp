class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& pre) {
        int n = pre.size();
        vector<int> adj[n];
        vector<int> topo;
        queue<int> q;
        vector<int> inDegree(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < pre[i].size(); j++)
                adj[pre[i][j]].push_back(i);
        }

        for(int i = 0; i < n; i++){
            for(auto it : adj[i])
                inDegree[it]++;
        }

        for(int i = 0; i < n; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(auto it : adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0)
                    q.push(it);
            }
        }
        sort(topo.begin(), topo.end());

        return topo;       
    }
};
