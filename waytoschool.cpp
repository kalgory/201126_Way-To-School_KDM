#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int m,n;

int dp_function(int x, int y){
    if(x==m||y==n) return 0;
    if(v[y][x]==-1) return 0;
    if(v[y][x]!=0) return v[y][x];
    if(x==m-1&&y==n-1) return 1;
    v[y][x]=(dp_function(x+1,y)+dp_function(x,y+1))%1000000007;
    return v[y][x];
}



int solution(int x_input, int y_input, vector<vector<int>> puddles) {
    m=x_input;
    n=y_input;
    v.resize(n,vector<int> (m,0));
    for(int i=0;i<puddles.size();i++)v[puddles[i][1]-1][puddles[i][0]-1]=-1;
    return dp_function(0,0);   
    
}

int main(){
    vector<vector <int>> puddles(1, vector<int> (2,0)); //공의 정보 저장하는 vector
    puddles[0][0]=2;
    puddles[0][1]=2;
    cin>>m>>n;
    v.resize(n,vector<int> (m,0));
    for(int i=0;i<puddles.size();i++)v[puddles[i][1]-1][puddles[i][1]-1]=-1;
    cout<<solution(m,n,puddles);
}