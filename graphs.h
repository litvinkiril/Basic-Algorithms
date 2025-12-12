#pragma once
#include <bits/stdc++.h>
namespace ga {

using ll = long long;
static constexpr ll INF = (1LL<<62);

struct Edge {
    int to;
    ll w;
};

struct Graph {
    int n = 0;
    bool directed = false;
    std::vector<std::vector<Edge>> g;

    Graph() = default;
    Graph(int n_, bool directed_ = false) : n(n_), directed(directed_), g(n_) {}

    void add_edge(int u, int v, ll w = 1) {
        g[u].push_back({v, w});
        if (!directed) g[v].push_back({u, w});
    }
};

struct BFSResult {
    std::vector<int> dist;
    std::vector<int> parent;
    std::vector<int> order;
};

inline BFSResult bfs(const Graph& gr, int s) {
    BFSResult res;
    res.dist.assign(gr.n, INT_MAX);
    res.parent.assign(gr.n, -1);
    std::queue<int> q;
    res.dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front(); q.pop();
        res.order.push_back(v);
        for (auto e : gr.g[v]) {
            if (res.dist[e.to] == INT_MAX) {
                res.dist[e.to] = res.dist[v] + 1;
                res.parent[e.to] = v;
                q.push(e.to);
            }
        }
    }
    return res;
}

inline std::vector<int> restore_path(int s, int t, const std::vector<int>& parent) {
    if (s == t) return {s};
    if (t < 0 || t >= (int)parent.size()) return {};
    std::vector<int> path;
    for (int v = t; v != -1; v = parent[v]) path.push_back(v);
    std::reverse(path.begin(), path.end());
    if (path.empty() || path.front() != s) return {};
    return path;
}

struct DFSResult {
    std::vector<int> parent;
    std::vector<int> tin, tout;
    std::vector<int> order_pre;
    std::vector<int> order_post;
};

inline DFSResult dfs_iterative(const Graph& gr, int s) {
    DFSResult res;
    res.parent.assign(gr.n, -1);
    res.tin.assign(gr.n, -1);
    res.tout.assign(gr.n, -1);

    int timer = 0;
    std::vector<int> it(gr.n, 0);
    std::vector<int> st;
    st.push_back(s);
    res.parent[s] = -1;

    while (!st.empty()) {
        int v = st.back();
        if (res.tin[v] == -1) {
            res.tin[v] = timer++;
            res.order_pre.push_back(v);
        }
        if (it[v] == (int)gr.g[v].size()) {
            res.tout[v] = timer++;
            res.order_post.push_back(v);
            st.pop_back();
            continue;
        }
        int to = gr.g[v][it[v]++].to;
        if (res.tin[to] == -1) {
            res.parent[to] = v;
            st.push_back(to);
        }
    }
    return res;
}

struct DijkstraResult {
    std::vector<ll> dist;
    std::vector<int> parent;
};

inline DijkstraResult dijkstra(const Graph& gr, int s) {
    DijkstraResult res;
    res.dist.assign(gr.n, INF);
    res.parent.assign(gr.n, -1);

    using P = std::pair<ll,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    res.dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != res.dist[v]) continue;
        for (auto e : gr.g[v]) {
            if (res.dist[v] + e.w < res.dist[e.to]) {
                res.dist[e.to] = res.dist[v] + e.w;
                res.parent[e.to] = v;
                pq.push({res.dist[e.to], e.to});
            }
        }
    }
    return res;
}

struct BellmanFordResult {
    std::vector<ll> dist;
    std::vector<int> parent;
    bool has_neg_cycle = false;
};

inline BellmanFordResult bellman_ford(const Graph& gr, int s) {
    struct E { int u,v; ll w; };
    std::vector<E> edges;
    edges.reserve(2 * gr.n);
    for (int u = 0; u < gr.n; ++u)
        for (auto e : gr.g[u])
            edges.push_back({u, e.to, e.w});

    BellmanFordResult res;
    res.dist.assign(gr.n, INF);
    res.parent.assign(gr.n, -1);
    res.dist[s] = 0;

    for (int i = 0; i < gr.n - 1; ++i) {
        bool any = false;
        for (auto &ed : edges) {
            if (res.dist[ed.u] == INF) continue;
            if (res.dist[ed.u] + ed.w < res.dist[ed.v]) {
                res.dist[ed.v] = res.dist[ed.u] + ed.w;
                res.parent[ed.v] = ed.u;
                any = true;
            }
        }
        if (!any) break;
    }
    for (auto &ed : edges) {
        if (res.dist[ed.u] == INF) continue;
        if (res.dist[ed.u] + ed.w < res.dist[ed.v]) {
            res.has_neg_cycle = true;
            break;
        }
    }
    return res;
}

inline std::vector<std::vector<ll>> floyd_warshall(int n, const std::vector<std::tuple<int,int,ll>>& edges, bool directed) {
    std::vector<std::vector<ll>> d(n, std::vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (auto [u,v,w] : edges) {
        d[u][v] = std::min(d[u][v], w);
        if (!directed) d[v][u] = std::min(d[v][u], w);
    }
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i) if (d[i][k] != INF)
            for (int j = 0; j < n; ++j) if (d[k][j] != INF)
                d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    return d;
}

inline std::pair<bool, std::vector<int>> toposort_kahn(const Graph& gr) {
    std::vector<int> indeg(gr.n, 0);
    for (int u = 0; u < gr.n; ++u)
        for (auto e : gr.g[u]) indeg[e.to]++;

    std::queue<int> q;
    for (int i = 0; i < gr.n; ++i) if (indeg[i] == 0) q.push(i);

    std::vector<int> order;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);
        for (auto e : gr.g[v]) {
            if (--indeg[e.to] == 0) q.push(e.to);
        }
    }
    bool ok = ((int)order.size() == gr.n);
    return {ok, order};
}

struct DSU {
    std::vector<int> p, r;
    DSU() = default;
    explicit DSU(int n) : p(n), r(n,0) { std::iota(p.begin(), p.end(), 0); }
    int find(int a){ return p[a]==a?a:p[a]=find(p[a]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) std::swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

struct MSTEdge { int u,v; ll w; };
struct MSTResult { ll weight = 0; std::vector<MSTEdge> edges; bool ok = false; };

inline MSTResult mst_kruskal(int n, std::vector<MSTEdge> edges) {
    std::sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a.w < b.w; });
    DSU dsu(n);
    MSTResult res;
    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            res.weight += e.w;
            res.edges.push_back(e);
        }
    }
    res.ok = ((int)res.edges.size() == n - 1);
    return res;
}

inline MSTResult mst_prim(const Graph& gr, int start = 0) {
    MSTResult res;
    std::vector<ll> key(gr.n, INF);
    std::vector<int> parent(gr.n, -1);
    std::vector<char> used(gr.n, 0);

    using P = std::pair<ll,int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [k, v] = pq.top(); pq.pop();
        if (used[v]) continue;
        used[v] = 1;
        for (auto e : gr.g[v]) {
            if (!used[e.to] && e.w < key[e.to]) {
                key[e.to] = e.w;
                parent[e.to] = v;
                pq.push({key[e.to], e.to});
            }
        }
    }

    for (int v = 0; v < gr.n; ++v) {
        if (!used[v]) { res.ok = false; return res; }
    }
    res.ok = true;
    for (int v = 0; v < gr.n; ++v) if (v != start) {
        res.weight += key[v];
        res.edges.push_back({parent[v], v, key[v]});
    }
    return res;
}

inline std::vector<int> scc_kosaraju(const Graph& gr, int* comp_cnt_out = nullptr) {
    int n = gr.n;
    std::vector<std::vector<int>> rg(n);
    for (int u = 0; u < n; ++u) for (auto e : gr.g[u]) rg[e.to].push_back(u);

    std::vector<char> vis(n, 0);
    std::vector<int> order;
    order.reserve(n);

    std::function<void(int)> dfs1 = [&](int v) {
        vis[v] = 1;
        for (auto e : gr.g[v]) if (!vis[e.to]) dfs1(e.to);
        order.push_back(v);
    };
    for (int i = 0; i < n; ++i) if (!vis[i]) dfs1(i);

    std::vector<int> comp(n, -1);
    int cc = 0;
    std::function<void(int)> dfs2 = [&](int v) {
        comp[v] = cc;
        for (int to : rg[v]) if (comp[to] == -1) dfs2(to);
    };

    for (int i = n - 1; i >= 0; --i) {
        int v = order[i];
        if (comp[v] == -1) {
            dfs2(v);
            cc++;
        }
    }
    if (comp_cnt_out) *comp_cnt_out = cc;
    return comp;
}

struct BridgesArtsResult {
    std::vector<std::pair<int,int>> bridges;
    std::vector<int> articulation_points;
};

inline BridgesArtsResult bridges_and_articulation_points(const Graph& gr) {
    int n = gr.n;
    std::vector<int> tin(n, -1), low(n, -1), parent(n, -1);
    std::vector<char> is_art(n, 0);
    int timer = 0;
    BridgesArtsResult res;

    std::function<void(int)> dfs = [&](int v) {
        tin[v] = low[v] = timer++;
        int children = 0;
        for (auto e : gr.g[v]) {
            int to = e.to;
            if (to == parent[v]) continue;
            if (tin[to] != -1) {
                low[v] = std::min(low[v], tin[to]);
            } else {
                parent[to] = v;
                children++;
                dfs(to);
                low[v] = std::min(low[v], low[to]);
                if (low[to] > tin[v]) {
                    res.bridges.push_back({v, to});
                }
                if (parent[v] != -1 && low[to] >= tin[v]) {
                    is_art[v] = 1;
                }
            }
        }
        if (parent[v] == -1 && children > 1) is_art[v] = 1;
    };

    for (int i = 0; i < n; ++i) if (tin[i] == -1) dfs(i);
    for (int i = 0; i < n; ++i) if (is_art[i]) res.articulation_points.push_back(i);
    return res;
}

struct BipartiteResult { bool ok = true; std::vector<int> color; };

inline BipartiteResult bipartite_check(const Graph& gr) {
    BipartiteResult res;
    res.color.assign(gr.n, -1);
    for (int i = 0; i < gr.n; ++i) if (res.color[i] == -1) {
        std::queue<int> q;
        res.color[i] = 0;
        q.push(i);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (auto e : gr.g[v]) {
                if (res.color[e.to] == -1) {
                    res.color[e.to] = res.color[v] ^ 1;
                    q.push(e.to);
                } else if (res.color[e.to] == res.color[v]) {
                    res.ok = false;
                }
            }
        }
    }
    return res;
}

}
