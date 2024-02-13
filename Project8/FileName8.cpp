#include <iostream>
#include <string>
#include <Windows.h>
// ������� ���� ����������
class Component {
public:
    virtual std::string operation() const = 0;
    virtual ~Component() {}
};

// ��������� ��������� ����������
class ConcreteComponent : public Component {
public:
    std::string operation() const override {
        return "������ ���������������";
    }
};

// ������� ���� ����������
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

// �������� ����������
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(Component* component) : Decorator(component) {}

    std::string operation() const override {
        return "���������� �� ConcreteDecoratorA -> " + Decorator::operation();
    }
};

class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(Component* component) : Decorator(component) {}

    std::string operation() const override {
        return "���������� �� ConcreteDecoratorB -> " + Decorator::operation();
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ��������� ��'���� ���������� �� ����������
    Component* component = new ConcreteComponent();
    Decorator* decoratorA = new ConcreteDecoratorA(component);
    Decorator* decoratorB = new ConcreteDecoratorB(decoratorA);

    // ������ ������ �������� ����� ���������
    std::cout << decoratorB->operation() << std::endl;

    // ��������� ���'��
    delete decoratorB;

    return 0;
}
