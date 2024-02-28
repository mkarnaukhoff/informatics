#include <iostream>
#include <math.h>

using namespace std;

struct Product{
    string name;
    float price;
    int amount;
};

Product generator(int max_price, int max_amount, int max_weight){
	Product x;
	string colors[] = {"red", "blue", "white", "black", "yellow", "green"};
	string companies[] = {"apple", "samsung", "honor", "xiasomi", "google", "compucter"};
	x.price = rand()%(max_price);
	x.amount = rand()%(max_amount);
	x.name = companies[rand()%(size(companies))];
  return x;
}

void print(Product q){
	cout << "Name: " << q.name;
	cout << ", price: " << q.price;
	cout << ", amount: " << q.amount << endl;
}

int main()
{
    int n;
    cin >> n;
    Product m[n];
    for(int i = 0; i < n; i++) {
        //cin >> m[i].name >> m[i].price >> m[i].amount;
        m[i] = generator(100, 100, 100);
    }
    int k = 0;
    Product ans[4];
    int min_now = m[0].price * m[0].amount;
    int total_cost_now;
    int index_min_now;
    int max_total = 0;
    int total_now;
    for(int i = 0; i < n; i ++){
        total_now = m[i].price * m[i].amount;
        if (total_now > max_total) {
            max_total = total_now;
        }
    }

    while (k < 4) {
        min_now = max_total;
        for(int i = 0; i < n; i ++){
            
            total_cost_now = m[i].price * m[i].amount;
            if (((total_cost_now) <= min_now) && (total_cost_now > 0)) {
                min_now = total_cost_now;
                index_min_now = i;
            }
        }
        for (int i = 0; i < n; i ++){
        }
        ans[k] = m[index_min_now];
        m[index_min_now].price = -1;
        k++;
    }

    for(int i = 0; i < 4; i ++ ){
        cout << ans[i].name << " " << ans[i].price << " " << ans[i].amount << endl; 
    }
    return 0;
}
