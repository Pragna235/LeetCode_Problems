class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<pair<int, int>> v;
        for (auto& i : points) v.emplace_back(-i[0], i[1]);
        sort(v.begin(), v.end());
        int res = 0;
        for (int i=0; i<v.size(); i++) {
            set<int> cur;
            for (int j=i+1; j<v.size(); j++) {
                if (v[i].second <= v[j].second) {
                    auto it = cur.lower_bound(v[i].second);
                    if (it == cur.end() || *it > v[j].second) res++;
                }
                
                cur.insert(v[j].second);
            }
        }
        return res;
    }
};
