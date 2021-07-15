#include <iostream>
using namespace std;
#define MAXN 1000

int N, P, Q;
char wall[MAXN+1][MAXN+1];
void paint(char c, int l) {
    int i, r;
    if (c == 'R') {
        for (i=0; i<=N-l; i++)
            wall[l+i][i+1] = 'R';
    } else if (c == 'G') {
        for (i=l; i<=N; i++)
            wall[i][l] = 'G';
    } else {
        r = N-l+1;
        for (i=1; i<=r; i++)
            wall[r][i] = 'B';
    }
}

char get_color(int x, int y) {
    return wall[x][y];
}

void print_wall() {
    int i, j;
    for (i=1; i<=N; i++) {
        for (j=1; j<=i; j++)
            cout << wall[i][j];
        cout << endl;
    }
}

int main() {
    int i, j, l, x, y;
    char c;
    cin >> N >> P;
    for (i=1; i<=N; i++)
        for (j=1; j<=N; j++)
            wall[i][j] = 'W';

    for (i=0; i<P; i++) {
        cin >> c >> l;
        paint(c, l);
    }

    cin >> Q;
    for (i=0; i<Q; i++) {
        cin >> x >> y;
        cout << get_color(x, y) << endl;
    }
    return 0;
}