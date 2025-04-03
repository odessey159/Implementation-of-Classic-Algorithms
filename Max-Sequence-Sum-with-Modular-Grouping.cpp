#include<bits/stdc++.h>
using namespace std;
int n,m,k,b,h[20],t[20],len,E[5001],J[5001],num,jud,jjj,voidlen,bb,maxid,maxp;
float C[5001];
long double a,ans,finalans,maxitem;
vector< vector<float> > B;
vector< vector<int> > id;
void ch(); 
int main()
{
	cin>>n>>k>>m;
	B.resize(k);
	id.resize(k);
	for(int i=0;i<k;++i)
	{
		B[i].resize(1);
		id[i].resize(1);
	}
	if(m>n)
	{
		m=n;
	}
	for(int i=1;i<=n;++i)
	{
		//cout<<i<<" ";
		cin>>b>>a;
		maxitem=max(a,maxitem);
		//a=a*10;
		bb=b;
		b%=k;
		B[b][0]+=1;
		B[b].resize(B[b][0]+1);
		id[b].resize(B[b][0]+1);
		B[b][int(B[b][0])]=a;
		id[b][int(B[b][0])]=bb;
	}
	if(m==1 or n==0)
	//if(true)
	{
		printf("%.1Lf",maxitem);
		return 0;
	}
	for(int i=0;i<k;++i)
	{
		for(int j=1;j<=B[i][0];++j)
		{
			for(int p=1;p<=B[i][0];++p)
			{
				if(id[i][p]>maxid)
				{
					maxid=id[i][p];
					maxp=p;
					C[j]=B[i][p];
				}
			}
			maxid=0;
			id[i][maxp]=0;
		}
		for(int j=1;j<=B[i][0];++j)
		{
			B[i][j]=C[j];
			//cout<<B[i][j]<<" ";
		}
		//cout<<i<<endl;
	}
	ch();
	//cout<<finalans<<endl;
	//float fff=finalans;
	finalans=max(finalans,maxitem);
	printf("%.1Lf",finalans);
	return 0;
}
void ch()
{
	for(int i=0;i<k;++i)
	{
		for(int j=1;j<=int(B[i][0]);++j)
		{
			//cout<<B[i][0]<<endl;
			//cout<<i<<" "<<j<<endl;
			len=0;
			ans=0;
			voidlen=0;
			if(len==0)
			{
				h[0]=i;
				h[1]=j;
				t[0]=i;
				t[1]=j;
				len++;
				ans=B[i][j];
				E[i]=1;
				if(t[1]==int(B[t[0]][0]))
				{
					t[0]++;
					if(t[0]>=k)
					{
						t[0]=0;
					}
					t[1]=1;
					J[E[h[0]]]=h[0]+1;
					while(int(B[t[0]][0])==0)
					{
						voidlen++;
						if(voidlen>1)
						break;
						t[0]++;
						if(t[0]>=k)
						t[0]=0;
					}
				}
				else
				{
					t[1]++;
				}
			}
			jjj=0;
			while((len<m)and(jjj!=1)and(voidlen<=1))
			{
				//cout<<i<<" "<<j<<endl;
				E[t[0]]++;
				ans+=B[t[0]][t[1]];
				len++;
				if(J[E[t[0]]]==0)
				{
					finalans=max(ans,finalans);
					//cout<<h[0]<<" "<<h[1]<<" "<<t[0]<<" "<<t[1]<<" "<<len<<" "<<ans<<" "<<endl;
				}
				if(t[1]==int(B[t[0]][0]))
				{
					if(J[E[t[0]]]!=0)
					{
						jjj=1;
					}
					J[E[t[0]]]=E[t[0]];
					t[0]++;
					if(t[0]==k)t[0]=0;
					t[1]=0;
					while(int(B[t[0]][0])==0)
					{
						voidlen++;
						if(voidlen>1)
						break;
						t[0]++;
						//cout<<t[0]<<endl;
						if(t[0]>=k)
						t[0]=0;
					}
				}
				t[1]++;
			}
			//for(int p=h[0];p<=t[0];++p){J[E[p]]=0,E[p]=0;}
			for(int p=0;p<=5000;++p)
			{
				J[p]=0;
				E[p]=0;
			}
			//cout<<fixed<<finalans<<" ";
		}
	}
	return;
}
