#include <iostream>
#include <string>

using namespace std;

string getResponse(string input) {
    // Basic responses based on input
    if (input == "Hello" || input == "Hi")
        return "Hi there! How can I help you?";
    else if (input == "How are you?")
        return "I'm just a computer program, but thanks for asking!";
    else if (input == "What's your name?")
        return "I'm a chatbot created by OpenAI.";

    // If input doesn't match any predefined responses
    return "I'm sorry, I didn't understand that.";
}

int main() {
    cout << "Welcome! How can I assist you today?" << endl;
    cout << "You can start chatting. Type 'exit' to end the conversation." << endl;

    string userInput;
    while (true) {
        cout << "User: ";
        getline(cin, userInput);

        if (userInput == "exit")
            break;

        string response = getResponse(userInput);
        cout << "Bot: " << response << endl;
    }

    cout << "Goodbye! Have a great day!" << endl;

    return 0;
}
