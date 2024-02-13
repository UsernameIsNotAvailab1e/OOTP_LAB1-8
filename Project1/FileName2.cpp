#include <iostream>
#include <unordered_map>

// ����������� ���� ���������
class Prototype {
public:
    virtual Prototype* clone() = 0;
    virtual void info() = 0;
    virtual ~Prototype() {}
};

// �������� ��������� ���������
class ConcretePrototype1 : public Prototype {
public:
    Prototype* clone() override {
        return new ConcretePrototype1(*this);
    }

    void info() override {
        std::cout << "ConcretePrototype1" << std::endl;
    }
};

class ConcretePrototype2 : public Prototype {
public:
    Prototype* clone() override {
        return new ConcretePrototype2(*this);
    }

    void info() override {
        std::cout << "ConcretePrototype2" << std::endl;
    }
};

// ����������� ��������
class PrototypeManager {
public:
    Prototype* getPrototype(const std::string& type) {
        if (prototypes.find(type) != prototypes.end()) {
            return prototypes[type]->clone();
        }
        return nullptr;
    }

    void registerPrototype(const std::string& type, Prototype* prototype) {
        prototypes[type] = prototype;
    }

private:
    std::unordered_map<std::string, Prototype*> prototypes;
};

int main() {
    // ��������� ��������� ���������
    PrototypeManager manager;

    // �������� �������� ���������
    manager.registerPrototype("ConcretePrototype1", new ConcretePrototype1());
    manager.registerPrototype("ConcretePrototype2", new ConcretePrototype2());

    // ��������� ��� ��'���� �� ����� ���������
    Prototype* prototype1 = manager.getPrototype("ConcretePrototype1");
    if (prototype1) {
        prototype1->info();
        delete prototype1;
    }

    Prototype* prototype2 = manager.getPrototype("ConcretePrototype2");
    if (prototype2) {
        prototype2->info();
        delete prototype2;
    }

    return 0;
}