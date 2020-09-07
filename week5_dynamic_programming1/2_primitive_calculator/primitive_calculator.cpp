#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
	int min_steps[n + 1];	// this array is for minimum steps for that index

	min_steps[0]=0;

	for (int i=1; i<n; ++i) {

		int num_steps;
		int index = i + 1;

		num_steps = min_steps[i-1] + 1;

		if (index % 3 == 0)	num_steps = std::min(num_steps, min_steps[index / 3 - 1] + 1);

		if (index % 2 == 0)	num_steps = std::min(num_steps, min_steps[index / 2 - 1] + 1);

		min_steps[i] = num_steps;
	}
	vector<int> solution;
	for (int i=n-1; i>0; )
	{

		solution.push_back(i + 1);

		if (min_steps[i-1] == min_steps[i] - 1)
			i = i-1;
		else if ((i+1)%2 == 0 && min_steps[i/2] == min_steps[i] - 1)
			i = i / 2;
		else if ((i+1)%3 == 0 && min_steps[i / 3] == min_steps[i] - 1)
			i = i / 3;
	}
	solution.push_back(1);
	std::reverse(solution.begin(), solution.end());
	return solution;
}

int main() {
	
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}

}
