#include <iostream>
#include <string>
#include <Windows.h>
// Базовий клас компонента
class Component {
public:
    virtual std::string operation() const = 0;
    virtual ~Component() {}
};

// Конкретна реалізація компонента
class ConcreteComponent : public Component {
public:
    std::string operation() const override {
        return "Базова функціональність";
    }
};

// Базовий клас декоратора
class Decorator : public Component {
protected:
    Component* component;

public:
    Decorator(Component* component) : component(component) {}

    std::string operation() const override {
        if (component) {
            return component->operation();
        }
        return "";
    }

    virtual ~Decorator() {
        delete component;
    }
};

// Конкретні декоратори
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string operation() const override {
        return "Доповнення від ConcreteDecoratorA -> " + Decorator::operation();
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    std::string operation() const override {
        return "Доповнення від ConcreteDecoratorB -> " + Decorator::operation();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення об'єктів компонентів та декораторів
    Component* component = new ConcreteComponent();
    Decorator* decoratorA = new ConcreteDecoratorA(component);
    Decorator* decoratorB = new ConcreteDecoratorB(decoratorA);

    // Виклик методу операції через декоратор
    std::cout << decoratorB->operation() << std::endl;

    // Звільнення пам'яті
    delete decoratorB;

    return 0;
}
