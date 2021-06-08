#include<bits/stdc++.h>
using namespace std;
#define max 1000000007
#define ll long long int
map<pair<ll,ll>,ll> finalmap;

void addEdge(pair <ll,ll> edge, vector <ll> graph[],ll n)
{
    graph[edge.first-1][edge.second-1]=1;
    graph[edge.second-1][edge.first-1]=1;
}

ll dist(ll source,ll destination,vector<ll> graph[],ll n,ll visited[],ll count,ll final)
{
//    cout<<"\nin source="<<source<<endl;
    visited[source]=1;
    if(graph[source][destination]==1)
    {
        visited[destination]=1;
        return count;
    }
    
    else
    {
        count=count+1;
    for(ll i=0;i<n;i++)
    {
        if(graph[source][i]==1&&visited[i]==0)
        {
            count=dist(i,destination,graph,n,visited,count,final);
        }
        if(visited[destination]==1)
        {
            break;
        }
        if(i==n-1)
            count-=1;
    }
    }
    return count;
    
}

ll ShowFun(vector <ll> graph[], ll arr[],ll n,ll c){
    ll value=0;
    ll visited[n];
    ll distval;
    pair<ll,ll> pval;
    for(ll i=0;i<c;i++){
        for(ll j=i+1;j<c;j++){
            pval.first=arr[i];
            pval.second=arr[j];
            if(finalmap.find(pval)!=finalmap.end()){
                //cout<<"Yes";
                distval=finalmap[pval];
            }
            else
        {
            memset(visited,0,sizeof(visited));
            distval=dist((arr[i]-1),(arr[j]-1),graph,n,visited,0,0)+1;
            finalmap[pval]=distval;
        }
            //cout<<"\n diatvalue==="<<distval<<" "<<arr[i]<<" "<<arr[j]<<endl;
            value=value+(arr[i]*arr[j]*distval)%max;
            
        }
    }
    ll r=value%(max);
    //cout<<endl;
    return r;
    
}
int main(){
    ll n,q;
    cin>>n>>q;
    vector <ll> graph[n+1];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++)
            graph[i].push_back(0);
    }
    pair <ll,ll> edge;
    for(ll i=0;i<n-1;i++){
        cin>>edge.first>>edge.second;
        addEdge(edge,graph,n);
    }
    ll c;
    for(ll i=0;i<q;i++){
        cin>>c;
        ll arr[c];
        for(ll j=0;j<c;j++)
            cin>>arr[j];
        //cout<<endl;
        cout<<ShowFun(graph,arr,n,c);
        if(i<q-1)
            cout<<endl;
    }
    
    
}

