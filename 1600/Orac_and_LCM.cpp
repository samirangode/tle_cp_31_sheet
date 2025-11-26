#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

const int MAX_A = 200000 + 1;

std::vector<int> SPF(MAX_A); // Smallest Prime Factor

void computeSPF() {
    for (int i = 0; i < MAX_A; ++i)
        SPF[i] = i;
    for (int i = 2; i * i < MAX_A; ++i) {
        if (SPF[i] == i) {
            for (int j = i * i; j < MAX_A; j += i)
                if (SPF[j] == j)
                    SPF[j] = i;
        }
    }
}

void factorize(int num, std::map<int, int>& factors) {
    while (num > 1) {
        int prime = SPF[num];
        int count = 0;
        while (num % prime == 0) {
            num /= prime;
            count++;
        }
        factors[prime] += count;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    computeSPF();

    std::map<int, std::vector<int>> primeExponents;

    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        int num = a[i];
        std::map<int, int> factors;
        factorize(num, factors);
        for (const auto& f : factors) {
            primeExponents[f.first].push_back(f.second);
        }
    }

    long long result = 1;

    for (auto& p : primeExponents) {
        auto& exponents = p.second;
        if (exponents.size() < n - 1)
            continue; // Exponent in gcd(t) is 0

        // Fill missing exponents with zeros
        exponents.resize(n, 0);
        std::sort(exponents.begin(), exponents.end());

        int exponentInGCD;
        if (exponents[0] == exponents[1]) {
            exponentInGCD = exponents[0];
        } else {
            exponentInGCD = exponents[1];
        }

        for (int i = 0; i < exponentInGCD; ++i)
            result *= p.first;
    }

    std::cout << result << std::endl;
    return 0;
}

