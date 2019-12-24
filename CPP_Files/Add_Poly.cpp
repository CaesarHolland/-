#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
int ex[N] , ex_temp[N] , n;

int main()
{
    int l , tn;
    memset(ex , 0 , sizeof ex);
    memset(ex_temp , 0 , sizeof ex_temp);
    cout<<"Enter the number of item:"<<endl;
    cin>>n;
    cout<<"Enter the polynomial's coffcient:"<<endl;
    for(int i=0 ; i<n ; i++)
        cin>>ex[i];
    string str;
    cout<<"Enter serve:[Add/Sub/Multi]"<<endl;
    cin>>str;
    if(str == "Add"){
            //加法
            cout<<"[Mode:Add]Enter number of item:"<<endl;
            cin>>tn;
            cout<<"[Mode:Add]Enter polynomial's cofficient:"<<endl;
            tn = max(tn,n);
            for(int i=0 ; i<tn ; i++){
                int a;
                cin>>a;
                ex_temp[i] += a+ex[i];
            }
            l = tn;
            //
    }
    else if(str == "Sub"){
            //减法
            cout<<"[Mode:Sub]Enter the number of item:"<<endl;
            cin>>tn;
            tn = max(tn,n);
            cout<<"[Mode:Sub]Enter polynomial's cofficient:"<<endl;
            for(int i=0 ; i<tn ; i++){
                int a;
                cin>>a;
                ex_temp[i] += (a-ex[i]);
            }
            l = tn;
            //
    }
    else if(str == "Multi"){
            //乘法
            cout<<"[Mode:Multi]Just enter cofficient and enter 'ee' when you finish:"<<endl;
            int a , j=0;
            while(cin>>a){
                for(int i=0 ; i<n ; i++)
                    ex_temp[i+j] += a*ex[i];
                j++;
            }
            l = j+n-1;
            //
    }
    else cout<<"No serves"<<endl;
    cout<<"Result:"<<endl;
    for(int i=0 ; i<l ; i++)
        cout<<ex_temp[i]<<' ';
    cout<<endl;
    return 0;
}