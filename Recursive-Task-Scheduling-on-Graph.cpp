#include<bits/stdc++.h>
using namespace std;
int n,m,t,N[10000][10],Nnext[1001][1001],ans=0,a,b,c;
void dfs(int k,int h)
{
	//	cout<<k<<" "<<h<<" "<<N[k][1]<<endl;
	if(Nnext[k][0]==0)
	{
		ans=max(ans,N[k][1]);
	}
	for(int i=1;i<=Nnext[k][0];++i)
	{
		N[Nnext[k][i]][1]=N[k][1]+max(N[Nnext[k][i]][0]-h-1,0);
		dfs(Nnext[k][i],h+1);
	}
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;++i)
	{
		cin>>a>>b>>c;
		Nnext[a][++Nnext[a][0]]=b;
		N[b][0]=c;
	}
	dfs(t,0);
	cout<<ans;
	return 0;
}
