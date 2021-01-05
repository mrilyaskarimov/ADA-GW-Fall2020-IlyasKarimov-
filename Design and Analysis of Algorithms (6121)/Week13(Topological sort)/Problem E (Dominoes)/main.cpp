//
//  main.cpp
//  Problem E (Dominoes)
//
//  Created by Ilyas Karimov on 21.12.20.
//


#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;
int n, m, cnt, a, b, i, j, c, v, to;
vector<vector<int> > g, gr;
vector<int> used, top, color;
set<pair<int,int> > s;

void dfs1(int v){
    used[v] = 1;
    for(int i = 0; i < g[v].size(); i++){
        int to = g[v][i];
        if (!used[to]) dfs1(to);
    }
    top.push_back(v);
}

void dfs2(int v, int c){
      color[v] = c;
      for(int i = 0; i < gr[v].size(); i++){
        int to = gr[v][i];
        if (color[to] == -1) dfs2(to,c);
      }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    g.resize(n+1);
    gr.resize(n+1);
    for(i = 0; i < m; i++)
    {
      scanf("%d %d",&a,&b);
      g[a].push_back(b);
      gr[b].push_back(a);
    }
    used.resize(n+1);
        for(i = 0; i < n; i++)
          if (!used[i]) dfs1(i);
    color.assign(n+1,-1);
    c = 0;
    for(i = 0; i < n; i++){
        v = top[n-i];
        if (color[v] == -1) dfs2(v,c++);
    }
    used.assign(c,1);
        for(i = 0; i < g.size(); i++)
        for(j = 0; j < g[i].size(); j++){
            to = g[i][j];
            if (color[i] != color[to]) used[color[to]] = 0;
        }
    c = 0;
    for(i = 0; i < used.size(); i++)
          if (used[i]) c++;
    printf("%d\n",c);
}
