#include<bits/stdc++.h>
using namespace std;
const int maxn=25e4+5;
int n,m;
struct Edge
{
    int nxt,to;
}e[maxn<<2];
int head[maxn],tot;
void add(int u,int v)
{
    edge[++tot]=(Edge){head[u],v};
    haed[u]=tot;
}
void SPFA()
{
    
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v),add(v,u);   
    }
    SPFA();

    return 0;
}