#include <iostream>
using namespace std;

int N, P, Q;
int Red[200001], Blue[200001], Green[200001];

int main() {
    char color;
    int i, l, x, y, ri, bi, gi;
    cin >> N >> P;
    for (i=1; i<=P; i++) {
        cin >> color >> l;
        if (color == 'R') {
            Red[l] = i;
        } else if (color == 'B') {
            Blue[l] = i;
        } else {
            Green[l] = i;
        }
    }
    cin >> Q;
    for (i=0; i<Q; i++) {
        cin >> x >> y;
        ri = x - y + 1;
        bi = N - x + 1;
        gi = y;
        if (Red[ri] + Blue[bi] + Green[gi] == 0) {
            cout << "W" << endl;
        } else if (Red[ri] > Blue[bi] && Red[ri] > Green[gi]) {
            cout << "R" << endl;
        } else if (Blue[bi] > Red[ri] && Blue[bi] > Green[gi]) {
            cout << "B" << endl;
        } else {
            cout << "G" << endl;
        }
    }
    return 0;
}