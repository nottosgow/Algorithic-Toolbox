#include<iostream>
#include<iomanip>
#include<float.h>
#include<stdlib.h>
#include<math.h>

using namespace std;

struct Point {
	int x, y;
};

int compareX (const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->x - p2->x);
}

int compareY (const void* a, const void* b) {
	Point *p1 = (Point *)a, *p2 = (Point *)b;
	return (p1->y - p2->y);
}

double dist (Point p1, Point p2) {
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double bruteForce(Point P[], int n) {
	double min = FLT_MAX;
	for (int i = 0; i<n; ++i)
		for (int j=i+1; j<n; ++j)
			if (dist(P[i], P[j]) < min)
				min = dist(P[i], P[j]);
	return min;
}

double min(double x, double y) {
	return (x < y)? x : y;
}
double stripClosest(Point strip[], int size, double d) {
	double min = d;

	qsort (strip, size, sizeof(Point), compareY);

	for (int i=0; i<size; ++i)
		for (int j=i+1; j<size && (strip[j].y - strip[i].y) < min; ++j)
			if (dist(strip[i], strip[j]) < min)
				min = dist(strip[i], strip[j]);
	return min;
}

double minimal_distance_fast(Point P[], int n) {
	if (n <= 3) return bruteForce (P, n);

	int mid = n/2;
	Point midP = P[mid];

	double dL = minimal_distance_fast(P, mid);
	double dR = minimal_distance_fast(P+mid, n - mid);

	double d = min(dL, dR);

	Point strip[n];
	int j=0;
	for (int i=0; i<n ; ++i)
		if (abs (P[i].x - midP.x) < d)
			strip[j] = P[i], j++;

	return min(d,stripClosest(strip, j, d));
}

double closest(Point P[], int n) {

	qsort(P, n, sizeof(Point), compareX);

	return minimal_distance_fast(P, n);
}

int main() {

	size_t n;
	std::cin >> n;
 	Point points[n]; 
	for (size_t i = 0; i < n; i++) {
		std::cin>>points[i].x>>points[i].y;    
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << closest(points, n) << "\n";
}
