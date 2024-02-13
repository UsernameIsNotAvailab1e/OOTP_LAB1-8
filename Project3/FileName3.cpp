#include <iostream>
#include <Windows.h>
// ����������� ���� ������㳿
class Strategy {
public:
    virtual void execute() = 0;
    virtual ~Strategy() {}
};

// �������� ��������� ������㳿
class ConcreteStrategy1 : public Strategy {
public:
    void execute() override {
        std::cout << "���������� �������� 1" << std::endl;
    }
};

class ConcreteStrategy2 : public Strategy {
public:
    void execute() override {
        std::cout << "���������� �������� 2" << std::endl;
    }
};

// ��������
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
    // ��������� ��������� � ���������� ������㳺�
    Context context(new ConcreteStrategy1());

    // ������������ ������㳿
    context.executeStrategy();

    // ���� ������㳿
    context.setStrategy(new ConcreteStrategy2());

    // ������������ ���� ������㳿
    context.executeStrategy();

    return 0;
}
