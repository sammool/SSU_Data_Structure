#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int INF = 1e9;

struct Node{
  int x, y, cost;
  bool operator>(const Node &another) const{
    return cost > another.cost;
  }
};

int main(int argc, char** argv) {
  int n,m;
  cin >> n >> m;
  
  char maze[n][m];
  int dist[n][m];
  pair<int,int> path[n][m];

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    for(int j=0; j<m; j++){
      maze[i][j] = s[j];
      dist[i][j] = INF;
      path[i][j] = {-1,-1};
    }
  }

  priority_queue<Node, vector<Node>, greater<Node>> pq;
  dist[0][1] = maze[0][1] - '0';
  pq.push({0,1,maze[0][1] - '0'});

  while(!pq.empty()){
    Node cur = pq.top();
    pq.pop();
    for(int idx=0; idx<4; idx++){
      int nx = cur.x + dx[idx];
      int ny = cur.y + dy[idx];
      if(nx<0 || ny<0 || nx>=n || ny>=m)
        continue;
      if(maze[nx][ny] == '0')
        continue;
      
      int cost = dist[cur.x][cur.y] + maze[nx][ny] - '0';
      if(cost < dist[nx][ny]){
        dist[nx][ny] = cost;
        path[nx][ny] = {cur.x, cur.y};
        pq.push({nx, ny, cost});
      }
    }
  }

  int x = n-1;
  int y = m-2;
  maze[x][y] = '*';
  while(!(x==0 && y==1)){
    pair<int,int> prev = path[x][y];
    maze[prev.first][prev.second] = '*';
    x = prev.first;
    y = prev.second;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cout << maze[i][j];
    }
    cout << '\n';
  }
  cout << dist[n-1][m-2];

}