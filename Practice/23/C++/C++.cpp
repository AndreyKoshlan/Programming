#include <iostream>
#include <iomanip>
#include "factorials.h"
#include "taylor.h"
#include "combinations.h"

const double pi = 3.14159265358979323846;
const int FACTORIALS_LIMIT = 10;
const double TAYLOR_STEP = pi / 180;
const double TAYLOR_LIMIT = pi / 4;
const int TAYLOR_ITERATION_COUNT = 5;
const int TAYLOR_PRECISION = 4;
const int COMBINATIONS_N = 10;
const int COMBINATIONS_START = 1;
const int COMBINATIONS_END = 10;

using std::cout;
using std::cin;
using std::endl;

int main() {
    /* ~ factorials ~ */
	cout << "n" << "\t" << "n!" << endl;
	for (int i = 1; i <= FACTORIALS_LIMIT; i++) {
		cout << i << "\t" << fact(i) << endl;
	}
	cout << endl;

	/* ~ Taylor series ~ */
	cout << "x" << "\t" << "sin(x)" << endl;
	for (double i = 0; i <= TAYLOR_LIMIT; i += TAYLOR_STEP) {
		cout << std::setprecision(TAYLOR_PRECISION) << i << "\t";
		cout << sin(i, TAYLOR_ITERATION_COUNT) << endl;
	}
	cout << endl;

	/* ~ combinations ~ */
	cout << "k" << "\t" << "C(k, " << COMBINATIONS_N << ")" << endl;
	for (int i = COMBINATIONS_START; i <= COMBINATIONS_END; i++) {
		cout << i << "\t" << comb(i, COMBINATIONS_N) << endl;
	}
}