#include<bits/stdc++.h>
using namespace std;
const int N = 210 , INF = 0x3f3f3f3f;
int omap[N][N];
int n,m,k;

void floyd(){
    for(int k=1 ; k<=n ; k++)
        for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                omap[i][j] = min(omap[i][j] , omap[i][k]+omap[k][j]);
}

int main()
{
    cin>>n>>m>>k;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i==j) omap[i][j]=0;
            else omap[i][j] = INF;
        }
    }
    while(m--){
        int a,b,c;
        cin>>a>>b>>c;
        omap[a][b] = min(omap[a][b],c);
    }
    
    floyd();
    
    while(k--){
        int a,b;
        cin>>a>>b;
        if(omap[a][b]>INF/2) cout<<"impossible"<<endl;
        else cout<<omap[a][b]<<endl;
    }
    return 0;
}