#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
static int checked;
class vertex{
    public:
        string color,val;
        int start,finish;
        vector<string> adjacent;

        vertex(){
            color = "pink";
        }
};


void dfs(unordered_map<string,vertex>&vtx , string s){
for(auto i : vtx[s].adjacent){
            vtx[s].color = "black";
            if (vtx[i].color == "pink")
            {
                vtx[i].start = checked;
                dfs(vtx, i);
}
}
vtx[s].finish = checked++;
}

int main()
{
cout<<ln<<ln;

unordered_map<string, vertex> vtx;
string u, v;

int n;
cout << "Enter the number of  Edge : ";
cin >> n;
cout<<"\nInsert pair of vertices for each of  "<<n<<"vertices"<<ln;

for(int i= 0;i<n;i++)
{
            cin >> u >> v;
            vtx[u].adjacent.push_back(v);
            vtx[v].adjacent.push_back(u);
            vtx[u].val = u;
            vtx[v].val = v;
}

for(auto i : vtx){
    cout << "vertex :  " << i.second.val<< ln;
    cout << "colour : " << i.second.color << ln;
    cout << "start : " << i.second.start<< ln;
    cout << "finish : " << i.second.finish<< ln;
    cout << "Adjacent vertices : ";
    for(auto j:i.second.adjacent){
    cout << j << " ";
    }
    cout << ln<<ln;
    
    
}
cout << ln;

cout << "All verticees are :  ";
for(auto i : vtx){
    cout << i.first << " ";
}
cout << ln;

cout << "Enter a vertex to initiate depth first search  : ";
cin >> u;

vtx[u].start = 1;
checked = 2;

dfs(vtx, u);

cout << "After performing dfs \n\n";
for(auto i : vtx){
    cout << "vertex :  " << i.second.val<< ln;
    cout << "colour : " << i.second.color << ln;
    cout << "start : " << i.second.start<< ln;
    cout << "finish : " << i.second.finish<< ln;
    cout << ln<<ln;
    
    
}
cout<<ln<<ln<<ln;
 return 0;
}