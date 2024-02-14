#include <iostream>
#include <stdlib.h>
#include <math.h>

# define NMAX 10

using namespace std;

struct Point{
        int x,y;};  //Объявление структуры Point

float dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){

    Point m[NMAX];
    Point zero={0,0};
    Point nearest_zero;
    int i,a=-100,b=100;
    float dmin,d;
  
    for (i=0;i<NMAX;i++){
        m[i].x=a+rand()%(b-a);
        m[i].y=a+rand()%(b-a);
    }
    cout << "Points:" << endl;
    for (i=0;i<NMAX;i++){
        cout << "(" << m[i].x << ";" << m[i].y << ") ";
    }

    cout << endl;

    dmin=dist(m[0],zero);
    nearest_zero=m[0];
    Point father_zero = m[0];
    float dmax = 0;

    for (i=0;i<NMAX;i++){
        d=dist(m[i],zero);
        cout << "point " << i << ": " << d << endl;
        if (d<dmin){
            nearest_zero=m[i];
            dmin=d;
        }
        if (d > dmax){
            father_zero = m[i];
            dmax = d;
        }
    }

    cout << "Nearest zero point:"<< endl;
    cout << "(" << nearest_zero.x << ";" << nearest_zero.y << ") " << endl;
    cout << "Farther zero point:"<< endl;
    cout << "(" << father_zero.x << ";" << father_zero.y << ") " << endl;

    dmin = dist(m[0],m[1]);

    for (i=1;i<NMAX;i++){
        d=dist(m[0],m[i]);
        if (d<dmin){
            nearest_zero=m[i];
            dmin=d;
        }
    }

    cout << "Nearest to m[0] point:"<< endl;
    cout << "(" << nearest_zero.x << ";" << nearest_zero.y << ") " << endl;

    dmin = m[0].x;
    Point father_Y = m[0];

    for (i = 0; i < NMAX; i ++){
        if (dmin < m[i].x) {
            dmin = m[i].x;
            father_Y = m[i];
        }
    }

    cout << "Father Y:" << endl;
    cout << "(" << father_Y.x << ";" << father_Y.y << ") " << endl;

    dmin = dist(m[0], m[1]);
    Point nearestpt1 = m[0], nearestpt2 = m[1];

    for (i = 0; i < NMAX; i ++){
        for (int j = i + 1; j < NMAX; j++){
            d = dist(m[i],m[j]);
            if (d < dmin){
                nearestpt1 = m[i];
                nearestpt2 = m[j];
                dmin = d;
            }
        }
    }
    
    cout << "Nearest points:" << endl;
    cout << "(" << nearestpt1.x << ";" << nearestpt1.y << ") U " << "(" << nearestpt2.x << ";" << nearestpt2.y << ") " << endl;
    return 0;
}