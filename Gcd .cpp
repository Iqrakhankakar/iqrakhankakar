#include <iostream>
#include <cstdlib> 

using namespace std;

int result_num, result_den;

void add_fractions(int, int, int, int);
void sub_fractions(int, int, int, int);
void multiply_fractions(int, int, int, int);
void divide_fractions(int, int, int, int);
void display_result();

int gcd(int, int);
void simplify_fraction(int&, int&);

int main() {
    int f1_num, f1_den, f2_num, f2_den;
    char dummy; 

    cout << "Enter first fraction e.g. 2/3\t";
    cin >> f1_num >> dummy >> f1_den;
    if (f1_den == 0) {
        cerr << "Error: Denominator of the first fraction cannot be zero." << endl;
        return 1;
    }

    cout << "Enter second fraction e.g. 3/4\t";
    cin >> f2_num >> dummy >> f2_den;
    if (f2_den == 0) {
        cerr << "Error: Denominator of the second fraction cannot be zero." << endl;
        return 1;
    }

    cout << "Adding fractions results in \t";
    add_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();  
    cout << endl;

    cout << "Subtracting fractions results in \t";
    sub_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();  
    cout << endl;

    cout << "Multiplying fractions results in \t";
    multiply_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();  
    cout << endl;

    cout << "Dividing fractions results in \t";
    divide_fractions(f1_num, f1_den, f2_num, f2_den);
    display_result();
    cout << endl;

    return 0;
}

void add_fractions(int f1_num, int f1_den, int f2_num, int f2_den) {
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den + f2_num * f1_den;
    simplify_fraction(result_num, result_den);
}

void sub_fractions(int f1_num, int f1_den, int f2_num, int f2_den) {
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_den - f2_num * f1_den;
    simplify_fraction(result_num, result_den);
}

void multiply_fractions(int f1_num, int f1_den, int f2_num, int f2_den) {
    result_den = f1_den * f2_den;
    result_num = f1_num * f2_num;
    simplify_fraction(result_num, result_den);
}

void divide_fractions(int f1_num, int f1_den, int f2_num, int f2_den) {
    if (f2_num == 0) {
        cerr << "Error: Division by zero is not allowed." << endl;
        return;
    }
    result_num = f1_num * f2_den;
    result_den = f1_den * f2_num;
    simplify_fraction(result_num, result_den);
}

void display_result() {
    if (result_den == 1) {
        cout << result_num;
    } else if (result_num == 0) {
        cout << 0;
    } else {
        cout << result_num << "/" << result_den;
    }
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplify_fraction(int& num, int& den) {
    int divisor = gcd(abs(num), abs(den));
    num /= divisor;
    den /= divisor;
    if (den < 0) { s
        num = -num;
        den = -den;
    }
}
