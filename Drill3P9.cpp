#include "std_lib_facilities.h"

int main()
{
	cout << "Write  | to exit \n";


	//cm, m, in, ft. Assume conversion factors 
	//1m == 100cm, 
	//1in == 2.54cm,
	//1ft == 12in.
	double smallestSoFar = numeric_limits<double>::max();
	double largestSoFar = numeric_limits<double>::min();

	const double mTocm = 100, inTocm = 2.54, ftToin = 12, inTom = 0.0254, ftTom = 0.3048;
	string units;
	double number, sum = 0, count = 0;

	cout << "Enter a number with its units (cm, m, in, ft): ";
	while (cin >> number >> units) {
		if (units == "in") {
			cout << number << " inches is " << number * inTom << " m" << endl;
			sum += number * inTom;
			if (number * inTom > largestSoFar) largestSoFar = number * inTom;
			if (number * inTom < smallestSoFar) smallestSoFar = number * inTom;
			count++;
		}
		else if (units == "m") {
			cout << number << " m is " << number << " m" << endl;
			sum += number;
			if (number > largestSoFar) largestSoFar = number;
			if (number < smallestSoFar) smallestSoFar = number;
			count++;

		}
		else if (units == "cm") {
			cout << number << " cm is " << number / mTocm << " m" << endl;
			sum += number / mTocm;
			if (number / mTocm > largestSoFar) largestSoFar = number / mTocm;
			if (number / mTocm < smallestSoFar) smallestSoFar = number / mTocm;
			count++;

		}
		else if (units == "ft") {
			cout << number << " ft is " << number * ftTom << " m" << endl;
			sum += number * ftTom;
			if (number * ftTom > largestSoFar) largestSoFar = number * ftTom;
			if (number * ftTom < smallestSoFar) smallestSoFar = number * ftTom;
			count++;

		}
		else cout << "I don't know those units!" << endl;
		cout << "The smallest so far is " << smallestSoFar << endl
			<< "The largest so far is " << largestSoFar << endl
			<< "The total so far is " << sum << endl
			<< "Count is " << count << endl;

		if (number == '|')
			break;
	}
	return 0;
}