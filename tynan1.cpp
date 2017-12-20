// Project #1: Stats
// By: Seamus Tynan
#include <iostream>
#include <iomanip>
#include <cassert>
#include "stats.h"

using namespace std;

int main()
{
	// Declaration of 6 statisticians to test.
	stats s1, s2, s3, s4, s5, s6;
	int count;
	double user_input; // count and user_input to be used later for s6.


	// Testing next function on s1.
	s1.next(5);
	s1.next(2);

	// Testing set and get functions and operator<<
	cout << setprecision(3) << "Statistician s1 should contain : ";
	cout << "COUNT = 2, TOTAL = 7, MEAN = 3.5, MIN = 2, MAX = 5" << endl << endl << s1 << endl;

	// Add numbers to second statistician.
	s2.next(0);	// Check to see if making zero first number affects results.
	s2.next(3);
	s2.next(5); // Will make max 5, same as s1.

	// Testing if s2 also initialized properly.
	cout << "Statistician s2 should contain : ";
	cout << "COUNT = 3, TOTAL = 8, MEAN = 2.67, MIN = 0, MAX = 5" << endl << endl << s2 << endl;
	
	// Test operator+ by adding s1 and s2 into s3, then display.
	s3 = s1 + s2;
	cout << "Statistician s3 should contain : ";
	cout << "COUNT = 5, TOTAL = 15, MEAN = 3, MIN = 0, MAX = 5" << endl << endl << s3 << endl;

	// Test reset Member function
	s3.reset();
	cout << "Statistician s3 should be empty : " << endl << s3 << endl;

	// Test operator== by checking s1 == s2(false), then s4 == s5(true)
	s4.next(6);
	s4.next(6);
	s5.next(6);
	s5.next(6);
	bool isFalse = s1 == s2;
	bool isTrue = s4 == s5;
	cout << "Statistician s1 == s2 produces the boolean value : " << isFalse << endl;
	cout << "Statistician s1 == s2 produces the boolean value : " << isTrue << endl << endl;

	// Test operator* (scale * right).
	s3 = 2 * s1;
	cout << "Statistician s3 should contain : ";
	cout << "COUNT = 4, TOTAL = 14, MEAN = 3.5, MIN = 4, MAX = 10" << endl << endl << s3 << endl;

	// Test operator* (left * scale).
	s3 = s2 * 4;
	cout << "Statistician s3 should contain : ";
	cout << "COUNT = 12, TOTAL = 32, MEAN = 2.67, MIN = 0, MAX = 20" << endl << endl << s3 << endl;

	// Test user input
	cout << "How many numbers will be in your statistician s6? : ";
	cin >> count;
	for (int i = 0; i < count; i++)
	{
		cout << "Please enter the next value for s6 :";
		cin >> user_input;
		s6.next(user_input);
	}

	cout << "Your statistician s6 contains : " << endl << endl << s6 << endl;

	cout << std::right << setw(50) << "END PROGRAM" << endl << endl;

	system("pause");
	return 0;
}