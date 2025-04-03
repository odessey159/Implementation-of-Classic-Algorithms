#include<bits/stdc++.h>
using namespace std;
int n,A[200001],B[200001],S[200001],T[200001],ans;
void de(int k)
{
	//cout<<k<<"  "<<A[k]<<" "<<endl;
	S[k]=-1;
	T[A[k]]--;
	if(T[A[k]]==0 and S[A[k]]!=-1)
	{
				//if(A[k]==-1)cout<<k<<endl;
		de(A[k]);
	}
	A[k]=-1;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>A[i];
		T[A[i]]++;
		S[i]=i;
	}
	for(int i=1;i<=n;++i)
	{
		if(T[i]==0 and S[i]!=-1)
		{
			//cout<<i<<" "<<A[i]<<" "<<endl;
			T[A[i]]--;
			S[i]=-1;
			if(T[A[i]]==0 and S[A[i]]!=-1)
			{
				//S[A[i]]=-1;
				de(A[i]);
			}
			A[i]=-1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		if(S[i]==-1)
		{
			ans++;
		}
	}
	//cout<<T[-1]<<endl;
	cout<<ans;
	return 0;
}
