#include <iostream>
#include <algorithm>

int compare(const void *a, const void *b)
{
    return ( *(int *)a - *(int *)b);
}

int majority(int a[], int n)
{
    int count = 1;
    for (int i=0; i<n; i++)
    {
        if (a[i] != a[i-1])
        {
            count = 1;
        }
        else 
        {
            count++;
            if (count > n/2)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n; std::cin >> n;
    int a[n];
    for (int i=0; i<n; i++) std::cin >> a[i];
    qsort(a, n, sizeof(int), compare);
    std::cout << majority(a, n) << std::endl;
    return 0;
}