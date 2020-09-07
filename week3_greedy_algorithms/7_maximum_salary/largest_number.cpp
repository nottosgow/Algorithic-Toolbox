#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<int> convert(vector<string> a) {
	int n = a.size();
	vector<int> numbers;
	for (int i = 0; i < n; i++) {
		for (int j = 0; a[j] != '\0'; j++) {
			numbers.push_back((int) a[i][j]);
		}
	}
	sort(numbers.begin(), numbers.end());
	return numbers;
}

string largest_number(vector<string> a) {
	//write your code here
	std::stringstream ret;
	vector<int> num = convert(a);
	for (size_t i = 0; i < num.size(); i++) {
		ret << num[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
