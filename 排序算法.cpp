#include<bits/stdc++.h>
using namespace std;
int ri[100000],a[100000];
long long x=0;
void ef(int l,int r);
void kp(int l,int r);
void mp(int n);
void tp(int n);
int main()
{
	int n;
	cin>>n;
	//tp(n);
	/*
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
	}
	//ef(1,n);
	//kp(1,n);
	//mp(n);
	for (int i=1;i<=n;i++) 
	{
		cout<<a[i]<<' ';
	}*/
	return 0;
}
void ef(int l,int r)
{
	if (l==r) return;
	int i=l,mid=(l+r)/2,j=(l+r)/2+1,k=l;
	ef(l,mid);
	ef(j,r);
	while (i<=mid&&j<=r)
	{
		if (a[i]<=a[j]) 
		{
			ri[k]=a[i];
			i++;
			k++;
		}
		else
		{
			ri[k]=a[j];
			k++;
			j++;
			x+=mid-i+1;
		}
	}
	while (i<=mid)
	{
		ri[k]=a[i];
		k++;
		i++;
	} 
	while (j<=r)
	{
		ri[k]=a[j];
		k++;
		j++;
	}
	for (int ii=l;ii<=r;ii++)
		a[ii]=ri[ii];
}
void kp(int l,int r)
{
	int mid=a[(l+r)/2],i=l,j=r;
	while (i<=j)
	{
		while (a[i]<mid)
			i++;
		while (a[j]>mid)
			j--;
		if (i<=j)
			swap(a[i],a[j]),i++,j--;
	}
	if (l<j)
		kp(l,j);
	if (i<r)
		kp(i,r);
}
void mp(int n)
{
	for (int i=1;i<n;i++)
		for (int j=1;j<n;j++)
			if (a[j]>a[j+1]) swap(a[j],a[j+1]);
}
void tp(int n)
{
	int dmax=-1;
	for (int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		dmax=max(dmax,l);
		a[l]++;
	}
	for (int i=0;i<=dmax;i++)
	{
		while (a[i]!=0)
		{
			cout<<i<<' ';
			a[i]--;
		}
	}
}
