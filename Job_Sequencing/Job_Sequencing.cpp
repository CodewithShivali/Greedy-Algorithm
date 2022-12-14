#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b)
{
    return a.first>b.first;
}
int main()
{
    vector<pair<int,int>>job;
    int n,profit,deadline;
    cout<<"Enter the number of ID's:"<<"\n";
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cout<<"Enter the PROFIT and DEADLINE"<<"\n";
        cin>>profit;
        cin>>deadline;
        job.push_back(make_pair(profit,deadline));
    }
    sort(job.begin(),job.end(),compare);
    int maxEndTime=0;
    for(int i=0;i<n;++i)
    {
        if(job[i].second>maxEndTime)
        maxEndTime=job[i].second;
    }
    int fill[maxEndTime];
    int count=0;
    int maxProfit=0;

    for(int i=0;i<maxEndTime;++i){fill[i]=-1;}
    for(int i=0;i<n;++i)
    {
        int j=job[i].second-1;
        while(j>=0 and fill[j]!=-1)
        {
            j--;
        }
        if(j>=0 and fill[j]==-1)
        {
            fill[j]=i;
            count++;
            maxProfit += job[i].first;
        }
    }
    cout<<"The Count:"<<count<<" "<<"The Profit:"<<maxProfit<<"\n";
}