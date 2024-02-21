#include <iostream>
#include <fstream>
#include <math.h>

# define NMAX 10

using namespace std;

struct Point{

        int x,y;};  //Объявление структуры Point

float dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){

    Point *m;
    int i,n,count;
    ifstream input;
    input.open("input.txt");
    input >> n;

    m = new Point[n];

    for (i = 0; i < n; i++){
       input >> m[i].x >> m[i].y;
    }
    cout << "Points:" << endl;
    for (i = 0; i < n ; i++){
        cout << "(" << m[i].x << ";" << m[i].y << ") ";
    }
    cout << endl;

    input.close();

    count = 0;
    for (i=0;i<n;i++){
        if (m[i].x>0 && m[i].y>0){count++;};
    }

    cout << "In first quart: " << count << " points"<< endl;

    return 0;
}