#include<iostream>
#include<cmath>
using namespace std;
long long n,q,A[1000001],L[1000001],R[1000001],ans1[1000001],ans2[1000001],anspl[1000001],anspr[1000001],num=2,ju,b;
void search1(int k)
{
	//cout<<k<<" "<<ju<<endl;
	if(k>q)
	{
		b=1;
		return;
	}
	if(b==1 or ju==-1)
	{
		return;
	}
	ju=-1;
	//cout<<L[k]<<" "<<R[k]<<" ";
	if(ans2[R[k]]==0)
	{
		//cout<<"L"<<R[k]<<endl;
		ju=1;
		ans1[++num]=R[k];
		anspl[anspr[ans2[L[k]]]]=num;
		anspr[num]=anspr[ans2[L[k]]];
		anspl[num]=ans2[L[k]];
		anspr[ans2[L[k]]]=num;
		ans2[R[k]]=num;
	}
	else if(ans2[L[k]]==0)
	{
		//cout<<"R"<<L[k]<<endl;
		ju=1;
		ans1[++num]=L[k];
		anspr[anspl[ans2[R[k]]]]=num;
		anspr[num]=ans2[R[k]];
		anspl[num]=anspl[ans2[R[k]]];
		anspl[ans2[R[k]]]=num;
		ans2[L[k]]=num;
	}
	else
	{
		return;
	}
	if(ju==1)
	{
		search1(k+1);
	}
	
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>A[i];
	}
	for(int i=1;i<=q;++i)
	{
		cin>>L[i];
	}
	for(int i=1;i<=q;++i)
	{
		cin>>R[i];
	}
	if(A[1]!=L[1]or A[n]!=R[1])
	{
		cout<<b;
		return 0;
	}
	ans1[1]=L[1];
	ans1[2]=R[1];
	ans2[L[1]]=1;
	ans2[R[1]]=2;
	anspr[1]=2;
	anspl[1]=-1;
	anspl[2]=1;
	anspr[2]=-1;
	search1(2);
	int kkk=1,aug=1;
	b=1;
	//cout<<ans1[1]<<endl;
	//cout<<endl;
	while(kkk!=-1)
	{
		//cout<<ans1[kkk]<<" "<<kkk<<endl; 
		if(b==0)
		break;
		while(A[aug]!=ans1[kkk])
		{
			aug++;
			if(aug>n)
			{
				b=0;
				break;
			}
		}
		aug++;
		kkk=anspr[kkk];
	}
	if(ju==-1)b=0;
	cout<<b;
	return 0;
}
/*
7 6
1 2 3 4 5 6 7
1 2 2 4 2 6
7 7 5 5 3 7

*/
