#define __USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

void print(Point a) {
    cout << fixed << setprecision(8) << a.x << " " << a.y << endl;
}

void koch(int n, Point a, Point b) {
    if (n == 0) return;

    Point s, t, u;
    double r = 60.0 / 180.0 * M_PI;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = s.x + (t.x - s.x) * cos(r) - (t.y - s.y) * sin(r);
    u.y = s.y + (t.x - s.x) * sin(r) + (t.y - s.y) * cos(r);

    koch(n - 1, a, s);
    print(s);
    koch(n - 1, s, u);
    print(u);
    koch(n - 1, u, t);
    print(t);
    koch(n - 1, t, b);
}

int main() {
    Point a, b;
    int n;
    cin >> n;

    a.x = 0.0;
    a.y = 0.0;
    b.x = 100.0;
    b.y = 0.0;

    print(a);
    koch(n, a, b);
    print(b);

    return 0;
}