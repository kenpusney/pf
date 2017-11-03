
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>
#include <iterator>
#include <iostream>

using namespace std;

array<uint32_t, 1 << 24> primes{};

void sieve()
{
    for (size_t i = 2; i < primes.size(); i++)
    {
        if (primes[i])
        {
            for (size_t j = 2 * i; j < primes.size(); j += i)
            {
                primes[j] = 0;
            }
        }
    }
}

void factor(uint32_t x)
{
    vector<uint32_t> factors;
    const auto limit = x / 2 + 1;
    const auto origin = x;
    for (int i = 2; i < limit; i++)
    {
        if (primes[x])
        {
            factors.push_back(x);
            break;
        }
        if (primes[i] && !(x % i))
        {
            factors.push_back(i);
            x /= i;
            i = 1;
        }
    }
    // std::sort(begin(factors), end(factors));
    // std::cout << origin << ": ";
    // for (auto fac : factors)
    // {
    //     std::cout << fac << ", ";
    // }
    // std::cout << endl;
}

int main()
{
    std::fill(begin(primes), end(primes), 1);
    sieve();
    for (auto i = 0; i < primes.size(); i++)
    {
        if (!primes[i])
        {
            factor(i);
        }
    }
}
