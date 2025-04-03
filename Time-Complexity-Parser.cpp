#include<bits/stdc++.h>
using namespace std;
int n,m,S[200000],k,p,ind,num,ans,T[200000];
char a,x,y,z;
string L;
void ca()
{
	k=0;
	cin>>n;
	for(int j=1;j<=n;++j)
	{
		cin>>a;
		if(a=='F')
		{
			cin>>z;
			getline(cin,L);
			p=1;
			if(L[1]>='1' and L[1]<='9')
			{
				x='1';
				while(L[p]!=' ')
				{
					p++;
				}
			}
			else
			{
				x='n';
				p++;
			}
			if(L[p+1]>='1' and L[p+1]<='9')
			{
				y='1';
			}
			else
			{
				y='n';
			}
			if(x!='n' and y=='n')
			{
				S[++k]=1;
			}
			else
			{
				S[++k]=0;
			}
			//cout<<L[1]<<x<<" "<<y<<endl;
		}
		if(a=='E')
		{
			S[++k]=-1;
		}
	}
}
int main()
{
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		ca();
		ind=0,num=0,ans=0;
		//cout<<k<<endl;
		for(int o=1;o<=k;++o)
		{
			//cout<<S[o]<<" ";
			if(S[o]!=-1)
			{
				T[++ind]=S[o];
				num+=S[o];
			}
			else
			{
				if(T[ind]==1)
				{
					num-=1;
				}
				ind--;
			}
			ans=max(ans,num);
		}
		if(ans==0)
		{
			cout<<"O(1)"<<endl;
		}
		else
		{
			cout<<"O(n^"<<ans<<")"<<endl;
		}
	}
	return 0;
}
