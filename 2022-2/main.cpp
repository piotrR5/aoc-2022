#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int evaluate(char a, char b) {
    // cout << "[evaluate] " << a << " vs " << b << endl;
    // int score = 0;
    // if (b == 'X')
    //     score = 1;
    // if (b == 'Y')
    //     score = 2;
    // if (b == 'Z')
    //     score = 3;
    // cout << "shape score: " << score << endl;

    // if (a - b == 'A' - 'X') {
    //     score += 3;
    //     cout << "DRAW\n";
    //     return score;
    // }

    // if ((a == 'A' && b == 'Y') || (a == 'B' && b == 'Z') ||
    //     (a == 'C' && b == 'X')) {
    //     score += 6;
    //     cout << "WIN\n";
    //     return score;
    // }
    // return score;
    int f1 = a - 'A' + 1;
    int f2;
    int score;
    if (b == 'Y') {
        f2 = f1;
        score = f2 + 3;
    }

    else if (b == 'Z') {
        if (f1 == 1)
            f2 = 2;
        if (f1 == 2)
            f2 = 3;
        if (f1 == 3)
            f2 = 1;
        score = f2 + 6;
    } else {
        if (f1 == 1)
            f2 = 3;
        if (f1 == 2)
            f2 = 1;
        if (f1 == 3)
            f2 = 2;
        score = f2;
    }
    return score;
}

int main() {
    fstream file;
    file.open("input.txt");
    vector<pair<char, char>> rounds;
    char x, y;
    while (file >> x >> y) {
        rounds.push_back({x, y});
        // cout << "[" << x << " " << y << "]\n";
    }

    int score = 0;
    for (auto [a, x] : rounds) {
        score += evaluate(a, x);
        cout << "score: " << score << endl;
    }

    cout << score << endl;

    return 0;
}
