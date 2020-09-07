#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <float.h>
using std::vector;
using std::string;
using std::pair;
using std::min;

struct point {
	int x;
	int y;
};

void swap(point *a, point *b){
	point t = *a;
	*a = *b;
	*b = t;
}

double dist(point p1, point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int partitionX(vector<point> &p, int low, int high){
	int pivot = p[high].x;
	int i = (low-1);

	for(int j = low; j < high; j++){
		if(p[j].x<=pivot){
			i++;
			swap(&p[i], &p[j]);
		}
	}
	swap(&p[i+1], &p[high]);
	return (i + 1);
}

void quickSortX(vector<point> &p, int low, int high){
	if (low<high){
		int pi = partitionX(p, low, high);

		quickSortX(p, low, pi-1);
		quickSortX(p, pi+1, high);
	}
}

int partitionY(vector<point> &p, int low, int high){
	int pivot = p[high].y;
	int i = (low-1);

	for(int j = low; j < high; j++){
		if(p[j].y<=pivot){
			i++;
			swap(&p[i], &p[j]);
		}
	}
	swap(&p[i+1], &p[high]);
	return (i + 1);
}

void quickSortY(vector<point> &p, int low, int high){
	if (low<high){
		int pi = partitionY(p, low, high);

		quickSortY(p, low, pi-1);
		quickSortY(p, pi+1, high);
	}
}

double bruteForce(vector<point> p) {
	double m = FLT_MAX;
	for (int i=0, n = p.size(); i<n; i++)
		for (int j=i+1; j<n; ++j)
			if (dist(p[i], p[j]) < m)
				m = dist(p[i], p[j]);
	return m;
}

double stripClosest (vector<point> p, int size, double d) {
	double m = d;
	for (int i=0; i<size; ++i)
		for (int j=i+1; j < size && (p[j].y - p[i].y) < m; ++j)
			if (dist(p[i],p[j]) < m)
				m = dist(p[i], p[j]);
	return m;
}

double get_minimum_x(vector<point> Px, vector<point> Py, int left, int right){
	// what do i want to do here? i want to return the minimum defined 
	// as d in my notes. ie i want to find the min when i consider 2 
	// subarrays with respective mins of d1 and d2
	if (Py.size() <= 3) 
		return bruteForce(Py);
	int n = right-left+1;	
	int mid = left + (right-left) / 2;
	point midPoint = Py[mid];

	vector<point> PyL(mid);
	vector<point> PyR(n-mid);
	int Li = 0, Ri = 0;
	for (int i=0; i<n; ++i) {
		if (Py[i].x <= midPoint.x && Li < mid)
			PyL[Li++] = Py[i];
		else
			PyR[Ri++] = Py[i];
	}

	double dL = get_minimum_x(Px, PyL, left, mid-1);
	double dR = get_minimum_x(Px, PyR, mid+1, right);

	double d = min(dL, dR);

	vector<point> strip(n);
	int j = 0;
	for (int i=0; i<n; i++)
		if ((Py[i].x - midPoint.x) * (Py[i].x - midPoint.x) < d*d)
			strip[j++] = Py[i];
	return stripClosest(strip, j, d);
}

double minimal_distance_fastest(vector<point> &p){
	int n = p.size();
	vector<point> Px(n);
	vector<point> Py(n);
	for (int i=0; i<n; i++) {
		Px[i] = p[i];
		Py[i] = p[i];
	}

	quickSortX(Px,0,n-1);
	quickSortY(Py,0,n-1);

	return get_minimum_x(Px, Py, 0, n-1);
}

int main() {
	size_t n;
	std::cin >> n;
	vector<point> points(n); 
  
	for (size_t i = 0; i < n; i++) {
		std::cin>>points[i].x>>points[i].y;    
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << minimal_distance_fastest(points) << "\n";
}
