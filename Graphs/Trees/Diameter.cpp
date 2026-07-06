  // Finding tree diameter using tree dp in O(N)
  int ans = 0;
  auto dfs = [&](auto &&self, int u, int p) -> int {
    int mx = 0, smx = 0;

    for (auto v : adj[u]) {
      if (v == p) continue;

      int d = self(self, v, u) + 1;
      if (d > mx) {
        smx = mx;
        mx = d;
      } else if (d > smx) {
        smx = d;
      }
    }
    ans = max(ans, mx + smx);
    return mx;
  };
  dfs(dfs, 0, -1);
