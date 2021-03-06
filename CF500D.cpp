#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector< pair<int,int> >g[N];
int cnt[N],n,w[N];
double C3,ans=0;
int dfs(int u,int fa)
{
    int tot=0;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i].first,id=g[u][i].second;
        if(v==fa) continue;
        cnt[id]=dfs(v,u);
        tot+=cnt[id];
    }
    return tot+1;
}
double cal(int i)
{
    double a=cnt[i],b=n-cnt[i];
    return 2.0*w[i]/C3*(a*(a-1)*b/2.0+b*(b-1)*a/2.0);
}
int main()
{
    int a,b,q,x,y;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&w[i]);
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,i));
    }
    C3=1.0*n*(n-1)*(n-2)/6;
    int m=dfs(1,0);
    for(int i=1;i<n;i++)
        ans+=cal(i);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        ans-=cal(x);
        w[x]=y;
        ans+=cal(x);
        printf("%.9lf\n",ans);
    }
}