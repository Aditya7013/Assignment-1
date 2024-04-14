#include <iostream>
#include <vector>
#include <string>

// Base class representing an item on a bill
class Item {
protected:
  // Item name (e.g., Pizza, Cola)
  std::string name;
  // Price per unit (e.g., price per kg for food, price per liter for drinks)
  double price;

public:
  // Constructor to create an item with a name and price
  Item(const std::string& n, double p) : name(n), price(p) {}

  // This function needs to be defined differently for FoodItem and DrinkItem
  // because they calculate cost differently. We declare it as virtual here.
  virtual double calculateCost() const = 0;
};

// Class representing a food item (inherits from Item)
class FoodItem : public Item {
private:
  // Weight of the food item (e.g., in kilograms)
  double weight;

public:
  // Constructor to create a FoodItem with name, price per unit (e.g., per kg), and weight
  FoodItem(const std::string& n, double p, double w) : Item(n, p), weight(w) {}

  // Calculates the total cost of the food item by multiplying price by weight
  double calculateCost() const override {
    return price * weight;
  }
};

// Class representing a drink item (inherits from Item)
class DrinkItem : public Item {
private:
  // Volume of the drink item (e.g., in liters)
  double volume;

public:
  // Constructor to create a DrinkItem with name, price per unit (e.g., per liter), and volume
  DrinkItem(const std::string& n, double p, double v) : Item(n, p), volume(v) {}

  // Calculates the total cost of the drink item by multiplying price by volume
  double calculateCost() const override {
    return price * volume;
  }
};

// Class representing a bill that holds items and calculates the total cost
class Bill {
private:
  // A list of items on the bill (using pointers)
  std::vector<Item*> items;

public:
  // Add an item to the bill
  void addItem(Item* item) {
    items.push_back(item);
  }

  // Calculate the total cost of all items on the bill
  double getTotalCost() const {
    double total = 0;
    // Loop through all items in the list
    for (Item* item : items) {
      // Call the calculateCost function on each item (polymorphism)
      total += item->calculateCost();
    }
    return total;
  }
};

int main() {
  Bill bill;

  // Create food items with name, price per unit, and weight
  FoodItem pizza("Pizza", 10.99, 0.5); // $10.99 per kg, 0.5 kg
  FoodItem salad("Salad", 5.99, 0.3);   // $5.99 per kg, 0.3 kg

  // Create drink items with name, price per unit, and volume
  DrinkItem cola("Cola", 1.99, 0.5);    // $1.99 per liter, 0.5 liter
  DrinkItem juice("Juice", 2.49, 0.3);  // $2.49 per liter, 0.3 liter

  // Add items to the bill
  bill.addItem(&pizza);
  bill.addItem(&salad);
  bill.addItem(&cola);
  bill.addItem(&juice);

  // Display the total cost of all items on the bill
  std::cout << "Total cost: $" << bill.getTotalCost() << std::endl;

  return 0;
}