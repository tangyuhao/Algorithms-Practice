#include <iostream>
#include <queue>
using namespace std;
#define N 16

int calNumMinRoutes(int graph[N][N]) {
    queue <int> q;
    int step[N];
    int routeNumber[N];
    for (int i = 0; i < N; i++)
        step[i] = 0;
    for (int i = 0; i < N; i++)
        routeNumber[i] = 0;
    routeNumber[0] = 1;
    q.push(0);

    int from, min;
    // start calculating minimum routes
    while (!q.empty()) {
        from = q.front();
        q.pop();
        min = step[from] + 1;
        // start from the point except the start point
        for (int i = 1; i < N; i++) {
            if (graph[from][i] == 1) {
                if (step[i] == 0 || step[i] > min) {
                    routeNumber[i] = routeNumber[from];
                    step[i] = min;
                    q.push(i);
                }
                else if (step[i] == min) {
                    routeNumber[i] += routeNumber[from];
                }
            }

        }

    }
    return routeNumber[N-1];



}

int main() {
    // define the graph

    int graph[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[i][j] = 0;

    graph[0][1] = graph[0][4] = 1;
    graph[1][5] = graph[1][0] = graph[1][2] = 1;
    graph[2][1] = graph[2][6] = graph[2][3] = 1;
    graph[3][2] = graph[3][7] = 1;
    graph[4][0] = graph[4][5] = 1;
    graph[5][1] = graph[5][4] = graph[5][6] = graph[5][9] = 1;
    graph[6][2] = graph[6][7] = graph[6][5] = graph[6][10] = 1;
    graph[7][3] = graph[7][6] = 1;
    graph[8][9] = graph[8][12] = 1;
    graph[9][8] = graph[9][13] = graph[9][10] = 1;
    graph[10][9] = graph[10][14] = graph[10][11] = 1;
    graph[11][10] = graph[11][15] = 1;
    graph[12][8] = graph[12][13] = 1;
    graph[13][9] = graph[13][12] = graph[13][14] = 1;
    graph[14][10] = graph[14][13] = graph[14][15] = 1;
    graph[15][11] = graph[15][14] = 1;

    cout << calNumMinRoutes(graph) << endl;
    return 0;
}