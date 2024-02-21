#include <iostream>
#include <cmath>

#define NMAX 10000000

using namespace std;

struct Point {
    int x, y;
};

double distance(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int N;
    cin >> N;

    Point points[1000];

    for (int i = 0; i < N; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    double min_distance[3] = {NMAX, NMAX, NMAX};
    
    Point pairs[3][2];

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            float dist = distance(points[i], points[j]);
            for (int k = 0; k < 3; ++k) {
                if (dist < min_distance[k]) {
                    for (int l = 2; l > k; --l) {
                        min_distance[l] = min_distance[l - 1];
                        pairs[l][0] = pairs[l - 1][0];
                        pairs[l][1] = pairs[l - 1][1];
                    }
                    min_distance[k] = dist;
                    pairs[k][0] = points[i];
                    pairs[k][1] = points[j];
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << pairs[i][0].x << " " << pairs[i][0].y << " "
             << pairs[i][1].x << " " << pairs[i][1].y << endl;
    }

    return 0;
}