#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define V 7

// Struct untuk menyimpan lintasan
struct PathInfo {
    vector<char> path;
    int weight;
};

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], min_index = v;
    return min_index;
}

void buildPath(int parent[], int j, vector<char>& path, char nodeNames[]) {
    if (parent[j] == -1) {
        path.push_back(nodeNames[j]);
        return;
    }
    buildPath(parent, parent[j], path, nodeNames);
    path.push_back(nodeNames[j]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int parent[V];
    char nodeNames[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<PathInfo> paths;

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;
        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Simpan semua jalur ke vector paths
    for (int i = 0; i < V; i++) {
        if (i != src && dist[i] != INT_MAX) {
            vector<char> path;
            buildPath(parent, i, path, nodeNames);
            paths.push_back({path, dist[i]});
        }
    }

    // Urutkan berdasarkan bobot
    sort(paths.begin(), paths.end(), [](const PathInfo& a, const PathInfo& b) {
        return a.weight < b.weight;
    });

    // Cetak hasil
    cout << "Jadi, lintas terpendeknya adalah:\n";
    for (const auto& p : paths) {
        cout << "- ";
        for (size_t i = 0; i < p.path.size(); i++) {
            cout << p.path[i];
            if (i != p.path.size() - 1) cout << ", ";
        }
        cout << " dengan bobot " << p.weight << endl;
    }
}

int main() {
    cout << "Program Algoritma Dijkstra" << endl;
    cout << "Nama: Amelya Novparwinka" << endl;
    cout << "Nim/Kelas : 23533800/4C" << endl;
    cout << "----------------------------------" << endl << endl;

    int graph[V][V] = {
        // A  B  C  D  E  F  G
        {0, 3, 0, 2, 0, 0, 0}, // A
        {3, 0, 5, 0, 0, 0, 0}, // B
        {0, 5, 0, 0, 0, 8, 0}, // C
        {2, 0, 0, 0, 3, 0, 0}, // D
        {0, 0, 0, 3, 0, 0, 11}, // E
        {0, 0, 8, 0, 0, 0, 11}, // F
        {0, 0, 0, 0, 11, 11, 0} // G
    };

    dijkstra(graph, 0); // Mulai dari A (index 0)

    cout << "\nProgram selesai dijalankan oleh: Amelya Novparwinka" << endl;

    return 0;
}
