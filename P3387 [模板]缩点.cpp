#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int maxm=1e5+5;
int n,m,a[N],x[maxm],y[maxm];
int head[maxm],to[maxm],nxt[maxm],e_num;
bool camp(int a,int b)
{
	if(x[a]!=x[b])
		return x[a]<x[b];
	return y[a]<y[b];
}
void add(int u,int v)
{
	nxt[++e_num]=head[u];
	to[e_num]=v;
	head[u]=e_num;
}
int top,sum,num,dfn[N],low[N],st[N],w[N],co[N];
void tarjan(int u)
{
	dfn[u]=low[u]=++num;
	st[++top]=u;
	for(int i=head[u];i!=0;i=nxt[i])
	{
		int v=to[i];
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(!co[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		co[u]=++sum;
		w[sum]+=a[u];
		while(st[top]!=u)
		{
			co[st[top]]=sum;
			w[sum]+=a[st[top]];
			top--;
		}
		top--;
	}
	return ;
}
int dg[N],rnk[maxm];
void remove()
{
	for(int i=1;i<=m;i++)
	{
		rnk[i]=i;
		x[i]=co[x[i]];
		y[i]=co[y[i]];
	}
	sort(rnk+1,rnk+1+m,camp);
	e_num=0;
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(nxt));
	for(int i=1;i<=m;i++)
	{
		int k=rnk[i];
		if(x[k]!=y[k]&&(x[k]!=x[rnk[i-1]]||y[k]!=y[rnk[i-1]]))//����ͬһ���� 
		{
			dg[y[k]]++;
			add(x[k],y[k]);
		}
	}
	return ;
}
int ans,dis[N],que[N],l,r;
void tuopu()
{
	for(int i=1;i<=sum;i++)
		if(!dg[i])
		{
			que[++r]=i;
			dis[i]+=w[i];
			if(ans<dis[i]) ans=dis[i];
		}
	while(l<r)
	{
		int u=que[++l];
		for(int i=head[u];i!=0;i=nxt[i])
		{
			int v=to[i];
			dg[v]--;
			if(dis[v]<dis[u]+w[v])
				dis[v]=dis[u]+w[v];
			if(ans<dis[v]) ans=dis[v];
			if(!dg[v])
				que[++r]=v;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	remove();
	tuopu();
	cout<<ans<<endl;
	return 0;
}
