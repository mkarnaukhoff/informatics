#include <iostream>
 
using namespace std;

struct Product{
    char name[10]; 
    float price; 
    int amount;
	char color[10];
	int weight;
	};  //Объявление структуры product
	
void print(Product q){
	cout << "Name: " << q.name << endl;
	cout << "Price: " << q.price << endl;
	cout << "Amount: " << q.amount << endl;
	cout << "Color: " << q.color << endl;
	cout << "Weight: " << q.weight << endl;
}

Product get_product(){
	Product q;
	cout << "Name: " << endl;
	cin >> q.name;
	cout << "Price: " << endl;
	cin >> q.price;
	cout << "Amount:" << endl;
	cin >> q.amount;
	cout << "Color: " << endl;
	cin >> q.color;
	cout << "Weight: " << endl;
	cin >> q.weight;
	return q;
}
 
int main(){
  Product q;
  q = get_product();
  cout << endl << endl;
  print(q);
  
  return 0;
}