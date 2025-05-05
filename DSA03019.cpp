#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
using namespace std;
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        vector<string> result;

        while (b % a != 0)
        {
            long long x = b / a + 1;
            result.push_back("1/" + to_string(x));
            a = a * x - b;
            b = b * x;
            long long g = gcd(a, b);
            a /= g;
            b /= g;
        }
        result.push_back("1/" + to_string(b / a));

        for (size_t i = 0; i < result.size(); ++i)
        {
            if (i > 0)
                cout << " + ";
            cout << result[i];
        }
        cout << "\n";
    }

    return 0;
}