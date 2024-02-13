#include <iostream>
#include <string>
#include <Windows.h>
// Інтерфейс, який використовується клієнтом
class Target {
public:
    virtual std::string request() const = 0;
    virtual ~Target() {}
};

// Клас, який ми хочемо адаптувати
class Adaptee {
public:
    std::string specificRequest() const {
        return "Специфічний запит";
    }
};

// Адаптер, який забезпечує сумісність між Target і Adaptee
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    std::string request() const override {
        return "Адаптер: " + adaptee->specificRequest();
    }

    ~Adapter() {
        delete adaptee;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Використання класу Adaptee через Adapter
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);

    std::cout << adapter->request() << std::endl;

    // Звільнення пам'яті
    delete adapter;

    return 0;
}
