#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	double value = 1232250.9988098409759287452045720457285472390528750892750;
	if (value - (int) value >= 0.9) {
		std::cout << std::fixed << std::setprecision(4) << std::ceil(value);
	}
	std::cout << std::fixed << std::setprecision(4) << value;
	return 0;
}
