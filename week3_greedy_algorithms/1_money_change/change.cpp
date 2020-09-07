#include <iostream>

int get_change(int m) {
    //write your code here
    int count = 0;

    count += m/10;
    m %= 10;
    
    count += m/5;
    m %= 5;
    
    count += m;
    m = 0;
    
    return count;
}

int main() {
    int m;
    std::cin >> m;
    std::cout << get_change(m) << '\n';
}
