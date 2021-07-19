#include <iostream>
using namespace std;

int N, P, Q;
int Red[200001], Blue[200001], Green[200001];

int main() {
    int i, j, l;
	char color;
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
	int r, c, lr, lb, lg;
	for (i=0; i<Q; i++) {
		cin >> r >> c;
		lr = r - c + 1;
		lb = N - r + 1;
		lg = c;
		if (Red[lr] + Blue[lb] + Green[lg] == 0) {
			cout << "W" << endl;
		} else if (Red[lr] > Blue[lb] && Red[lr] > Green[lg]) {
			cout << "R" << endl;
		} else if (Blue[lb] > Red[lr] && Blue[lb] > Green[lg]) {
			cout << "B" << endl;
		} else {
			cout << "G" << endl;
		}

	}
}
