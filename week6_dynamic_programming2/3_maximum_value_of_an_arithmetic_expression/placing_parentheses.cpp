#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
	return 1;
  }
}

long long get_maximum_value(const string &exp) {

	int length = exp.size();
	int num_of_nums = (length + 1) / 2;

	long long minArray[num_of_nums][num_of_nums];
	long long maxArray[num_of_nums][num_of_nums];

	memset(minArray, 0, sizeof(minArray));
	memset(maxArray, 0, sizeof(maxArray));

	for (int i=0; i < num_of_nums; i++) {
		minArray[i][i] = std::stoll(exp.substr(2 * i, 1));
		maxArray[i][i] = std::stoll(exp.substr(2 * i, 1));
	}

	for (size_t s=0; s<num_of_nums - 1; s++)
	{
		for (size_t i=0; i<num_of_nums - s - 1; i++)
		{
			int j = i + s - 1;
			long long minVal = LLONG_MAX;
			long long maxVal = LLONG_MIN;

			for (int k=i; k<j; k++)
			{
				long long a = eval(minArray[i][k], minArray[k+1][j], exp[2 * k + 1]);
				long long b = eval(minArray[i][k], maxArray[k+1][j], exp[2 * k + 1]);
				long long c = eval(maxArray[i][k], minArray[k+1][j], exp[2 * k + 1]);
				long long d = eval(maxArray[i][k], maxArray[k+1][j], exp[2 * k + 1]);
				minVal = min(minVal, min(a, min(b, min(c, d))));
				maxVal = max(maxVal, max(a, min(b, min(c, d))));
			}
			minArray[i][j] = minVal;
			maxArray[i][j] = maxVal;
		}
	}
	////////////////////////////////////////////////////////////////////////////////
	std::cout<<"--------------------MAX--------------------\n";
	for (int i=0; i<num_of_nums; i++) {
		for (int j=0; j<num_of_nums; j++) std::cout<<maxArray[i][j]<<'\t';
		std::cout << std::endl;
	}
	std::cout<<"--------------------MIN--------------------\n";
	for (int i=0; i<num_of_nums; i++) {
		for (int j=0; j<num_of_nums; j++) std::cout<<minArray[i][j]<<'\t';
		std::cout << std::endl;
	}
	////////////////////////////////////////////////////////////////////////////////
	return maxArray[0][num_of_nums - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
