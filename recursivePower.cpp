/**
 *author:Abu Jafar Shiddik
 *created:17-03-2023(12:21:15)
 **/
#include <bits/stdc++.h>
using namespace std;
int power(int n, int m)
{
    if (m != 0)
    {
        return (n * power(n, m - 1));
    }
    else
        return 1;
};
int main()
{
    int n, m;
    cin >> n >> m;
    cout << power(n, m);
    return 0;
}