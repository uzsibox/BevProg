#include "std_lib_facilities.h"

int main()
{
    cout << "Write  | to exit \n";
    
   

	//cm, m, in, ft. Assume conversion factors
	//  1m == 100cm, 
	// 1in ==2.54cm,
	// 1ft == 12in.
	const double mTocm = 100, inTocm = 2.54, ftToin = 12;
	string units;
	double number;
	
	cout << "Enter a number with its units (cm, m, in, ft): ";
	while (cin >> number >> units) {
		if (units == "in") {
			cout << number << " inches is " << number * inTocm << " cm" << endl;       //Spacel elválasztva (eg 14 m ) nem veszi be
		}
		else if (units == "m") {
			cout << number << " m is " << number * mTocm << " cm" << endl;
		}
		else if (units == "cm") {
			cout << number << " cm is " << number / mTocm << " m" << endl;
		}
		else if (units == "ft") {
			cout << number << " ft is " << number * ftToin << " inches" << endl;
		}
		else cout << "I don't know those units!" << endl;

        if (number == '|')
            break;
    }
    return 0;
}