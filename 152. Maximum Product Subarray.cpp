class Solution {
public:
  int maxProduct(vector<int>& A) {
    int n = A.size();
    double ans = INT_MIN;
    double pr = 1, su = 1;
    for (int i=0; i<n; ++i) {
      pr *= A[i];
      su *= A[n-1-i];
      ans = max({ans, pr, su});
      if (pr == 0) pr = 1;
      if (su == 0) su = 1;
    }
    return ans;
  }
};
