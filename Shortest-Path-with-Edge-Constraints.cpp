#include<bits/stdc++.h>
using namespace std;
struct edge
{
	int to,dis,next;
};
edge e[4001];
int head[4001],dis[4001],cnt,n,m,q,u,v,w,U[2001],V[2001],W[2001],EP[2001][2001],s,d,A[20][2001],num,len,ans;
bool vis[4001],evis[10];
void add_edge(int u,int v,int w)
{
	cnt++;
	e[cnt].dis=w;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct node
{
	int dis;
	int pos;
	bool operator <(const node&x)const
	{
		return x.dis<dis;
	}
};

priority_queue<node> pq;

void inti()
{
	for(int i=1;i<=n;++i)
	{
		dis[i]=99999999;
		vis[i]=0;
	}
	
}
void rec(int cntt)
{
	for(int i=1;i<=n;++i)
	{
		A[cntt][i]=dis[i];
		//cout<<dis[i]<<" ";
	}
	//cout<<endl;
}
void dij(int s)
{
	inti();
	dis[s]=0;
	pq.push((node){0,s});
	while(!pq.empty())
	{
		int cntnode=pq.top().pos;
		pq.pop();
		if(vis[cntnode])continue;
		for(int i=head[cntnode];i;i=e[i].next)
		{
			if(e[i].dis+dis[cntnode]<dis[e[i].to])
			{
				dis[e[i].to]=e[i].dis+dis[cntnode];
				if(!vis[e[i].to])
				pq.push((node){dis[e[i].to],e[i].to});
			}
		}
		vis[cntnode]=1;
	}
}
void dfs(int lastnode,int step)
{
	if(step==EP[num][0])
	{
		len=len+A[lastnode][d];
		ans=min(ans,len);
		//cout<<len<<" ";
		len=len-A[lastnode][d];
		return;
	}
	for(int i=1;i<=EP[num][0];++i)
	{
		if(!evis[i])
		{
			len=len+A[lastnode][U[EP[num][i]]]+W[EP[num][i]];
			evis[i]=1;
			dfs(i*2,step+1);
			evis[i]=0;
			len=len-A[lastnode][U[EP[num][i]]]-W[EP[num][i]];
			len=len+A[lastnode][V[EP[num][i]]]+W[EP[num][i]];
			evis[i]=1;
			dfs(i*2-1,step+1);
			evis[i]=0;
			len=len-A[lastnode][V[EP[num][i]]]-W[EP[num][i]];
		}
	}
}
int main()
{
	cin>>n>>m>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>u>>v>>w;
		U[i]=u;
		V[i]=v;
		W[i]=w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=q;++i)
	{
		cin>>EP[i][0];
		for(int j=1;j<=EP[i][0];++j)
		{
			cin>>EP[i][j];
		}
	}
	for(int i=1;i<=q;++i)
	{
		cin>>s>>d;
		for(int j=0;j<10;++j)evis[j]=0;
		int cntt=0;
		dij(s);
		rec(cntt);
		for(int j=1;j<=EP[i][0];++j)
		{
			dij(U[EP[i][j]]);
			rec(++cntt);
			dij(V[EP[i][j]]);
			rec(++cntt);
		}
		num=i;
		len=0;
		ans=99999999;
		//cout<<U[EP[num][1]]<<" "<<A[0][U[EP[num][1]]]<<" "<<A[1][1]<<" "<<A[2][1]<<endl;
		dfs(0,0);
		cout<<ans<<endl;
	}
}
/*
7 9 1
1 2 3
5 4 3
3 1 1
6 1 9
3 4 2
1 4 4
3 2 2
3 7 1
5 7 2
1
4
1 5
*/
