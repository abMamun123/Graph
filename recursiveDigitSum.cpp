/**
 *author:Abu Jafar Shiddik
 *created:14-03-2023(00:47:00)
 **/
#include <bits/stdc++.h>
using namespace std;
int digitSum(int n)
{
    if (n < 0)
        return n;
    return digitSum(n / 10);
};
int main()
{
    int n;
    cin >> n;
    cout<<digitSum(n);
    return 0;
}