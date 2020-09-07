// Money change for denominations 1, 3, 4.
// need to find optimal solution using dynamic programming
// strategy: create an array containing the number of coins required for
// each amount of money then call a recursive fn which can use the values
// provided

#include <iostream>
#include <climits>

int coins[] = {4, 3, 1};

int get_change(int money)
{
	int min_number_coin[money+1];
	min_number_coin[0] = 0;
	for (int m=1; m<=money; ++m)
	{
		min_number_coin[m] = INT_MAX;
		for (int i=0; i<3; ++i)
		{
			if (m >= coins[i])
			{
				int number_coins = 0;
				number_coins = min_number_coin[m - coins[i]] + 1;
				if (number_coins < min_number_coin[m])
					min_number_coin[m] = number_coins;
			}
		}
	}
	return min_number_coin[money];
}

int main()
{
  	int m;
  	std::cin >> m;
  	std::cout << get_change(m) << '\n';
}
