#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,dis,next;
};
struct node
{
	int dis;
	int from;
	int to;
};

edge e[40001];
node f[40001];
int head[40001],cnt,n,m,q,u,v,w,U[40001],V[40001],W[40001],CU[201][201],CV[201][201],EP[201][201],s,d,num,len,ans,ncnt,fa[40001];
bool cmp(node x,node y)
{
	return x.dis>y.dis;
}
void add_edge(int u,int v,int w)
{
	cnt++;
	e[cnt].dis=w;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void add_node(int u,int v,int w)
{
	ncnt++;
	f[ncnt].dis=w;
	f[ncnt].to=v;
	f[ncnt].from=u;
}
int find(int x)
{
	while(fa[x]!=x)
	{
		x=fa[x]=fa[fa[x]];
	}
	return x;
}
void kruskal()
{
	for(int i=1;i<=m;++i)
	{
		int eu=find(f[i].from);
		int ev=find(f[i].to);
		if(eu==ev)continue;
		fa[eu]=ev;
		if(find(s)==find(d))
		{
			ans=f[i].dis;
			return;
		}	
	}
	
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		U[i]=u;
		V[i]=v;
		W[i]=w;
		add_edge(u,v,w);
		add_edge(v,u,w);
		add_node(u,v,w);
	}
	cin>>q;
	for(int i=1;i<=q;++i)
	{
		cin>>EP[i][0];
		for(int j=1;j<=EP[i][0];++j)
		{
			cin>>CU[i][j]>>CV[i][j]>>EP[i][j];
		}
	}
	for(int i=0;i<=q;++i)
	{
		cin>>s>>d;
		ans=99999999;
		//ncnt=0;
		for(int j=1;j<=m;++j)
		{
			for(int k=1;k<=EP[i][0];++k)
			{
				if((CV[i][k]==f[j].from and CU[i][k]==f[j].to) or (CU[i][k]==f[j].from and CV[i][k]==f[j].to))
					f[j].dis=EP[i][k];
			 } 
		}
		//for(int j=1;j<=m;++j)	cout<<f[j].from<<" "<<f[j].to<<" "<<f[j].dis<<endl;
		//cout<<endl;
		sort(f+1,f+m+1,cmp);
		for(int j=1;j<=n;++j)
		{
			fa[j]=j;
		}
		kruskal();
		cout<<ans<<endl;
	}
}
/*
4 5
1 2 2
2 3 1
1 3 3
3 4 4
1 4 6
0
1 4

*/
