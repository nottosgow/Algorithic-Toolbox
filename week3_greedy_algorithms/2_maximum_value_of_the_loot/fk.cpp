#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void sort_on_ratio (vector<int> &v, vector<int> &w) {
	for (int i = 0, n = v.size(); i < n; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			float r1 = (float) v[j] / (float) w[j];
			float r2 = (float) v[j + 1] / (float) w[j + 1];
			if (r2 > r1) {
				swap (v[j], v[j + 1]);
				swap (w[j], w[j + 1]);
			}
		}
	}
}

double knapsack(int W, vector<int> v, vector<int> w) {
	sort_on_ratio (v, w);
	double max_value = 0.0;
	for (int i = 0, n = v.size(); i < n; ++i) {
		if (!W) break;
		if (w[i] <= W) {
			W -= w[i];
			max_value += v[i];
		} else {
			max_value += (double) W * v[i] / w[i];
			W = 0;
		}
	}
	return max_value;
}
		
int main() {
	int n, W;
	cin >> n >> W;
	vector<int> value(n);
	vector<int> weight(n);
	for (int i = 0; i < n; i++) 
		cin >> value[i] >> weight[i];

	double optimal_value = knapsack(W, value, weight);
	if (optimal_value - (int) optimal_value >= 0.9) optimal_value = ceil(optimal_value);

	cout << fixed << setprecision(10);
	cout << optimal_value << endl;
	return 0;
}

