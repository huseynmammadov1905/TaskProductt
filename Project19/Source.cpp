
#include <iostream>

using namespace std;



// Kechilenlerin her biri istifade olunsun
// Initializer list, Delegate, getter setter

//class : Product
//	fields : id, name, description, price, discount
//	methods : ShowProduct(), GetPriceWithDiscount()
//
//
//	Stock{
//	   char* name
//	   Product *	// array
//	   Print()	// show all product in Stock
//	   Product GetProduct(int id);
//}


class Product {
	int id;
	char* name;
	char* description;
	double price;
	short discount;

public:

	Product() :id(0), name(nullptr), description(nullptr), price(0), discount(0) {
	}

	Product(int id, const char* name, const char* description, double price, short discount) {
		SetID(id);
		SetName(name);
		SetDescription(description);
		SetPrice(price);
		SetDiscount(discount);
	}
#pragma region Getter
	int GetID() { return id; }

	char* GetName() { return name; }

	char* GetDesc() { return description; }

	double GetPrice() { return price; }

	short GetDiscount() { return discount; }

#pragma endregion

#pragma region Setter

	void SetID(int id) {
		this->id = id < 0 ? 1 : id;
	}

	void SetName(const char* name) {

		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);

	}

	void SetDescription(const char* description) {

		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void SetPrice(double price) {
		this->price = price;
	}

	void SetDiscount(short discount) {
		this->discount = discount;
	}

#pragma endregion

#pragma region Method

	void ShowProduct() {
		cout << "id : " << id << endl;
		cout << "name : " << name << endl;
		cout << "description : " << description << endl;
		cout << "price : " << price << endl;
		cout << "discount : " << discount << endl;
		cout << "Get price with discount : " << GetPriceWithDiscount() << endl << endl;
	}

	double  GetPriceWithDiscount() {
		double newprice = 0;
		newprice = price - (price * discount / 100);
		return newprice;
	}

#pragma endregion
};

class Stock {
	char* name;
	int size = 4;
	Product* products = new Product[size]{
		{1, "Banana" , "yellow fruit", 10, 25},
		{2,"Apple" , "iphone fruit", 15, 20},
		{3,"Milk","white water",40,15},
		{4,"fish","animal",50,10}
	};

public:
	Stock() :name(nullptr) {

	}
	~Stock() {
		delete name;
	}

	void Print() {
		for (int i = 0; i < size; i++)
		{
			products[i].ShowProduct();
		}
	}

	Product GetProduct(int id) {
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetID() == id)
				return products[i];
		}
	}
};

int main() {
	Stock products;
	products.Print();
}