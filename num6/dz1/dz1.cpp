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
    cin >> n >> r;
    int temp_x, temp_y;
    int count = 0;

    for (int i = 0; i < n; i++){
        cin >> temp_x >> temp_y;
        if (sqrt(temp_x * temp_x + temp_y * temp_y) < r) {
            count++;
        }
    }

    cout << count;


}