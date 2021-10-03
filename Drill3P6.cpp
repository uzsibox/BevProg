#include "std_lib_facilities.h"

int main()
{
    cout << "Write  numbers seperated by enter,  use . for doubles , | to exit \n";
    double smallestSoFar = numeric_limits<double>::max();
    double largestSoFar = numeric_limits<double>::min();
   

    double x = 0;
   

    while (cin >> x) {
        if (largestSoFar < x) {
            largestSoFar = x;
            cout << " The largest so far is " << x << "\n";
        }

        if (smallestSoFar > x) {
            smallestSoFar = x;
            cout << " The smallest so far is " << x << "\n";                                    //Csak az utolsó beütést tárolja
        }

        if (x == '|')
            break;
    }
    return 0;
}