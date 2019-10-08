#include "Gi.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <limits>
#include <utility>


namespace {
	constexpr auto EPSILON = 1.0E-4;
}



GroceryItem::GroceryItem(const std::string& productName,
	const std::string& brandName,
	const std::string& upc,
	double price)
	: _upc(upc),
	_brandName(brandName),
	_productName(productName),
	_price(price)

{}  // constructor with decleration



std::string GroceryItem::upc() const

{
	return _upc;

}


void GroceryItem::upc(const std::string& upc)

{
	_upc = upc;

}



std::string GroceryItem::brandName() const

{
	return _brandName;

}



void GroceryItem::brandName(const std::string& brandName) //brand name setter

{
	_brandName = brandName;

}



std::string GroceryItem::productName() const	// product name getter

{
	return _productName;

}



void GroceryItem::productName(const std::string& productName)		// product name setter

{
	_productName = productName;

}



double GroceryItem::price() const // price getter

{
	return _price;

}


void GroceryItem::price(double price)   // price setter

{
	_price = price;

}

// function to output the items details

std::istream& operator>>(std::istream& stream, GroceryItem& groceryItem)

{
	GroceryItem workingItem;

	stream >> std::quoted(workingItem._upc)
		>> std::quoted(workingItem._brandName)
		>> std::quoted(workingItem._productName)
		>> workingItem._price;

	stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	groceryItem = std::move(workingItem);

	return stream;

}

// function to read the item details

std::ostream& operator<<(std::ostream& stream, const GroceryItem& groceryItem)

{
	stream << "UPC: " << std::quoted(groceryItem.upc()) << ","
		<< "Brand: " << std::quoted(groceryItem.brandName()) << ","
		<< "Product: " << std::quoted(groceryItem.productName()) << " ,"
		<< "Price: $" << groceryItem.price() << '\n';
	return stream;

}

// Logical operators

bool operator==(const GroceryItem& lhs, const GroceryItem& rhs)
{
	if constexpr ((true))
	{
		return		lhs._upc == rhs._upc
			&& lhs._productName == rhs._productName
			&& lhs._brandName == rhs._brandName
			&& std::abs(lhs._price - rhs._price) < EPSILON;
	}

	else
	{
		return !(lhs < rhs) && !(rhs < lhs);
	}

}

bool operator< (const GroceryItem& lhs, const GroceryItem& rhs)
{
	if (auto result = lhs._upc.compare(rhs._upc);                 result != 0)	return result < 0;
	if (auto result = lhs._productName.compare(rhs._productName); result != 0)	return result < 0;
	if (auto result = lhs._brandName.compare(rhs._brandName);     result != 0)  return result < 0;
	if (std::abs(lhs._price - rhs._price) >= EPSILON)							    return lhs._price < rhs._price;

	return false;

}

bool operator!=(const GroceryItem& lhs, const GroceryItem& rhs) { return !(lhs == rhs); }
bool operator<=(const GroceryItem& lhs, const GroceryItem& rhs) { return !(lhs < rhs); }
bool operator> (const GroceryItem& lhs, const GroceryItem& rhs) { return !(lhs < rhs); }
bool operator>=(const GroceryItem& lhs, const GroceryItem& rhs) { return !(lhs < rhs); }
