#include <iostream>
#include <vector>
#define INF 999
using namespace std;
int n, m;

vector<vector<int>> D;
vector<vector<int>> P;
vector<vector<int>> W;
vector<int> p;
vector<pair<int, int>> temp;

void floyd() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			D[i][j] = W[i][j];
			P[i][j] = 0;
		}
	}

	for (int k = 1; k <= n; k++) { //���İ��� ��带 ������
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (D[i][j] > D[i][k] + D[k][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
			}
		}
	}
}

void path(int u , int v) {
	int k = P[u][v];
	if (k != 0) {
		path(u, k);
		p.push_back(k);
		path(k, v);
	}
}

void print_path(int u, int v) {
	cout << u << " ";
	for (int i = 0; i < p.size(); i++) {
		cout << p[i] << " ";
	}
	cout << v << endl;
}

int main() {
	int a, b,c,num;
	cin >> n >> m;
	W.resize(n + 1, vector<int>(n + 1,INF));
	P.resize(n + 1, vector<int>(n + 1));
	D.resize(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) { //�밢�� �ʱ�ȭ
		D[i][i] = W[i][i] = 0;
	}

	for (int i = 1; i <= m; i++) { // W�迭�� �ޱ�
		cin >> a >> b >> c;
		W[a][b] = c;
	}

	floyd();
	cin >> num;
	int u, v;
	while (num--) { //�������ϱ����ؼ� �迭�� ����
		cin >> u >> v;
		temp.push_back(make_pair(u, v));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << D[i][j] << (j == n ? "\n" : " ");
		}	
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << P[i][j] << (j == n ? "\n" : " ");
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		u = temp[i].first; v = temp[i].second;
		if (D[u][v] != INF) {
			path(u, v);
			print_path(u, v);
			p.resize(0);
		}
		else {
			cout << "NONE" << endl;
		}
	}
	
}