/*
    + In this game, you have four stacks labeled 1 to 4.
    + The goal is to move symbols (O, X, #) between these stacks 
      such that all symbols in each stack become identical. 
    + You win when all stacks contain the same symbol.
*/
#include <iostream>
#include <vector>
#include <stack>
#include <ctime>
#include <functional>

struct AllElementsSameFunctor {
    // Functor to check if all elements in the stack are the same
    bool operator()(const std::stack<char>& s) const {
        std::vector<char> vec;
        std::stack<char> temp = s;

        while (!temp.empty()) {
            vec.push_back(temp.top());
            temp.pop();
        } // Copy stack elements to vector

        return (s.size() == 4 || s.size() == 0) &&
               std::all_of(vec.begin(), vec.end(), [&](char c) { return c == vec.front(); });
    }
};

void printStack(const std::stack<char>& s, int stackNum) {
    // Function to print the contents of a stack
    std::stack<char> temp = s;
    std::vector<char> stackElements;

    while (!temp.empty()) {
        stackElements.emplace_back(temp.top());
        temp.pop();
    } // Copy stack elements to vector

    std::cout << "Stack " << stackNum << ":" << std::endl;
    std::reverse(stackElements.begin(), stackElements.end()); // Print stack number and elements and reverse the stack

    for (auto it = stackElements.rbegin(); it != stackElements.rend(); ++it) {
        std::cout << "| " << *it << " |\n";
    }

    std::cout << "|___|\n";
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    std::vector<char> numbers = {'O', 'O', 'O', 'O', 'X', 'X', 'X', 'X', '#', '#', '#', '#'};  // Initial symbols to be distributed among stacks

    std::stack<char> stack1, stack2, stack3, stack4; // Stacks and a vector of pointers to stacks
    std::vector<std::stack<char>*> stackVector = {&stack1, &stack2, &stack3, &stack4};

    for (auto it = stackVector.begin(); it != stackVector.end(); ++it) {
        // Randomly share symbols in stacks and print initial stack contents
        size_t index = std::distance(stackVector.begin(), it);
        if (!numbers.empty()) {
            for (int i = 0; i < 4; ++i) {
                int randomIndex = rand() % numbers.size();
                char selectedNumber = numbers[randomIndex];
                numbers.erase(numbers.begin() + randomIndex);
                stackVector[index]->push(selectedNumber);
            }
        }
        printStack(*stackVector[index], index + 1);
    }

    std::function<bool(const std::stack<char>&)> allElementsSame = AllElementsSameFunctor(); // Functor to check if all stacks have identical elements

    while (true) { // Game loop to move symbols between stacks until all stacks are identical
        if (allElementsSame(stack1) && allElementsSame(stack2) && allElementsSame(stack3) && allElementsSame(stack4)) {
            std::cout << "You Won the Game!" << std::endl;
            break;
        } // Check if all stacks contain identical elements

        int fromStack, toStack;
        std::cout << "\nEnter 1.(source stack) and 2.(destination stack) from (1-4): \n";
        std::cout << "Enter Source Stack:";
        std::cin >> fromStack;
        std::cout << "Enter Destination Stack:";
        std::cin >> toStack; // Get the Input of user

        std::stack<char>* from = (fromStack == 1) ? &stack1 : (fromStack == 2) ? &stack2 : (fromStack == 3) ? &stack3 : &stack4;
        std::stack<char>* to = (toStack == 1) ? &stack1 : (toStack == 2) ? &stack2 : (toStack == 3) ? &stack3 : &stack4;

        if (to->size() < 4 && !(from->empty())) {
            char elementToMove = from->top();
            from->pop();
            to->push(elementToMove); // Move the top element from 'from' stack to 'to' stack if conditions are met

            for (int i = 0; i < 4; ++i) {
                printStack(*stackVector[i], i + 1);
            }
        }
    }

    return 0;
}