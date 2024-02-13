#include <iostream>
#include <vector>

// Інтерфейс ітератора
template<typename T>
class Iterator {
public:
    virtual T next() = 0;
    virtual bool hasNext() = 0;
    virtual ~Iterator() {}
};

// Конкретний ітератор для вектора
template<typename T>
class VectorIterator : public Iterator<T> {
private:
    std::vector<T> vec;
    size_t index;

public:
    VectorIterator(const std::vector<T>& v) : vec(v), index(0) {}

    T next() override {
        return vec[index++];
    }

    bool hasNext() override {
        return index < vec.size();
    }
};

// Колекція, яка використовує ітератор
template<typename T>
class Aggregate {
private:
    std::vector<T> elements;

public:
    void add(const T& element) {
        elements.push_back(element);
    }

    Iterator<T>* createIterator() {
        return new VectorIterator<T>(elements);
    }
};

int main() {
    
    Aggregate<int> aggregate;
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);

    Iterator<int>* it = aggregate.createIterator();

    while (it->hasNext()) {
        std::cout << it->next() << " ";
    }
    std::cout << std::endl;

    delete it;

    return 0;
}
