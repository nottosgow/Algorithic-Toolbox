#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
	int count = 0;
	stops.push_back (dist);
	int n = stops.size(), m = tank, lastPos = 0;
//	cout << "stops: ";
//	for (int i = 0; i < n; i++) cout << stops[i] << ' ';
//	cout << '\n';
	for (int i = 2; i < n; i++) {
		if (stops[i] > tank && stops[i - 1] <= tank &&  stops[i - 1] - stops[lastPos] <= m) {
			
			count++;
//			cout << "count: " << count << '\n';
			
//			cout << "reached stop " << i - 1 <<','<<stops[i - 1];
			tank = stops[i - 1] + m;
			lastPos = i - 1;
//			cout << "\ntank: "<< tank <<'\n';

		}
	}
	if (tank >= dist) return count;
    return -1;
}
// i want a variable to track last position of car
int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n+1);
	stops[0] = 0;
    for (size_t i = 1; i <= n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
