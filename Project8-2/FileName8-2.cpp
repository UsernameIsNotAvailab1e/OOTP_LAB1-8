#include <iostream>
#include <string>
#include <Windows.h>
// ���������, ���� ��������������� �볺����
class Target {
public:
    virtual std::string request() const = 0;
    virtual ~Target() {}
};

// ����, ���� �� ������ ����������
class Adaptee {
public:
    std::string specificRequest() const {
        return "����������� �����";
    }
};

// �������, ���� ��������� �������� �� Target � Adaptee
class Adapter : public Target {
private:
    Adaptee* adaptee;

public:
    Adapter(Adaptee* adaptee) : adaptee(adaptee) {}

    std::string request() const override {
        return "�������: " + adaptee->specificRequest();
    }

    ~Adapter() {
        delete adaptee;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ������������ ����� Adaptee ����� Adapter
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);

    std::cout << adapter->request() << std::endl;

    // ��������� ���'��
    delete adapter;

    return 0;
}
