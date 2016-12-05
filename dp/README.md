* Memorized DP : recursion + memorization + _guessing_(choose best among different subproblems)
* Bottom-up DP : __topological sort__ of subproblem dependency DAG, no recursion and can save space.
* Bellman-Ford Algorithm, a DP approach to find shortest path in G. G can have negative edge costs. While Dijkstra's Algorithm can only be applied in graphs with positive edge costs.
    * Dijkstra's recall
        * maintain a set of S of vertices u for which we have determined a shortest-path distance d(u) from s; Initially S = {s}, and d(s) = 0.
        * calculate all d(v)s according to d(s)+l(s,v) which v are not in S and are neighbours of selected node s in S, update d(v) for these nodes. choose smallest in G-S as the new selected node.
        * repeat above process until all nodes of G are in S.
    * Bellman-Ford
        * if G has no negative cycles, then there is a shortest path from s to t that is simple(i.e., does not repeat nodes), and hence has at most n-1 edges.
        * Use OPT(i,v) denote the minimum cost of a v-t path using at most i edges.
            * OPT(i,v) = OPT(i-1,v) , if path P uses at most i-1 edges
            * OPT(i,v) = l(v,w) + OPT(i-1,w) , if path P uses i edges, and the first edge is (v,w).
            * OPT(i,v) = min(OPT(i-1,v), min(OPT(l(v,w) + OPT(i-1,w),w are neighbours of v)))
