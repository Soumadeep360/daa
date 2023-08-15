#include <bits/stdc++.h>
using namespace std;
#define ll long long int


// Method 1: Middle School Method
ll middleSchoolGCD(ll a, ll b)
{
    ll gcd;

    for (ll i = 1; i <= a && i <= b; i++)
    {
        // Checks if i is factor of both integers
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }

    return gcd;
}

// Method 2: Euclid's Algorithm with Division
ll euclideanDivisionGCD(ll a, ll b)
{
    while (b != 0)
    {
        ll remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// Method 3: Euclid's Algorithm with Subtraction
ll euclideanSubtractionGCD(ll a, ll b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main()
{
    ll num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate GCD using three methods
    clock_t s, e, s1, e1, s2, e2;

    s = clock();
    cout << "Middle School Method GCD: " << middleSchoolGCD(num1, num2) << endl;
    e = clock();
    cout << "Time taken :" << (double)(e - s) / CLOCKS_PER_SEC << endl;

    s1 = clock();
    cout << "Euclidean Algorithm (Division) GCD: " << euclideanDivisionGCD(num1, num2) << endl;
    e1 = clock();
    cout << "Time taken : " << (double)(e1 - s1) / CLOCKS_PER_SEC << endl;

    s2 = clock();
    cout << "Euclidean Algorithm (Subtraction) GCD: " << euclideanSubtractionGCD(num1, num2) << endl;
    e2 = clock();
    cout << "Time taken : " << (double)(e2 - s2) / CLOCKS_PER_SEC << endl;

    return 0;
}
