#include <iostream>
using namespace std;
// Method 1: Middle School Method
int middleSchoolGCD(int a, int b) {
 int gcd; 

for(int i=1; i <= a && i <= b; i++) 
{ 
// Checks if i is factor of both integers 
if(a%i==0 && b%i==0) 
gcd = i; 
} 

return gcd;
}

// Method 2: Euclid's Algorithm with Division
int euclideanDivisionGCD(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

// Method 3: Euclid's Algorithm with Subtraction
int euclideanSubtractionGCD(int a, int b) {
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

int main() {
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Calculate GCD using three methods
    int middleSchoolResult = middleSchoolGCD(num1, num2);
    int euclideanDivisionResult = euclideanDivisionGCD(num1, num2);
    int euclideanSubtractionResult = euclideanSubtractionGCD(num1, num2);

   cout << "Middle School Method GCD: " << middleSchoolResult << endl;
    cout << "Euclidean Algorithm (Division) GCD: " << euclideanDivisionResult << endl;
    cout << "Euclidean Algorithm (Subtraction) GCD: " << euclideanSubtractionResult << endl;

    return 0;
}
