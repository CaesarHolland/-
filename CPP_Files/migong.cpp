#include <bits/stdc++.h>
#include<iostream>
using namespace std;

typedef pair<int, int> PII;//定义孪生数据体，用来存储坐标

const int N = 1e2 + 7;
int g[N][N], d[N][N];//g为迷宫，d为 “用于走的” 迷宫，记录此位置走没走过
int n, m;

int bfs() {
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    queue <PII> q;

    for (auto &v : d) {//将d的值全部赋值-1
        for (auto &x : v) {
            x = - 1;
        }
    }
    d[0][0] = 0;//设置入口
    q.push({0, 0});//将入口坐标先入队

    while (!q.empty()) {
        auto t = q.front();
        q.pop();//等待下一个坐标

        for (int i = 0; i < 4; i++) {
            int x = t.first + dx[i], y = t.second + dy[i];

            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second]  + 1;
                q.push({x, y});
            }
        }

    }


        return d[n - 1][m - 1];
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    cout << bfs() << finall;

    return 0;
}