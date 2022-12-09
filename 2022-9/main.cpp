#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>
#include <vector>



using namespace std;

void doAMove(vector<pair<int, int>> &rope, char dir, int n,
             vector<vector<bool>> &vis) {
    int dx = 0, dy = 0;
    switch (dir) {
    case 'U':
        dy = -1;
        break;
    case 'D':
        dy = 1;
        break;
    case 'R':
        dx = -1;
        break;
    case 'L':
        dx = 1;
    }

    cout << "[" << dir << " " << n << "]\n";

    while (n--) {
        auto p = rope[0];
        rope[0].first += dx;
        rope[0].second += dy;
        vis[rope[1].first + 500][rope[1].second + 500] = true;
        if (rope[1].first + 1 < rope[0].first) {
            rope[1] = p;
        }
        if (rope[1].first - 1 > rope[0].first) {
            rope[1] = p;
        }
        if (rope[1].second + 1 < rope[0].second) {
            rope[1] = p;
        }
        if (rope[1].second - 1 > rope[0].second) {
            rope[1] = p;
        }
        vis[rope[1].first + 500][rope[1].second + 500] = true;
    }
}

int main(int argc, char *argv[]) {
    fstream file;
    file.open("input.txt");
    string line;
    vector<pair<int, int>> rope;
    rope.push_back({0, 0});
    rope.push_back({0, 0});
    vector<vector<bool>> vis(1000, vector<bool>(1000, 0));

    char dir;
    int n;

    while (file >> dir >> n) {
        doAMove(rope, dir, n, vis);
    }

    int c = 0;
    for (auto &i : vis) {
        for (auto j : i) {
            c += j;
        }
    }
    cout << c << endl;
}