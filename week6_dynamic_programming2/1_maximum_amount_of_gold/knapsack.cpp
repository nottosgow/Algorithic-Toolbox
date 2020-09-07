#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

int optimal_weight(int W, vector<int> &w) {

	w.insert(w.begin(), 0);
	vector <vector <int> > values (W + 1, vector<int> (w.size()));
	
	for (int i=0; i<=W; i++) values[i][0] = 0;
	for (int j=0; j<w.size(); ++j) values[0][j] = 0;

	for (int i=1, n=w.size(); i<n; ++i)
	{
		for (int j=1; j<=W; ++j)
		{
			values[j][i] = values[j][i - 1];
			if (w[i] <= j)
			{
				int val = values[j - w[i]][i - 1] + w[i];
				if (values[j][i] < val) values[j][i] = val;
			}
		}
	}
	
	return values[W][w.size() - 1];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	// std::sort (w.begin(), w.end());
	std::cout << optimal_weight(W, w) << '\n';
}
