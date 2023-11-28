//Создайте класс "Товар" с атрибутами, 
//такими как наименование, количество, цена.
//Реализуйте класс "Склад", который будет 
//содержать список товаров и методы для подсчета 
//общей стоимости и количества товаров на складе.с++

#include <iostream>
#include <string>
#include <vector>

class Product {
private:
	std::string product_name;
	int quantity;
	double price;
public:
	Product() {};
	Product(const std::string& product_name, int quantity, double price) {
		this->product_name = product_name;
		this->quantity = quantity;
		this->price = price;
	}
	std::string getName() const {
		return product_name;
	}
	int getQuantity() const {
		return quantity;
	}
	double getPrice() const {
		return price;
	}
};

class Warehouse {
private:
	std::vector<Product> products;
public:
	void addProduct(const Product& prod) {
		products.push_back(prod);
	}
	double calcCost() const {
		double totalCost = 0.0f;
		for (auto& prod : products) {
			totalCost += prod.getQuantity() * prod.getPrice();
		}
		return totalCost;
	}
	int calcQuantity() const {
		int totalQuantity = 0;
		for (auto& prod : products) {
			totalQuantity += prod.getQuantity();
		}
		return totalQuantity;
	}
};

int main() {
	setlocale(LC_ALL, "rus");
	Product prod1("Сигареты", 300, 120);
	Product prod2("Водка", 30, 350);

	Warehouse wer;
	wer.addProduct(prod1);
	wer.addProduct(prod2);

	std::cout << "Стоимость товара на складе: " << wer.calcCost() << std::endl;
	std::cout << "Общее количество товара на складе: " << wer.calcQuantity() << std::endl;





	return 0;
}