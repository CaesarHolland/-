#include<bits/stdc++.h>
using namespace std;
const int N=100010 , INF=0x3f3f3f3f;
int start[N] , last[N] , en[N] , w[N] , idx=1 , n , m;
int dist[N];
bool jud[N];
/* 
参数介绍：start[i]表示从i顶点开始的边的编号，last[i]表示i边的顶点的下一条边，en[i]表示i边的终点，w[i]为i边的权值;
*/

void add(int x , int y , int m){//邻接矩阵存储函数
    w[idx] = m;
    last[idx] = start[x];
    start[x] = idx;
    en[idx++] = y;
}

int spfa(){
    memset(jud , 0 , sizeof jud);
    memset(dist , INF , sizeof dist);
    queue<int>q;
    q.push(1);
    dist[1] = 0;
    jud[1] = 1;
    while(q.size()){
        int t = q.front();
        q.pop();
        jud[t] = 0;
        for(int i = start[t] ; i!=-1 ; i=last[i]){//开始松弛
            if(dist[en[i]] > dist[t] + w[i]){
                dist[en[i]] = dist[t] + w[i];
                if(!jud[en[i]]){
                    q.push(en[i]);
                    jud[en[i]] = 1;
                }
            }
        }
    }
    return dist[n];
}

int main()
{
    memset(start , -1 , sizeof start);
    cin>>n>>m;
    
    for(int i=1 ; i<=m ; i++){
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
    }
    
    int t = spfa();
    if(t==INF) cout<<"impossible"<<endl;
    else cout<<spfa()<<endl;
    return 0;
}