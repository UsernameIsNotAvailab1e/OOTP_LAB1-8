#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
// ��'��� "������", ���� ������ ���� ���������
class EditorMemento {
public:
    EditorMemento(const std::string& content) : content(content) {}

    const std::string& getContent() const {
        return content;
    }

private:
    std::string content;
};

// ��'��� "�������", ���� ������ �� ���� ������ �� ������ ���������
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

// ��'��� ���������, � ����� ����� �������� �� ����������� ����
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
    // ��������� ��������� �� ��������
    Editor editor;
    EditorCareTaker careTaker;

    // �������� �� �������� ����� ���������
    editor.setContent("���� 1");
    careTaker.addMemento(editor.createMemento());

    editor.setContent("���� 2");
    careTaker.addMemento(editor.createMemento());

    // ³��������� �������� �����
    editor.restoreFromMemento(careTaker.getMemento(0));
    std::cout << "ϳ��� ���������� ����������� ����� 1: " << editor.getContent() << std::endl;

    editor.restoreFromMemento(careTaker.getMemento(1));
    std::cout << "ϳ��� ���������� ����������� ����� 2: " << editor.getContent() << std::endl;

    return 0;
}
