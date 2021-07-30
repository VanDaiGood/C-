#include <bits/stdc++.h>
using namespace std;

int t;
int x, y, x1, x2;
pair<int,int>td,pt,tt,pd;

int g1(int a,int b)
{
    if(td.first>=a)return 0;
    if(td.second>=b) return 0;
    int f=INT_MAX;
    if(tt.second+abs(td.second-b)<=y)
    f=min(f,abs(td.second-b));
    if(pt.first+abs(a-td.first)<=x)
    f=min(f,abs(a-td.first));
    return f;
}

int g2(int a,int b)
{
    if(td.first>=a)return 0;
    if(tt.second<=b) return 0;
    int f=INT_MAX;
    if(td.second-abs(b-tt.second)>=0)
    f=min(f,abs(b-tt.second));
    if(pt.first+abs(a-tt.first)<=y)
    f=min(f,abs(a-tt.first));
    return f;
}

int g3(int a,int b)
{
    if(a>=pt.first)return 0;
    if(b>=pt.second)return 0;
    int f=INT_MAX;
    if(pd.first-abs(b-pt.second)>=0)
    f=min(f,abs(b-pt.second));
    if(tt.first-abs(a-pt.first)>=0)
    f=min(f,abs(a-pt.first));
    return f;
}
int g4(int a,int b)
{
    if(a>=pd.first)return 0;
    if(b<=pd.second)return 0;
    int f=INT_MAX;
    if(td.first-abs(a-pd.first)>=0)
    f=min(f,abs(a-pd.first));
    if(pt.second+abs(b-pd.second)<=y)
    f=min(f,abs(b-pd.second));
    return f;
}
int main()
{
    cin>>t;
    
    while(t--){
        cin>>x>>y;
        cin>>td.first>>td.second>>pt.first>>pt.second;
        cin>>x1>>x2;
        tt={td.first,pt.second};
        pd={pt.first,td.second};
        int k=INT_MAX;
        k=min(k,g1(x1,x2));
        k=min(k,g2(x1,y-x2));
        k=min(k,g3(x-x1,y-x2));
        k=min(k,g4(x-x1,x2));
        double kq=k;
       cout<<fixed<<setprecision(6)<<kq<<'\n';
    }

    return 0;
}
