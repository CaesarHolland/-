#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int f[N][N] , n , m;
int dx[]={0,1,0,-1} , dy={1,0,-1,0};

bool zou(int x , int y){
    f[x][y] = 2;//给初始位置打上标记;
    for(int i=0 ; i<4 ; i++){
        int zx = x+dx[i] , zy = y+dy[i];
        if(zx>=0 && zx<n && zy>=0 && zy<m){
            //判断一下是否到终点:
            if( zx==n-1 && zy == m-1){
                f[zx][zy] = 2;
                return true;
            }
            //没到的话就继续走:
            if( !f[zx][zy] ){//如果该方向通;
                int t = zou(zx,zy);//往该方向放出侦察机;
                if(!t) f[zx][zy]=3;//如果侦察机发现前方不通，则打上标记;
                else return true;//如果侦察机找到路线则返回true
            }
        }
    }
    //经过上面四个方向的调查发现没有路，则返回失败;
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)   
            cin>>f[i][j];

    int enx , eny;
    cin>>enx>>eny;//输入你定义的起点坐标(下标从0,0开始)

    if(zou(enx,eny)){
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(f[i][j]==2) cnf++;
                cout<<f[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<cnf-1<<"step in total."<<endl;
    }
    else cout<<"Faild"<<endl;
    return 0;
}