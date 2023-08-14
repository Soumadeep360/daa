#include<bits/stdc++.h>
using namespace std;

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
bool visited[MAX_CITIES];
int minCost = 99999999;
vector<int> bestPath;

void initializeGraph(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
}

void branchAndBoundTSP(int currentCity, int n, int cost, int count, vector<int> path) {
    if (count == n && graph[currentCity][0]) {
        if (cost + graph[currentCity][0] < minCost) {
            minCost = cost + graph[currentCity][0];
            bestPath = path;
            bestPath.push_back(0);  // Add the starting city to complete the path
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currentCity][i]) {
            visited[i] = true;
            path.push_back(i);
            branchAndBoundTSP(i, n, cost + graph[currentCity][i], count + 1, path);
            path.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of cities: " << endl;
    cin >> n;

    cout << "Enter the cost matrix:\n";
    initializeGraph(n);

    visited[0] = true;  // Starting from the first city
    vector<int> initialPath = {0};  // Starting path with just the first city
    branchAndBoundTSP(0, n, 0, 1, initialPath);

    cout << "Minimum cost of TSP: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}
