#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Point{
        int x,y;}; 

float dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    int n;
    float r;  
    cin >> n;
    int temp_x, temp_y;
    int count = 0;
    int x_max, x_min, y_max, y_min;
    cin >> temp_x >> temp_y;

    x_max = temp_x;
    x_min = temp_x;
    y_max = temp_y;
    y_min = temp_y;

    for (int i = 1; i < n; i++){
        cin >> temp_x >> temp_y;
        if (temp_x > x_max) x_max = temp_x;
        if (temp_x < x_min) x_min = temp_x;
        if (temp_y > y_max) y_max = temp_y;
        if (temp_y < y_min) y_min = temp_y;
    }

    cout << x_max << ' ' << y_max << ' ' << x_min << ' ' << y_min;


}