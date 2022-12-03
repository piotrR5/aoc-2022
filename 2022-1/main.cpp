#include <cstdlib>
#include <iostream>
#include <set>
using namespace std;

int main() {
    string input;
    int n = 0, nmax = 0;
    set<int> top3;
    while (getline(cin, input)) {

        if (input.size() == 0 || input == "\n") {
            top3.emplace(n);
            if (top3.size() > 3)
                top3.erase(3);
            n = 0;
        } else if (input == "q") {
            break;
        } else {
            n += atoi(input.c_str());
        }
    }
    for (auto i : top3)
        cout << i << endl;

    return 0;
}
