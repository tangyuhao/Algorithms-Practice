#include <iostream>
#include <queue>
using namespace std;

#define N 5

void topologic(int * toposort, int * indegree, int graph[][N]) {
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    int curPoint, outCnt = 0;
    while (!q.empty()) {
        curPoint = q.front();
        q.pop();
        toposort[outCnt++] = curPoint;
        for (int i = 0; i < N; i++) {
            if (graph[i][curPoint] != 0) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
    }
    for (int k = 0; k < outCnt; k++) {
        cout << toposort[k] << " ";
    }
    cout << endl;
    if (outCnt < N)
        cout << "this graph has cycles." << endl;
}

int main() {
    // graph[i][j] means j to i
    int graph[N][N]{{0,1,1,0,0},
                    {0,0,0,1,0},
                    {1,1,0,0,1},
                    {0,0,0,0,0},
                    {1,1,1,1,0}};
    int indegree[N] = {0,0,0,0,0};
    int toporesult[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            indegree[i] += graph[i][j];
        }
    }
    topologic(toporesult, indegree, graph);
    return 0;
}