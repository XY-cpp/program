#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],c[maxn],ans;
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[j]==b[i]&&i!=j)
                c[j]=1;
    for(int i=1;i<=n;i++)
        if(c[i]==0) ans++;
    cout<<ans<<endl;
}