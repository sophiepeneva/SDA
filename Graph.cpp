#include<vector>
#include<iostream>
#include<queue>
#include<stack> 

using namespace std;
const int INF = 1000000000;

void dijkstra(int s, vector<vector<pair<int, long long>>> adj) {
	int n = adj.size();
	vector<int> d(n, INF);
	vector<bool> u(n, false);

	d[s] = 0;
	for (int i = 1; i < n; i++) {
		int v = -1;
		for (int j = 1; j < n; j++) {
			if (!u[j] && (v == -1 || d[j] < d[v]))
				v = j;
		}

		if (d[v] == INF)
			break;

		u[v] = true;
		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
			}
		}
	}
	for (int i = 1; i < d.size();i++) {
		if (d[i] != INF && i != s)cout << d[i] << " ";
		else if (i != s) {
			cout << -1 << " ";
		}
	}
}

int mstPrim(vector<vector<pair<int, long long>>> adj, vector<int>& mst, vector<int>& dist, int s) {
	int n = adj.size();
	dist.assign(n, INF);
	mst.assign(n, -1);
	vector<int> d(n, INF);
	vector<bool> u(n, false);
	d[s] = 0;
	mst[s] = s;
	priority_queue<int, less<int>> q;
	q.push(s);
	int res = 0;
	while (!q.empty()) {
		int curr = q.top();
		q.pop();
		if (!u[curr]) {
			u[curr] = true;
			res += curr;
			for (auto edge : adj[curr]) {
				int to = edge.first;
				int cost = edge.second;
				if (!u[to] && d[to] > cost) {
					d[to] = cost;
					mst[to] = curr;
					q.push(to);
				}

				if (d[to]>d[curr] + cost) {
					d[to] = d[curr] + cost;
					q.push(to);
				}

			}
		}
	}
	return res;
}

void DFSHelper(vector<vector<pair<int,int>>>& graph, int start, bool* visited, stack<int>& path) {
	visited[start] = true;
	path.push(start);
	for (auto edge : graph[start]) {
		if (!visited[edge.first]) {
			DFSHelper(graph, edge.first, visited, path);
		}
	}
}

int paths(vector<vector<pair<int,int>>>& graph, int start) {
	bool* visited = new bool[graph.size()];
	for (int i = 0;i<graph.size();i++) {
		visited[i] = false;
	}
	stack<int> path;
	DFSHelper(graph, start, visited, path);
	int size = path.size();
	while (!path.empty()) {
		cout << path.top() << ", ";
		path.pop();
	}
	cout << endl;
	return size;
}

void BFS(vector<vector<pair<int, int>>> graph, int start) {
	int n = graph.size();
	int* arr = new int[n];
	bool* visited = new bool[n];
	for (int i = 0;i < n;i++) {
		visited[i] = false;
		arr[i] = -1;
	}
	arr[start] = 0;
	visited[start] = true;
	queue<int> myQueue;
	myQueue.push(start);

	while (!myQueue.empty()) {
		int curr = myQueue.front();
		myQueue.pop();
		for (auto edge : graph[curr]) {
			if (!visited[edge.first]) {
				visited[edge.first] = true;
				myQueue.push(edge.first);
				if (arr[edge.first] == -1) {
					arr[edge.first] = arr[curr] + 1;
				}
			}
		}
	}
	for (int i = 1;i < n;i++) {
		if (i != start) {
			cout << start << " -> " << i << " : " << arr[i] << endl;
		}
	}
}

void addEdge(vector<vector<pair<int, int>>>& graph, int u, int v, int w) {
	graph[u].push_back(make_pair(v, w));
	graph[v].push_back(make_pair(u, w));
}

int main() {

	int n, m, u, v, w;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n + 1);

	for (int i = 0;i < m;i++) {
		cin >> u >> v >> w;
		addEdge(graph, u, v, w);
	}

	BFS(graph, 1);
	cout << endl;
	paths(graph, 1);
	system("pause");
}