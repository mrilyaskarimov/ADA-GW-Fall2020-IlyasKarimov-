#include <iostream>
#include <vector>

using namespace std;

int test, n, m, a, b, i, j;
vector <vector<int> > g;
vector <int> used, res;
bool flag = false;

void dfs(int v, int prev = -1)
{
    used[v] = prev;
    
    for (int i = 0; i < g[v].size(); i++){
        if (used[g[v][i]] > 0 && !flag){
            flag = true;
            int temp = v;
            while (temp != used[g[v][i]]){
                res.push_back(temp);
                temp = used[temp];
            }
            break;
        }
        if (used[g[v][i]] == 0) dfs(g[v][i], v);
    }
    
    used[v] = -1;
}

int main()
{
    scanf("%d %d", &n, &m);
    g.resize(n + 1);
    used.resize(n + 1);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (used[i] == 0)
            dfs(i);
   
    if (flag)
    {
        puts("YES");
        for (int i = res.size() - 1; i >= 0; i--)
        printf("%d ", res[i]);
    }
    else puts("NO");
}
