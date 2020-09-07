#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int rows = str1.size();
	int cols = str2.size();

	int scores[rows+1][cols+1];
	scores[0][0] = 0;
	
	for (int i=1; i<rows+1; i++)
		scores[i][0] = scores[i - 1][0] + 1;
	for (int j=1; j<cols+1; j++)
		scores[0][j] = scores[0][j - 1] + 1;
	
	for (int i=1; i<rows+1; ++i) {
		for (int j=1; j<cols+1; j++) {
			scores[i][j] = scores[i - 1][j - 1];
			if (str1[i-1] != str2[j-1]) scores[i][j]++;
			int min_temp = std::min(scores[i-1][j] + 1, scores[i][j-1] + 1);
			scores[i][j] = std::min(scores[i][j], min_temp);
		}
	}
	return scores[rows][cols];
}

int main() {
	string str1;
	string str2;
	std::cin >> str1 >> str2;
	std::cout << edit_distance(str1, str2) << std::endl;
  	return 0;
}
