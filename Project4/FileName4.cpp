#include <iostream>
#include <vector>
#include <Windows.h>
// ������� ���� �������
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// �������� �������
class LightOnCommand : public Command {
public:
    void execute() override {
        std::cout << "������� �����" << std::endl;
    }
};

class TVOnCommand : public Command {
public:
    void execute() override {
        std::cout << "������� ��������" << std::endl;
    }
};

// ���� ��� ������������� ������������
class MacroCommand : public Command {
private:
    std::vector<Command*> commands;

public:
    void addCommand(Command* command) {
        commands.push_back(command);
    }

    void execute() override {
        for (Command* command : commands) {
            command->execute();
        }
    }

    ~MacroCommand() {
        for (Command* command : commands) {
            delete command;
        }
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ��������� ����� �������
    Command* lightOn = new LightOnCommand();
    Command* tvOn = new TVOnCommand();

    // ��������� ������������
    MacroCommand* macroCommand = new MacroCommand();
    macroCommand->addCommand(lightOn);
    macroCommand->addCommand(tvOn);

    // �������� ������������
    macroCommand->execute();

    // ��������� ���'���
    delete macroCommand;

    return 0;
}
