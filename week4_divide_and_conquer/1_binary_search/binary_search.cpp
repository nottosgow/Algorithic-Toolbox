#include <iostream>
using namespace std;

int BinarySearch (int a[], int left, int right, int data) {
	if (left > right) return -1;
	int mid = left + (right - left) / 2;
	if (data > a[mid]) return BinarySearch (a, mid + 1, right, data);
	if (data < a[mid]) return BinarySearch (a, left, mid - 1, data);
	return mid;
}

int main() {
	int n; cin>>n;
	int A[n];
	for (int i = 0; i < n; i++) cin >> A[i];
	int k; cin >> k;
	int B[k];
	for (int i = 0; i < k; i++) cin >> B[i];
	for (int i = 0; i < k; i++) {
		cout << BinarySearch (A, 0, n, B[i]) <<' ';
	}
	return 0;
}
