#include <iostream>
#include <fstream>
#include <math.h>
 
# define NMAX 10
 
using namespace std;
 
struct Point{
        int x,y;};  
 
float dist(Point a, Point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 
int main(){
    
    int i,j,k,n,r;
    cin >> n;
 
    Point m[n];
 
    for (i=0;i<n;i++){
       cin >> m[i].x >> m[i].y;
    }
 
 float max=0, dk;
 for (i=0;i<n;i++){
  for (j=i+1;j<n-1;j++){
   dk=dist(m[i],m[j]);
   if (dk>max){
    max=dk;
   }
  }
 }
 
    float d;
 float d1=max, d2=max, d3=max;
 for (i=0;i<n;i++){
  for (j=i+1;j<n;j++){
   d=dist(m[i],m[j]);
   if (d<d1 && d <d2 && d<d3){
    d1=d2;
    d2=d3;
    d3=d;
   }
  }
 }
 
  
    cout << d1<<endl;
 cout << d2<<endl;
 cout << d3<<endl;
    return 0;
}