#include <iostream>
 
using namespace std;
 
int main(){
 
  struct Product{
    char name[10]; 
    float price; 
    int amount;};  //Объявление структуры product
    
  Product p={"Apple",9.5,12};
  Product q;
 
  cout << p.name << " " << p.price << " " << p.amount << endl;
  cout << "Enter product name: ";
  cin >> q.name;
  cout << "Enter product price: ";
  cin >> q.price;
  cout << "Enter product amount: ";
  cin >> q.amount;
  cout << q.name << " " << q.price << " " << q.amount << endl;
  
  return 0;
}