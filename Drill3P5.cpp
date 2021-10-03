#include "std_lib_facilities.h"

int main()
{
    cout << "Write 2 numbers seperated by enter, | to exit the program , use . for doubles \n";
    double x = 0;
    double y = 0;

    while (cin >> x >> y) {
        if (x == '|' or y == '|')
            break;
        if (x < y)
            cout << " The smaller value is " << x;
        if (x > y)
            cout << " The smaller value is " << y;
        if (x < y)
            cout << "  The larger value is " << y;
        if (x > y)
            cout << "  The larger value is " << x;
        if (x - y < (1 / 100)  ||  y - x < (1 / 100)   )
            cout << " The numbers are almost equal";
        if (x == y)
           cout << " The numbers are equal ";                                   
                                                                                

        
    }
    return 0;
}