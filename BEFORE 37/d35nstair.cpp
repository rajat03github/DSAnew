#include <iostream>
using namespace std;

int countClimb(long long nstairs)
{
    // base case
    if (nstairs < 0)
        return 0;
    if (nstairs == 0)
        return 1;
    // recursvie
    int ans = countClimb(nstairs - 1) + countClimb(nstairs - 2);

    return ans;
}

int main()
{
    long n = 5;
    long ans = countClimb(n);
    cout << ans;

    return 0;
}