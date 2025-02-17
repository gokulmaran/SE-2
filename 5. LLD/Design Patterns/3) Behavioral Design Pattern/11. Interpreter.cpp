/*Concept
The Interpreter Pattern is a behavioral design pattern used to evaluate and interpret expressions defined in a language. It defines a grammatical representation for a language 
and provides an interpreter to evaluate sentences in the language.*/
#include <iostream>
#include <string>
#include <sstream>

// Abstract Expression
class Expression {
public:
    virtual int interpret() const = 0;
    virtual ~Expression() = default;
};

// Terminal Expression: Represents a number
class Number : public Expression {
private:
    int value;

public:
    explicit Number(int val) : value(val) {}

    int interpret() const override {
        return value;
    }
};

// Non-Terminal Expression: Represents addition
class Add : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    Add(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() const override {
        return left->interpret() + right->interpret();
    }

    ~Add() {
        delete left;
        delete right;
    }
};

// Non-Terminal Expression: Represents subtraction
class Subtract : public Expression {
private:
    Expression* left;
    Expression* right;

public:
    Subtract(Expression* left, Expression* right) : left(left), right(right) {}

    int interpret() const override {
        return left->interpret() - right->interpret();
    }

    ~Subtract() {
        delete left;
        delete right;
    }
};

// Simple Parser: Converts expression to a tree (without complex error handling)
Expression* parse(const std::string& expression) {
    std::istringstream stream(expression);
    int num1, num2;
    char op;

    stream >> num1 >> op >> num2;

    Expression* left = new Number(num1);
    Expression* right = new Number(num2);

    if (op == '+') {
        return new Add(left, right);
    } else if (op == '-') {
        return new Subtract(left, right);
    }

    return nullptr;
}

int main() {
    std::string expr = "3 + 5";
    Expression* parsedExpression = parse(expr);

    if (parsedExpression) {
        std::cout << "Result: " << parsedExpression->interpret() << std::endl;
        delete parsedExpression; // Clean up
    }

    return 0;
}
