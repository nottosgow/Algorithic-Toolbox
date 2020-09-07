#include <iostream>
#include <vector>

using std::vector;

int partition3(vector<int> &A) {
	
	//write your code here
	int total_sum=0;
	for (int i=0, n=A.size(); i<n; i++) total_sum += A[i];

	if (total_sum % 3 != 0) return 0;

	A.insert(A.begin(), 0);
	int n = A.size();
	int div[n][n]; 
	

	return 0;
}

int main() {
	
	int n;
	std::cin >> n;
	vector<int> A(n);
	
	for (size_t i = 0; i < A.size(); ++i) std::cin >> A[i];
	
	std::cout << partition3(A) << '\n';
}
