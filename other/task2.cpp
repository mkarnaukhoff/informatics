#include <iostream>
#include <stdlib.h>
 
# define NMAX 10
 
using namespace std;
 
struct Product{
  string name; 
  float price; 
  int amount; 
	string color;
	int weight;
};

Product generator(int max_price, int max_amount, int max_weight){
	Product x;
	string colors[] = {"red", "blue", "white", "black", "yellow", "green"};
	string companies[] = {"apple", "samsung", "honor", "xiasomi", "google", "compucter"};
	x.price = rand()%(max_price);
	x.amount = rand()%(max_amount);
	x.color = colors[rand()%(size(colors))];
	x.name = companies[rand()%(size(companies))];
	x.weight = rand()%(max_weight);
  return x;
}

void print(Product q){
	cout << "Name: " << q.name;
	cout << ", price: " << q.price;
	cout << ", amount: " << q.amount;
	cout << ", color: " << q.color;
	cout << ", weight: " << q.weight << endl;
}
 
int main(){
    
  Product m[NMAX];
  float res;
  int mprice = 100, mamount = 10, mweight = 10;
  
  for (int i=0;i<NMAX;i++){
    m[i] = generator(mprice, mamount, mweight);
  }
  
  for (int i=0;i<NMAX;i++){
    print(m[i]);
  }
  
  
  int total_cost = 0;
  int total_weight = 0;
  int total_weight_c = 0;
  int total_price_of_goods = 0;
  int total_price = 0;
  int total_amount = 0;
  
  for (int i=0;i<NMAX;i++){
	  total_amount += m[i].amount;
	  total_weight += m[i].weight * m[i].amount;
	  if (char(m[i].name[0]) == 'c') total_weight_c += m[i].weight * m[i].amount;
	  total_price_of_goods += m[i].price * m[i].amount;
    total_price += m[i].price;
  }
  cout << endl;
  cout << "Total weight: " << total_weight << endl;
  cout << "Total weight 'C': " << total_weight_c << endl;
  cout << "Average price of goods: " << (float)total_price_of_goods / total_amount << endl;
  cout << "Average total price: " <<  (float)total_price / NMAX << endl;

  int max_price = m[0].price;
  int min_price = m[0].price;
  int max_amount = m[0].amount;
  int price = 10; // заданная цена
  int count = 0;
  for (int i = 0; i < NMAX; i++) {
	  if (m[i].price > max_price) max_price = m[i].price;
	  if (m[i].price < min_price) min_price = m[i].price; 	
	  if (m[i].amount > max_amount) max_amount = m[i].amount;
	  if (m[i].price > price) count += m[i].amount;
  }
  cout << endl;

  cout << "Maximum price: " << max_price << endl;
  cout << "Minimum price: " << min_price << endl;
  cout << "Maximum amount: " << max_amount << endl;
  cout << "Products with a price higher than " << price << ": " << count << endl;

  return 0;
}