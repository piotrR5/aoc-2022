#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

struct Node {
    char n;
    bool wasVisited;
    pair<int, int> prev;

    Node(int n) {
        this->n = n;
        wasVisited = false;
    }
};

vector<Node> makeLineOfNodes(string line) {
    vector<Node> vec;
    for (auto i : line) {
        vec.push_back(Node(i));
    }

    return vec;
}

vector<pair<int, int>> getNeighbours(int i, int j,
                                     vector<vector<Node>> &graph) {

    vector<pair<int, int>> ret;
    //cout<<"["<<i<<" "<<j<<"]\n";
    if(i>=0 && i<graph.size() && j>=0 && j<graph[0].size()){
    if (i + 1 < graph.size()){
        if(i==40)goto spaghetti;
        if (graph[i + 1][j].n - 1 <= graph[i][j].n &&
            graph[i + 1][j].wasVisited == false)
            ret.push_back({i + 1, j});

    }
spaghetti:
        
    if (i - 1 >= 0)
        if (graph[i - 1][j].n - 1 <= graph[i][j].n &&
            graph[i - 1][j].wasVisited == false)
            ret.push_back({i - 1, j});
    if (j + 1 < graph[0].size())
        if (graph[i][j + 1].n - 1 <= graph[i][j].n &&
            graph[i][j + 1].wasVisited == false)
            ret.push_back({i, j + 1});
    if (j - 1 >= 0)
        if (graph[i][j - 1].n - 1 <= graph[i][j].n &&
            graph[i][j - 1].wasVisited == false)
            ret.push_back({i, j - 1});
    }

    return ret;
}

void printGraph(const vector<vector<Node>> &graph) {
    for (auto i : graph) {
        for (auto j : i)
            cout << j.n;
        cout << endl;
    }
    cout << endl;
}

void printVisits(const vector<vector<Node>> &graph) {
    for (auto i : graph) {
        for (auto j : i)
            cout << j.wasVisited;
        cout << "\t";
        for (auto j : i)
            cout << (j.wasVisited ? (char)(j.n - 'a' + 'A') : j.n);
        cout << endl;
    }
    cout << endl;
     usleep(2000);
    system("clear");
}

pair<int, int> findChar(char f, vector<vector<Node>> &g) {
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[0].size(); j++) {
            if (g[i][j].n == f) {
                g[i][j].n = (f == 'S' ? 'a' : 'z');
                return {i, j};
            }
        }
    }

    return {0, 0};
}

void BFS(pair<int, int> p, pair<int, int> e, vector<vector<Node>> graph) {
    deque<pair<int, int>> q;
    q.push_back(p);
    int chuj = 0;
    // cout<<graph.size()<<endl;
    while (!q.empty()) {
        // cout<<"["<<chuj++<<"]\n";
        //printVisits(graph);
        auto [x, y] = q.front();
        graph[x][y].wasVisited = true;
        q.pop_front();

        if (make_pair(x, y) == e) {
            //cout << "end found\n";
            break;
        }

        vector<pair<int, int>> n = getNeighbours(x, y, graph);

        for (auto &i : n) {
            q.push_back(i);
            graph[i.first][i.second].wasVisited=true;
            graph[i.first][i.second].prev = make_pair(x, y);
        }
    }

    int c = 0;
    auto E = e;
    while (E != p) {
        c++;
        auto [a, b] = graph[E.first][E.second].prev;
        E = graph[E.first][E.second].prev;
        //cout << a << " " << b << endl;
    }
    cout << c << endl;
}

int main() {

    //ios::sync_with_stdio(false);
    fstream file;
    file.open("input.txt");
    string line;

    vector<vector<Node>> graph;

    while (getline(file, line)) {
        graph.push_back(makeLineOfNodes(line));
    }

    printGraph(graph);

    pair<int, int> s = findChar('S', graph);
    pair<int, int> e = findChar('E', graph);


    cout<<"part1: \n";
    BFS(s, e, graph);

    cout<<"\n\npart2: \n";


    for(int i=0;i<graph.size()-1;i++){
        s=make_pair(i,0);
        BFS(s, e, graph);
    }    
}
