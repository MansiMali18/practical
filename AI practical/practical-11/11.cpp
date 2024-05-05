#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

// Pizza struct to store pizza information
struct Pizza {
    string name;
    string description;
    map<string, double> prices; // Price for each size
};

// Function to initialize available pizzas
vector<Pizza> initializePizzas() {
    vector<Pizza> pizzas;
    
    // Define pizzas and their prices
    Pizza margherita = {"Margherita", "Classic cheese pizza with tomato sauce and mozzarella cheese", {{"Small", 8.99}, {"Medium", 10.99}, {"Large", 12.99}}};
    Pizza pepperoni = {"Pepperoni", "Classic pepperoni pizza with tomato sauce, mozzarella cheese, and pepperoni slices", {{"Small", 9.99}, {"Medium", 11.99}, {"Large", 13.99}}};
    Pizza veggieSupreme = {"Veggie Supreme", "Loaded with fresh vegetables including bell peppers, onions, mushrooms, olives, and tomatoes", {{"Small", 10.99}, {"Medium", 12.99}, {"Large", 14.99}}};
    
    // Add pizzas to the vector
    pizzas.push_back(margherita);
    pizzas.push_back(pepperoni);
    pizzas.push_back(veggieSupreme);
    
    return pizzas;
}

// Function to display available pizzas
void displayAvailablePizzas(const vector<Pizza>& pizzas) {
    cout << "Available Pizzas:" << endl;
    for (const auto& pizza : pizzas) {
        cout << "Name: " << pizza.name << endl;
        cout << "Description: " << pizza.description << endl;
        cout << "Sizes and Prices:" << endl;
        for (const auto& sizePrice : pizza.prices) {
            cout << "- " << sizePrice.first << ": $" << sizePrice.second << endl;
        }
        cout << endl;
    }
}

// Function to handle user input and process orders
void processOrder(const vector<Pizza>& pizzas) {
    string userInput;
    cout << "Welcome to PizzaBot! How can I assist you today?" << endl;
    cout << "Type 'menu' to see available pizzas or 'exit' to end the conversation." << endl;
    cout << "User: ";
    getline(cin, userInput);
    
    while (userInput != "exit") {
        if (userInput == "menu") {
            displayAvailablePizzas(pizzas);
        } else {
            cout << "Sorry, I didn't understand that. Type 'menu' to see available pizzas or 'exit' to end the conversation." << endl;
        }
        cout << "User: ";
        getline(cin, userInput);
    }
}

int main() {
    // Initialize available pizzas
    vector<Pizza> pizzas = initializePizzas();
    
    // Process user orders
    processOrder(pizzas);
    
    cout << "Thank you for using PizzaBot. Have a great day!" << endl;
    
    return 0;
}
