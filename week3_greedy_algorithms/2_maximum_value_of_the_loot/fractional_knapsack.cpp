#include <iostream>
#include <vector>

using std::vector;

void swap (int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort (vector<int> &weights, vector<int> &values) {
	
	int n = weights.size();
	
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (values[j] / weights[j] < values[j+1] / weights[j+1]) {
				swap (&weights[j], &weights[j+1]);
				swap (&values[j], &values[j+1]);
			}
		}
	}
}

void show (vector<int> v, vector<int> w) {
	std::cout << "\n\nPrinting sorted array\n";
	for (int i = 0, n = w.size(); i < n; i++) {
		std::cout<<v[i]<<":"<<w[i]<<'='<<v[i]/w[i]<<'\n';
	}
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	if (!capacity) return value;
	// write your code here
	
	// I'm sorting weights and values based on the ratio between values to weights
	// So that i can go down the arrays and get maximized value
	sort (weights, values);
//	show (values, weights);
	// The greedy step i'm taking is to consider capacity amount of weight and
	// adding that much value
	
	int i = 0;
	while (capacity && i < weights.size()) {

		if (capacity >= weights[i]) {
			value += (double) values[i];
			capacity -= weights[i];
//			std::cout << "1Value:" << value <<" cap:" << capacity << '\n';
		}
		
		else {
			value += (double) values[i] * capacity / weights[i];
			capacity -= weights[i];
//			std::cout << "2Value:" << value << ", cap:" << capacity <<'\n';
//			break;
		}
		i++;
	}
	
	return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
