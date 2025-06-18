#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


double vedicSqrtApprox(int n)
{
    int A = static_cast<int>(sqrt(n));
    int B = n - (A * A);
    if (A == 0)
        return 0.0;
    return A + (static_cast<double>(B) / (2 * A));
}


double deviationPercent(int n, double approx, double actual)
{
    return fabs(approx - actual) / actual * 100.0;
}

int main()
{
    const int LIMIT = 100000000; // 10^8
    int count = 0;

    for (int n = 2; n < LIMIT; ++n)
    {
        double actualSqrt = sqrt(n);
        double approxSqrt = vedicSqrtApprox(n);
        double deviation = deviationPercent(n, approxSqrt, actualSqrt);

        if (deviation > 5.0)
        {
            cout << n << " " << actualSqrt << " " << approxSqrt << " " << deviation <<  endl;
            ++count;
        }


        if (n % 10000000 == 0)
        {
            cerr << "Checked up to: " << n << endl;
        }
    }

    cout << "\nTotal numbers with >2% deviation: " << count << endl;

    return 0;
}