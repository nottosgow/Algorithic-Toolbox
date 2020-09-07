#include <iostream>
#include <vector>

using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
	vector<int> c;
	int buffer_j = 0;
	for (int i=0; i<a.size(); i++)
	{
		for (int j=buffer_j; j<b.size(); j++)
		{
			if (a[i] == b[j])
			{
				c.push_back(a[i]);
				buffer_j = j + 1;
				break;
			}
		}
	}

	return std::min(std::min(a.size(), b.size()), c.size());
}

int lcs_as_ed(vector<int> &a, vector<int> &b)
{
	// in this i want to construct a 2D array and add 1 only when there's
	// a match. this means i never want to move diagonally when a[i] != b[j]

	int rows = a.size(); //std::cout<<"rows: "<<rows<<'\n';
	int cols = b.size(); //std::cout<<"cols: "<<cols<<'\n';

	int result[rows+1][cols+1];


	for (int i=0; i<=rows; i++) result[i][0] = 0;
	for (int j=0; j<=cols; j++) result[0][j] = 0;

	for (int i=1; i<=rows; i++)
	{
		for (int j=1; j<=cols; j++)
		{
			if (a[i-1] == b[j-1])
			{
				result[i][j] = result[i-1][j-1] + 1;
				continue;
			}
			int score = std::max(result[i-1][j], result[j-1][i]);
			result[i][j] = score;
		}
	}

	return result[rows][cols];
}


int main() {
	size_t n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	size_t m;
	std::cin >> m;
	vector<int> b(m);
	for (size_t i = 0; i < m; i++) {
		std::cin >> b[i];
  	}

	std::cout << lcs2(a, b) << std::endl;
	std::cout << lcs_as_ed(a,b)<<std::endl;
}
