#include <bits/stdc++.h>

using namespace std;
int n,s,t;
int m[51][51];
int inf = 1e9;
int dist[51], vis[51];
vector<int> pri[51];
vector<vector<int>> route;

void find_route(int t, vector<int> r)
{
    if (t == s)
    {
        reverse(r.begin(), r.end());
        route.push_back(r);
    }
    else
    {
        for (auto it : pri[t])
        {
            r.push_back(it);
            find_route(it, r);
            r.pop_back();
        }
    }
}

bool my_cmp(vector<int> v1, vector<int> v2)
{
    if (v1.size() != v2.size())
    {
        return v1.size() < v2.size();
    }
    else
    {
        int s = v1.size();
        for (int i = 0; i < s; i++)
        {
            if (v1[i] != v2[i])
            {
                return v1[i] < v2[i];
            }
        }
        return 0;
    }
}


int main()
{
    int count = 1;
    while (cin >> n)
    {
        route.clear();
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> m[i][j];
            }
        }
        cin >> s >> t;
        for (int i = 1; i <= n; i++)
        {
            dist[i] = inf;
            vis[i] = 0;
            pri[i].clear();
        }
        int tmps = s;
        dist[s] = 0;
        vis[s] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (m[tmps][j] == -1) continue;
                if (dist[j] > dist[tmps] + m[tmps][j])
                {
                    dist[j] = dist[tmps] + m[tmps][j];
                    pri[j].clear();
                    pri[j].push_back(tmps);
                }
                else
                {
                    if (dist[j] == dist[tmps] + m[tmps][j])
                    {
                        pri[j].push_back(tmps);
                    }
                }
            }
            int mx = inf, mxi = 0;
            for (int j = 1; j <= n; j++)
            {
                if (vis[j]) continue;
                if (dist[j] < mx)
                {
                    mx = dist[j];
                    mxi = j;
                }
            }
            vis[mxi] = 1;
            tmps = mxi;
        }
        vector<int> r;
        r.push_back(t);
        find_route(t, r);

        sort(route.begin(), route.end(), my_cmp);
        cout << "Case " << count << endl;
        cout << "The least distance from " << s << " -> " << t << " is " << dist[t] << endl;
        cout << "the path is ";
        for (auto it : route[0])//0代表排序后第一个
        {
            if (it == s)
                cout << it;
            else
            cout << "->" << it;
        }
        cout << endl;
        count++;
    }
    return 0;
}