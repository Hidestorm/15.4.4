#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item_base
{
public:
	Item_base(const string &book = "", double sales_price = 0.0) :
		isbn(book), price(sales_price) {
		cout << "Using item_base's constructor." << endl;
	}
	string book() const {
		return isbn;
	}
	virtual double net_price(rsize_t n) const {
		return price * n;
	}
	virtual ~Item_base() {
		cout << "Using item_base's destructor." << endl;
		system("pause");
	}
	friend ostream &operator << (ostream &, Item_base &);
private:
	string isbn;
protected:
	double price;
};


ostream & operator << (ostream & os, Item_base & ib)
{
	os << "\t Using operator << " << endl
		<< "\t Visit item_base's book:\t" << ib.isbn << endl
		<< "\tVisit item_base's net_price():"
		<< "\t3 ¡¶" << ib.book() << "¡·,The price is :"
		<< ib.net_price(3) << endl;
	return os;
}


class Bulk_item :public Item_base
{
public:
	Bulk_item(const string &book = "", double slae_price
	= 0.0, size_t qty = 0, double disc = 0.0):
		Item_base(book, slae_price), min_qty(qty),discount(disc)
	{
		cout << "Using Bulk_item's constructor." << endl;
	}
	double net_price(size_t cnt)const
	{
		if (cnt > min_qty)
			return cnt * (1 - discount) * price;
		else
			return cnt * price;
	}
	~Bulk_item()
	{
		cout << "Using Bulk_item's destructor." << endl;
		system("pause");
	}
private:
	size_t min_qty;
	double  discount;
};

ostream & operator << (ostream & os, Bulk_item &bi)
{
	os << "\t Using operator << (Bulk_item)" << endl
		<< "\t Visit Bulk_item's book():\t" << bi.book()
		<< endl
		<< "\tVisit Bulk_item's net_price():"
		<< "/t5   ¡¶" << bi.book() << "¡·,the price is :\t"
		<< bi.net_price(5) << endl;
	return os;
}

int main()
{
	Item_base base("C++ Primer", 42.00);
	Bulk_item bulk("How to program", 50.32, 3, 0.2);
	cout << base << endl;
	cout << bulk << endl;
	system("pause");
	return 0;
}