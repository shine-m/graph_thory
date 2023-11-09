#include<bits/stdc++.h>
using namespace std;
#define ln "\n" 

class vertex{
public:
    string color;
    vector<string> adjacent;
    int rank;
    int d;
    string val;

    vertex(){
      
        color = "pink";
        d = INT_MAX;
    }
};

int main()
{
cout<<ln<<ln;

unordered_map<string, vertex> mp;
int n;
cout<<"how many edges?\t";
cin >> n;
string  u, v;
cout<<"\nInsert pair of vertices for each of  "<<n<<"vertices"<<ln;

for (int i = 0; i < n;i++){
    cin >> u >> v;
    mp[u].adjacent.push_back(v);
    mp[v].adjacent.push_back(u);
    mp[u].val = u;
    mp[v].val = v;
}

for(auto i : mp){
    cout << "vertex :  " << i.second.val<< ln;
    cout << "colour : " << i.second.color << ln;
    cout << "d : " << i.second.d << ln;
    cout << "Adjacent vertices : ";
    for(auto j:i.second.adjacent){
    cout << j << " ";
    }
    cout << ln<<ln;
    
    
}
cout << ln;

cout<<"now performing bredth forst search\n";

cout << "vertices are \t";

for(auto i : mp){
    cout << i.first << " ";
}
cout << ln;

cout<<"Enter  a vertex to initiate breadth first search\t";

cin >> u;

queue<vertex> q;

mp[u].color = "black";
mp[u].d = 0;

q.push(mp[u]);

while(!q.empty()){


    for(auto i : q.front().adjacent)
    { 
        
    if (mp[i].color == "pink")
    {
      
       mp[i].d = q.front().d + 1;
       mp[i].color = "black";
       q.push(mp[i]);

      
    }
    }
    cout << ln;
    
    q.pop();
}


cout<<"after operating bfs :\n\n";
for(auto i : mp){
    cout << "vertex :  " << i.first << ln;
    cout << "colour : " << i.second.color << ln;
    cout << "d : " << i.second.d << ln;
   
    cout << ln<<ln;
    
    
}



cout << ln << ln << ln;
return 0;
}

//test case
// 7 a e a b a c c b c d d e d f