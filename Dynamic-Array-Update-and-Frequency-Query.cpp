#include<iostream>
#include<cmath>
using namespace std;
int n,m,p,A[1000001],b,k,x,y,c,sum,P[1000001],ans;
int main()
{
	cin>>n>>m>>p;
	for(int i=1;i<=n;++i)
	{
		cin>>A[i];
		sum+=A[i];
	}
		for(int j=1;j<=n;++j)
		{
			if((A[j]==0 and P[abs(A[j])]<=0) or (A[j]!=0 and P[abs(A[j])]<=1))
			{
				ans+=1;
				//cout<<A[j]<<endl;
			}
			P[abs(A[j])]+=1;
		}
	//	cout<<sum<<endl;
	for(int i=1;i<=m;++i)
	{
		cin>>b;
		if(b==1)
		{
			cin>>k>>x>>y>>c;
			sum-=A[k];
			P[abs(A[k])]-=1;
			if((P[abs(A[k])]<=1 and A[k]!=0) or (P[abs(A[k])]<=0 and A[k]==0))
			{
				ans-=1;
			}
			A[k]=((x*x+k*y+5*x)%p)*c;
			P[abs(A[k])]+=1;
			if((P[abs(A[k])]<=2 and A[k]!=0) or (P[abs(A[k])]<=1 and A[k]==0))
			{
				ans+=1;
			}
			sum+=A[k];
			//cout<<A[k]<<endl;
		}
		else if(b==2)
		{
			cout<<sum<<endl;
		}
		else
		{
			cout<<ans<<endl;
		}
	}
	return 0;
}
