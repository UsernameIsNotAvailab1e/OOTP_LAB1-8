#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
// Об'єкт "Снимок", який зберігає стан редактора
class EditorMemento {
public:
    EditorMemento(const std::string& content) : content(content) {}

    const std::string& getContent() const {
        return content;
    }

private:
    std::string content;
};

// Об'єкт "Зберігач", який зберігає та надає доступ до снимків редактора
class EditorCareTaker {
public:
    void addMemento(EditorMemento* memento) {
        mementos.push_back(memento);
    }

    EditorMemento* getMemento(size_t index) const {
        if (index >= 0 && index < mementos.size()) {
            return mementos[index];
        }
        return nullptr;
    }

private:
    std::vector<EditorMemento*> mementos;
};

// Об'єкт редактора, з якого можна зберігати та відновлювати стан
class Editor {
public:
    void setContent(const std::string& content) {
        this->content = content;
    }

    const std::string& getContent() const {
        return content;
    }

    EditorMemento* createMemento() const {
        return new EditorMemento(content);
    }

    void restoreFromMemento(const EditorMemento* memento) {
        if (memento) {
            content = memento->getContent();
        }
    }

private:
    std::string content;
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення редактора та зберігача
    Editor editor;
    EditorCareTaker careTaker;

    // Редагуємо та зберігаємо стани редактора
    editor.setContent("Стан 1");
    careTaker.addMemento(editor.createMemento());

    editor.setContent("Стан 2");
    careTaker.addMemento(editor.createMemento());

    // Відновлюємо попередні стани
    editor.restoreFromMemento(careTaker.getMemento(0));
    std::cout << "Після відновлення збереженого стану 1: " << editor.getContent() << std::endl;

    editor.restoreFromMemento(careTaker.getMemento(1));
    std::cout << "Після відновлення збереженого стану 2: " << editor.getContent() << std::endl;

    return 0;
}
