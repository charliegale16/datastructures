
#pragma once

#include <iostream>
#include <string>

class GroceryItem

{
private:

	std::string _upc;

	std::string _brandName;

	std::string _productName;

	double _price = 0.0;

public:

	GroceryItem() = default;

	std::string upc() const;
	GroceryItem(const std::string& productName, const std::string& brandName, const std::string& upc, double price);
	void upc(const std::string& upc);


	std::string brandName() const;
	void brandName(const std::string& brandName);


	std::string productName() const;
	void productName(const std::string& productName);


	double price() const;
	void price(double amount);

	//insertion and Exraction operators
	friend std::ostream& operator<<(std::ostream& stream, const GroceryItem& groceryItem);
	friend std::istream& operator>>(std::istream& stream, GroceryItem& groceryItem);

	friend bool operator==(const GroceryItem& lhs, const GroceryItem& rhs);
	friend bool operator< (const GroceryItem& lhs, const GroceryItem& rhs);

	/*// Logical Operators
	bool operator==(const GroceryItem& lhs, const GroceryItem& rhs);
	bool operator!=(const GroceryItem& lhs, const GroceryItem& rhs);

	bool operator< (const GroceryItem& lhs, const GroceryItem& rhs);
	bool operator<=(const GroceryItem& lhs, const GroceryItem& rhs);
	bool operator> (const GroceryItem& lhs, const GroceryItem& rhs);
	bool operator>=(const GroceryItem& lhs, const GroceryItem& rhs);

	*/
};
