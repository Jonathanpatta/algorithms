#include<iostream>
#include<vector>
using namespace std;
void mergearr(vector<int> &left,vector<int> &right,vector<int> &ar)
{
    int nl=left.size();
    int nr=right.size();
    int i=0,j=0,k=0;
    while(i<nl&&j<nr)
    {
        if(left[i]<=right[j])
        {
            ar[k]=left[i];
            k++;
            i++;
        }
        else
        {
            ar[k]=right[j];
            k++;
            j++;
        }
    }
    while(i < nl) ar[k++] = left[i++];
	while(j < nr) ar[k++] = right[j++];
}
void mergesort(vector<int> &ar,int n)
{
    int nl,nr;
    vector<int> a,b;
    if(n>1)
    {
        nl= n/2;
        nr=n-nl;
        for(int i=0;i<n;i++)
        {
            if(i<nl)
            {
                a.push_back(ar[i]);
            }
            else
            {
                b.push_back(ar[i]);
            }
        }
        mergesort(a,nl);
        mergesort(b,nr);
        mergearr(a,b,ar);
        //a.clear();
        //b.clear();

    }
    else
    {
        return;
    }
}
int main()
{
    int n,count1=0;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        cin>>count1;
        a.push_back(count1);
    }
    cout<<"\n";
    mergesort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
