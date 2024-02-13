#include <iostream>
#include <Windows.h>
// Абстрактний клас стратегії
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

// Конкретні реалізації стратегії
class ConcreteStrategy1 : public Strategy {
public:
    void execute() override {
        std::cout << "Виконується стратегія 1" << std::endl;
    }
};

class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "Виконується стратегія 2" << std::endl;
    }
};

// Контекст
class Context {
private:
    Strategy* strategy;

public:
    Context(Strategy* strategy) : strategy(strategy) {}

    void setStrategy(Strategy* newStrategy) {
        delete strategy;
        strategy = newStrategy;
    }

    void executeStrategy() {
        strategy->execute();
    }

    ~Context() {
        delete strategy;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення контексту з конкретною стратегією
    Context context(new ConcreteStrategy1());

    // Використання стратегії
    context.executeStrategy();

    // Зміна стратегії
    context.setStrategy(new ConcreteStrategy2());

    // Використання нової стратегії
    context.executeStrategy();

    return 0;
}
