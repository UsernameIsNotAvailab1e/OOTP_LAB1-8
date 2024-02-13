#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <Windows.h>
#include <unordered_map>
// Контекст виразу
class Context {
public:
    void setVariable(const std::string& name, int value) {
        variables[name] = value;
    
    }

    int getVariable(const std::string& name) const {
        if (variables.find(name) != variables.end()) {
            return variables.at(name);
        }
        return 0;
    }

private:
    std::unordered_map<std::string, int> variables;
};

// Базовий клас виразу
class Expression {
public:
    virtual int interpret(Context& context) = 0;
    virtual ~Expression() {}
};

// Термінальний вираз для числа
class NumberExpression : public Expression {
public:
    NumberExpression(int value) : value(value) {}

    int interpret(Context& context) override {
        return value;
    }

private:
    int value;
};

// Нетермінальний вираз для змінної
class VariableExpression : public Expression {
public:
    VariableExpression(const std::string& name) : name(name) {}

    int interpret(Context& context) override {
        return context.getVariable(name);
    }

private:
    std::string name;
};

// Нетермінальний вираз для оператора
class OperatorExpression : public Expression {
public:
    OperatorExpression(Expression* left, Expression* right, char op)
        : left(left), right(right), op(op) {}

    int interpret(Context& context) override {
        int leftValue = left->interpret(context);
        int rightValue = right->interpret(context);

        switch (op) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            if (rightValue != 0) {
                return leftValue / rightValue;
            }
            else {
                throw std::runtime_error("Ділення на нуль!");
            }
        default:
            throw std::invalid_argument("Невідомий оператор");
        }
    }

    ~OperatorExpression() {
        delete left;
        delete right;
    }

private:
    Expression* left;
    Expression* right;
    char op;
};

// Клас для парсінгу і інтерпретації виразу
class Parser {
public:
    Expression* parse(const std::string& expression) {
        std::stack<Expression*> stack;

        std::istringstream iss(expression);
        std::string token;
        while (iss >> token) {
            if (isdigit(token[0])) {
                stack.push(new NumberExpression(std::stoi(token)));
            }
            else if (isalpha(token[0])) {
                stack.push(new VariableExpression(token));
            }
            else if (isOperator(token[0])) {
                Expression* right = stack.top();
                stack.pop();
                Expression* left = stack.top();
                stack.pop();
                stack.push(new OperatorExpression(left, right, token[0]));
            }
        }

        if (stack.size() != 1) {
            throw std::invalid_argument("Невірний формат виразу");
        }

        return stack.top();
    }

private:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    Parser parser;
    Context context;

    context.setVariable("x", 10);
    context.setVariable("y", 5);

    std::string expression = "x y +";
    Expression* parsedExpression = parser.parse(expression);

    std::cout << "Результат виразу " << expression << " = " << parsedExpression->interpret(context) << std::endl;

    delete parsedExpression;

    return 0;
}
