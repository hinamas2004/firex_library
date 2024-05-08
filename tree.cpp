#include <bits/stdc++.h>
using namespace std;
struct UndirectedTree{
    int n;
    vector<vector<pair<int,long long>>> G;
    UndirectedTree(int _n){
        n = _n;
        G.resize(n);
    }
    void add_edge(int u,int v,long long w){
        G[u].emplace_back(v,w);
        G[v].emplace_back(u,w);
    }
    vector<long long> make_dist(int r){
        vector<long long> dist(n);
        auto dfs = [&](auto dfs,int R,int p)->void{
            for(auto v : G[R]){
                if(v.first == p)continue;
                dist[v.first] = dist[R] + v.second;
                dfs(dfs,v.first,R);
            }
        };
        dfs(dfs,r,-1);
        return dist;
    }
    pair<vector<int>,long long> find_path(int s,int t){
        vector<int> path;
        long long pathlong = 0;
        auto dfs = [&](auto dfs,int r,int p,long long pls)->void{
            if(!path.empty() && path.back() == t)return;
            pathlong += pls;
            path.emplace_back(r);
            if(r == t)return;
            for(auto v : G[r]){
                if(v.first == p)continue;
                dfs(dfs,v.first,r,v.second);
            }
            if(path.back() != t){
                pathlong -= pls;
                path.pop_back();
            }
        };
        dfs(dfs,s,-1,0);
        return {path,pathlong};
    }
    pair<vector<int>,long long> make_diameter(){
        vector<long long> d1 = make_dist(0);
        long long maxdist = 0;
        int maxdistindex = -1;
        for(int i=0; i<n; i++){
            if(d1[i] > maxdist){
                maxdist = d1[i];
                maxdistindex = i;
            }
        }
        vector<long long> d2 = make_dist(maxdistindex);
        maxdist = 0;
        int maxdistindex2 = -1;
        for(int i=0; i<n; i++){
            if(d2[i] > maxdist){
                maxdist = d2[i];
                maxdistindex2 = i;
            }
        }
        return find_path(maxdistindex,maxdistindex2);
    }
};