// Project #1: Stats
// By: Seamus Tynan
#include <iostream>
#include <iomanip>
#include <cassert>
#include "stats.h"

using namespace std;

stats::stats()	// Constructor initializes all values equal to zero when first called.
{
	reset();
}

void stats::next(double r) // Computes the: min, max, and total based on the value of r. Also updates count.
{
	if (count == 0) // Used in the first iteration of next();
	{
		minimum = r;
		maximum = r;
	}
	else
	{
		if (r > minimum && r > maximum)
		{
			maximum = r;
		}
		else
		{
			minimum = r;
		}
	}
	count++;
	total += r;
}

void stats::reset()	// Re-initializes all main values to 0.
{
	count = 0;
	total = 0;
	minimum = 0;
	maximum = 0;
}

void stats::setcount(int c)	// Sets the count.
{
	count = c;
}

void stats::settotal(double t)	// Sets the total.
{
	total = t;
}

void stats::setminimum(double min) // sets the minimum value.
{
	minimum = min;
}

void stats::setmaximum(double max) // sets the maximum value.
{
	maximum = max;
}

int stats::getcount() const // returns the count.
{
	return count;
}

double stats::gettotal() const // returns the total.
{
	return total;
} 

double stats::mean() const // returns the mean.
{
	assert(getcount() > 0); 
	return static_cast<double>(total) / count;
}

double stats::getminimum() const // returns the minimum.
{
	return minimum;
}

double stats::getmaximum() const // returns the maximum.
{
	return maximum;
}

// NON-MEMBER functions for the stats class
// operator==, returns true or false based on member variables and mean.
bool operator== (const stats& left, const stats& right)
{
	return (left.getminimum() == right.getminimum() && left.getmaximum() == right.getmaximum() && left.getcount() == right.getcount() && left.gettotal() == right.gettotal() && left.mean() == right.mean());
}

//operator+, returns statistician s after adding count and total, 
//and determining which side has the lowest min and hghest max.
stats operator+ (const stats& left, const stats& right) 
{
	stats s;
	s.setcount(left.getcount() + right.getcount());
	s.settotal(left.gettotal() + right.gettotal());


	// if statements determine which side has smallest value to get passed.
	if (left.getminimum() < right.getminimum())
	{
		s.setminimum(left.getminimum());
	}

	else if (left.getminimum() > right.getminimum())
	{
		s.setminimum(right.getminimum());
	}

	else
	{
		s.setminimum(left.getminimum());
	}

	// if statements determine which side has highest value to get passed.
	if (left.getmaximum() > right.getmaximum())
	{
		s.setmaximum(left.getminimum());
	}

	else if (left.getmaximum() < right.getmaximum())
	{
		s.setmaximum(right.getmaximum());
	}

	else
	{
		s.setmaximum(left.getmaximum());
	}

	return s;
}

// operator*, returns statistician s after multiplying a constant by a statistician.
stats operator* (double scale, const stats& right) 
{
	stats s; 
	s.setcount(scale * right.getcount());
	s.settotal(scale * right.gettotal());
	s.setminimum(scale * right.getminimum());
	s.setmaximum(scale * right.getmaximum());
	return s;
}

stats operator* (const stats & left, double scale)
{
	stats s;
	s.setcount(left.getcount() * scale);
	s.settotal(left.gettotal() * scale);
	s.setminimum(left.getminimum() * scale);
	s.setmaximum(left.getmaximum() * scale);
	return s;
}

ostream& operator<< (ostream & cout, const stats & right) 
{ 
	if (right.getcount() != 0)
	{
		cout << "************Contents of Statistician************" << endl;
		cout << std::left << setw(20) << " * COUNT " <<  " => " << right.getcount() << endl;
		cout << std::left << setw(20)<< " * TOTAL " << " => " << right.gettotal() << endl;
		cout << std::left << setw(20) << " * MEAN " << " => " << right.mean() << endl;
		cout << std::left << setw(20) << " * MINIMUM " <<  " => " << right.getminimum() << endl;
		cout << std::left << setw(20) << " * MAXIMUM " <<  " => " << right.getmaximum() << endl << endl;
	}
	else
		cout << "There are no numbers in the statistician!" << endl;

	return cout;
}
