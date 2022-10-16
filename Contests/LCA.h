const ll MAXN = 1e5;

ll n, m, l, q, timer;
vector<vl> up;
vl adj[MAXN], tin, tout;

// Found ETT/LCA code here: https://cp-algorithms.com/graph/lca_binary_lifting.html#algorithm

void dfs(ll v, ll p)
{
	tin[v] = timer++;
	up[v][0] = p;
	for (ll i = 1; i <= l; ++i)
		up[v][i] = up[up[v][i-1]][i-1];
	for (ll u : adj[v]) {
		if (u != p)
			dfs(u, v);
	}
	tout[v] = timer++;
}

bool is_ancestor(ll u, ll v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (ll i = l; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

void preprocess(ll root) {
	tin.resize(n);
	tout.resize(n);
	timer = 0;
	l = ceil(log2(n));
	up.assign(n, vl(l + 1));
	dfs(root, root);
}
