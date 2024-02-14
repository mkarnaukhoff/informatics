#include <iostream>
#include <math.h>

using namespace std;

struct Product{
    string name;
    float price;
    int amount;
};

int main()
{
    int n; 
    cin >> n; // вводим длину массива
    Product m[n]; // создаем массив m из Product длины n
    float sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> m[i].name >> m[i].price >> m[i].amount;
        sum += m[i].price * m[i].amount;
    }
    cout << round(sum);
}
// Product = {name, price, amount} 
// m = {{name1, price1, amount1}, {name2, price2, amount2}, {name2, price1, amount1}, {name1, price1, amount1}}