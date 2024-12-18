#include <iostream>
#include <fstream>

struct Fraction{
    int num, den;
    Fraction(int num = 0, int den = 1) : num(num), den(den) {}
};

int fGCD(int a, int b) {
	if (a == b || b == 0) return a;
	else return fGCD(b, a % b);
}

// Simplify the fraction
Fraction simplify(Fraction A) {
	int GCD = fGCD(abs(A.num), abs(A.den));
	if (A.den < 0) {
		A.num /= -1;
		A.den /= -1;
	}
	A.num /= GCD;
	A.den /= GCD;
    return A;
}

int main() {
    std::fstream input("input1.2.txt");
    int n,m, num, den;
    input >> m >> n;
    //create a vector of Fraction with the size of m x n
    std::vector<std::vector<Fraction>> arr(m, std::vector<Fraction>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            input >> num >> den;
            arr[i][j] = simplify({num, den});
        }
    }
    std::fstream output("output1.2.txt", std::ios::out);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            output << arr[i][j].num << '/' << arr[i][j].den << ' ';
        }
        output << '\n';
    }
    input.close();
    output.close();
}