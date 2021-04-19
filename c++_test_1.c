#include <iostream>
using namespace std;
class Point {

    private:
        int x, y, choice;
    public:
        Point(int _x=1, int _y=1) {
            x = _x;
            y = _y;
            choice = 0;
        }
        void set(int X, int Y, int CH);
        void show();
        void input();
        int getX();
        int getY();
        int getC();

};

void Point::show() {
    cout << "default : [(" << getX() << "," << getY() << ")]" << endl << "x : " << getX() <<endl<< "y : " << getY() <<endl << "choice : " << getC() <<endl;
}
void Point::set(int X,int Y,int CH) {
    x = X;
    y = Y;
    choice = CH;
}
void Point::input() {
    Point p;
    cin >> x;
    cin >> y;
    cin >> choice;
    switch (choice) {
    case 0:
        set(1, 1, 0);
        break;
    default:
        set(x, y, choice);
    }
}
int Point::getX() { return x; }
int Point::getY() { return y; }
int Point::getC() { return choice; }

int main() {
    Point p(1,1);
    p.show();
    cout << "Input x,y,choice :";
    p.input();
    p.show();
}
