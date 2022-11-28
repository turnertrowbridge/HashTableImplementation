#include <iostream>
#include "MyHashTable.h"

using namespace std;

int main() {
    MyHashTable shoppingCart;
    shoppingCart.set("apple", 5);        // sets apples to 5
    shoppingCart.set("orange", 10);      // sets orange to 10
    shoppingCart.set("banana", 2);       // set banana to 1
    shoppingCart.set("watermelon", 1);   // sets watermelon to 1
    shoppingCart.set("watermelon", 15);  // overwrites watermelon to 15
    shoppingCart.add("watermelon", 5);   // add 5 watermelons, 20 watermelons total
    shoppingCart.set("peach", -5);       // tries to add -5 peaches and gets error

    cout << "Cart has " << shoppingCart.get("apple") << " apples" << endl;
    cout << "Cart has " << shoppingCart.get("orange") << " oranges" << endl;
    cout << "Cart has " << shoppingCart.get("banana") << " bananas" << endl;
    cout << "Cart has " << shoppingCart.get("watermelon") << " watermelons" << endl;

    shoppingCart.removeAll("banana"); // remove banana
    cout << shoppingCart.get("banana") << endl; // returns -1 indicating no bananas
    shoppingCart.removeAll("pear"); // remove banana

    shoppingCart.remove("watermelon", 4); // removes 4 watermelons, 16 watermelons total
    cout << "Cart has " << shoppingCart.get("watermelon") << " watermelons" << endl;

    shoppingCart.remove("watermelon", 50000); // attempts to remove an invalid amount of watermelons and gets error
    cout << "Cart has " << shoppingCart.get("watermelon") << " watermelons" << endl; // still 16 watermelons total











    MyHashTable myHashTable1(5000);

    return 0;
}
