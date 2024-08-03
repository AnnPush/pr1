#include <iostream>

using std:: cout;
using std:: cin;
using std:: endl;

#include <cmath>

const double PI = 3.14159;

inline double circleArea(const double r)
{return PI * pow(r, 2);}

int main()
{
    double radius;
    cout << "Enter the length of the radius of your sphere: ";
    cin >> radius;
    cout << "Volume of sphere with radius " << radius << " is " << circleArea(radius) << endl;
}
//kknll
