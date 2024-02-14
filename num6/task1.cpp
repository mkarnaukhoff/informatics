#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){

    struct Product{
        string name; 
        float price; 
        int amount;
        string color;
        float weight;
        };
 
    int i,n;
    float user_price;
 
    ifstream input;
    ofstream output;
    input.open("input.txt");
    input >> n;


    Product *m;
    m = new Product[n];
    for (i = 0; i < n; i++){
        input >> m[i].name >> m[i].price >> m[i].amount >> m[i].color >> m[i].weight;
    }
    input.close();

    for (i = 0; i < n; i++){
        cout << "m["<< i << "] = " << m[i].name << " " << m[i].price << " " << m[i].amount << " " << m[i].color << " " << m[i].weight << endl;
    }

    cout << "Enter user price: ";
    cin >> user_price;
    float total_price = 0;
    int total_red = 0;
    float total_weight = 0;
    int amount_counter = 0;

    // 2 пункт 

    for (i = 0; i < n; i++){ 
        if (m[i].price > user_price) { // общую стоимость товаров, у которых вес больше заданного
            total_price += m[i].amount * m[i].price;
        }
        if (m[i].color == "red") total_red += m[i].amount; // количество товаров с цветом "red"
        total_weight += m[i].amount * m[i].weight; // общий вес товаров
        amount_counter += m[i].amount;
    }

    // 3 пункт
    output.open("output.txt");
    output << "Вывести в файл output.txt товары, у которых вес больше среднего веса всех товаров:" << endl;

    float avg_weight = total_weight / amount_counter;
    
    for (i = 0; i < n; i ++){
        if (m[i].weight > avg_weight) {
            output << m[i].name << endl;
        }
    }

    // Начальный код 

    output << "Начальный:" << endl;
    
    for (i = 0; i < n; i++){
        if (m[i].price > user_price){
            output << m[i].name << " " << m[i].price << endl;
        }
    }

    // 4 пункт

    output << "Вывести в файл output.txt 5 самых дорогих товаров:" << endl;
    
    int k = 0;
    
    float min_now = m[0].price;
    for(i = 0; i < n; i++){
        if (m[i].price < min_now) min_now = m[i].price;
    }

    float max_now;

    while(k < 5) {
        max_now = min_now;
        for(i = 0; i < n; i ++) {
            if (max_now < m[i].price){
                output << m[i].name << '\t' << m[i].price << endl;
                m[i].price = -1;
                break;
            }
        }
        k++;
    }

    output.close();

    delete[] m;

  return 0;
}