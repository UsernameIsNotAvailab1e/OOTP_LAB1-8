#include <iostream>
#include <memory>
#include <Windows.h>
// Абстрактний клас продукту
class Product {
public:
    virtual void operation() = 0;
    virtual ~Product() {}
};

// Конкретні реалізації продукту
class ConcreteProduct1 : public Product {
public:
    void operation() override {
        std::cout << "Викликано операцію ConcreteProduct1" << std::endl;
    }
};

class ConcreteProduct2 : public Product {
public:
    void operation() override {
        std::cout << "Викликано операцію ConcreteProduct2" << std::endl;
    }
};

// Абстрактний клас фабрики
class Creator {
public:
    virtual std::shared_ptr<Product> factoryMethod() = 0;
    virtual ~Creator() {}
};

// Конкретні реалізації фабрики
class ConcreteCreator1 : public Creator {
public:
    std::shared_ptr<Product> factoryMethod() override {
        return std::make_shared<ConcreteProduct1>();
    }
};

class ConcreteCreator2 : public Creator {
public:
    std::shared_ptr<Product> factoryMethod() override {
        return std::make_shared<ConcreteProduct2>();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Використання фабричного методу
    std::shared_ptr<Creator> creator1 = std::make_shared<ConcreteCreator1>();
    std::shared_ptr<Product> product1 = creator1->factoryMethod();
    product1->operation();

    std::shared_ptr<Creator> creator2 = std::make_shared<ConcreteCreator2>();
    std::shared_ptr<Product> product2 = creator2->factoryMethod();
    product2->operation();

    return 0;
}