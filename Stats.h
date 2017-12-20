// Project #1: Stats
// By: Seamus Tynan
#include <iostream>
using namespace std;
#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
class stats
{
public:
	// CONSTRUCTOR
	stats();
	// MODIFICATION MEMBER FUNCTIONS
	void next(double r);
	void reset();
	void setcount(int c);
	void settotal(double t);
	void setminimum(double min);
	void setmaximum(double max);
	// CONSTANT MEMBER FUNCTIONS
	int getcount() const;
	double gettotal() const;
	double mean() const;
	double getminimum() const;
	double getmaximum() const;
private:
	int count;       // How many numbers in the sequence
	double total;    // The sum of all the numbers in the sequence
	double minimum;  // The smallest number in the sequence
	double maximum;  // The largest number in the sequence
};
// NON-MEMBER functions for the stats class
bool operator== (const stats& left, const stats& right);
stats operator+ (const stats& left, const stats& right);
stats operator* (double scale, const stats& right);
stats operator* (const stats & left, double scale);
ostream& operator<< (ostream & cout, const stats & right);
#endif
