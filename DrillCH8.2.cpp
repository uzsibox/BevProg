#include "std_lib_facilities.h"

//-------------------------------------------------------------

void swap_v(int a, int b)
{
    int temp;
    temp = a, a = b;
    b = temp;

    cout << "swap_v     x: " << a << "   y: " << b << endl;

}

//-------------------------------------------------------------

void swap_r(int& a, int& b) //referenciák, value nem adható át
{
    int temp;
    temp = a, a = b;
    b = temp;

    cout << "swap_r     x: " << a << "   y: " << b << endl;
}

//-------------------------------------------------------------

 void swap_cr(const int& a, const int& b) //konstansokat nem lehet változtatni
{
     int temp;
    temp = a; 
 
    //a = b;
    //b = temp;

    cout << "swap_cr     x: " << a << "   y: " << b << endl;
}

int main() {
        /*int x = 7;
        int y = 9;
        swap_v(x, y);
        swap_v(7, 9);
        const int cx = 7;
        const int cy = 9;
        swap_v(cx, cy);
        swap_v(7.7, 9.9);
        double dx = 7.7;
        double dy = 9.9;
        swap_v(dx, dy);
        swap_v(7.7, 9.9);*/

   /* int x = 7;
    int y = 9;
    swap_r(x, y);
    //swap_r(7, 9);  //Ez a verzió nem tud intbõl int&be konvertálni 
    const int cx = 7;
    const int cy = 9;
    //swap_r(cx, cy); //Ez a verzió sem mûködik
    //swap_r(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    //swap_r(dx, dy);
    //swap_r(7.7, 9.9);*/

    int x = 7;
    int y = 9;
    swap_cr(x, y);
    swap_cr(7, 9);  
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx, cy); 
    swap_cr(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_cr(dx, dy);
    swap_cr(7.7, 9.9);

}