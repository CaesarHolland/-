#include<bits/stdc++.h>
using namespace std;
const int N = 510 , INF = 0x3f3f3f3f;
int omap[N][N] , dist[N] , n , m;
bool jud[N];

int dij(){
    memset(dist , INF , sizeof dist);
    dist[1] = 0;
    for(int i=1 ; i<=n ; i++){
        int t = -1;
        for(int j=1 ; j<=n ; j++) //先选出一个距离起点最近的点
            if(!jud[j] && (t==-1 || dist[j] < dist[t]))
                t = j;
        jud[t] = true;//并将其位置设为 “已访问”
        
        for(int j=1 ; j<=n ; j++){//再更新这个顶点周围的顶点到起点的距离
            dist[j] = min(dist[j] , omap[t][j]+dist[t]);
        }
    }
    return dist[n]==INF?-1:dist[n];
}

int main()
{
    cin>>n>>m;
    memset(jud , 0 , sizeof jud);
    memset(omap , INF , sizeof omap);
    
    for(int i=1 ; i<=m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        omap[a][b] = min(omap[a][b] , c);
    }

    cout<<dij()<<endl;
    return 0;
}