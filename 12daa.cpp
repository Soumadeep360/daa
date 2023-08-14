#include<bits/stdc++.h>
using namespace std;

#define MAX_CITIES 10

int graph[MAX_CITIES][MAX_CITIES];
bool visited[MAX_CITIES];
int minCost = 99999999;

void initializeGraph(int n) {
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            cin>> graph[i][j];
        }
    }
}

void branchAndBoundTSP(int currentCity, int n, int cost, int count) {
    if (count == n && graph[currentCity][0]) {
        minCost = (cost + graph[currentCity][0] < minCost) ? cost + graph[currentCity][0] : minCost;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && graph[currentCity][i]) {
            visited[i] = true;
            branchAndBoundTSP(i, n, cost + graph[currentCity][i], count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    int n;
    cout<<"Enter the number of cities: "<<endl;
    cin>>n;

    cout<<"Enter the cost matrix:\n";
    initializeGraph(n);

    visited[0] = true;  // Starting from the first city
    branchAndBoundTSP(0, n, 0, 1);

    cout<<"Minimum cost of TSP: "<< minCost<<endl;

    return 0;
}