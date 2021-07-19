#include <iostream>
using namespace std;
#define MAXN 1000

int N, P, Q;
char wall[MAXN+1][MAXN+1];
void paint(char color, int l) {
    int i, r;
    if (color == 'R') {
        for (i=0; i<=N-l; i++)
            wall[l+i][i+1] = 'R';
    } else if (color == 'G') {
        for (i=l; i<=N; i++)
            wall[i][l] = 'G';
    } else {
        r = N-l+1;
        for (i=1; i<=r; i++)
            wall[r][i] = 'B';
    }
}

void print_wall() {
    int i, j;
    for (i=1; i<=N; i++) {
        for (j=1; j<=i; j++)
            cerr << wall[i][j];
        cerr << endl;
    }
    cerr << "-------------------" << endl;
}

int main() {
    int i, j, l, r, c;
    char color;
    cin >> N >> P;
    for (i=1; i<=N; i++)
        for (j=1; j<=N; j++)
            wall[i][j] = 'W';

    for (i=0; i<P; i++) {
        cin >> color >> l;
        paint(color, l);
    }
    print_wall();

    cin >> Q;
    for (i=0; i<Q; i++) {
        cin >> r >> c;
        cout << wall[r][c] << endl;
    }

    return 0;
}