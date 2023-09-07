#include <iostream>
#include <cmath>
using namespace std;

class point
{
    int a, b;

public:
    void setData(int x, int y)
    {
        a = x;
        b = y;
    }
    float distance(point A, point B)
    {
        float c = sqrt((A.a - B.a) * (A.a - B.a) + (A.b - B.b) * (A.b - B.b));
        return c;
    }
};

int main()
{
    int x, y;
    cout << "Enter the values for x and y coordinates respectively: ";
    cin >> x >> y;
    point C, D, R;
    C.setData(x, y);
    cout << "Enter the other values for x and y coordinates respectively: ";
    cin >> x >> y;
    D.setData(x, y);
    float c = R.distance(C, D);
    cout << "The distance between two points is " << c << endl;

    return 0;
}