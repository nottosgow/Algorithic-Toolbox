#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;
using std::max;
using std::min;

struct Segment {
  int start, end;
};

void sortSeg (vector<Segment> &segments) {
	for (int i = 0, n = segments.size(); i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (segments[j].start > segments[j + 1].start) {
				Segment temp = segments[j];
				segments[j] = segments[j+1];
				segments[j+1] = temp;
			}
		}
	}
}

vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	//write your code here
	sortSeg (segments);
	Segment currSeg = segments[0];
	
	for (int i = 1, n = segments.size(); i < n; i++) {
		if (currSeg.end < segments[i].start) {
			currSeg.start = max(segments[i].start, currSeg.start);
			currSeg.end = min (segments[i].end, currSeg.end);
		}
		else {
			points.push_back (currSeg.start);
			currSeg = segments[i];
		}
	}
	points.push_back (currSeg.start);

	return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
/*
	so i'm thinking a safe move would be to id the points with max overlap
	to do that i'm thinking of having a loop from min of start to max of end
	and for each point storing a number which is the number of segments it has
	issues: how do i ensure each seg is rep?
			
 */
