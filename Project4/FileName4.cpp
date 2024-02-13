#include <iostream>
#include <vector>
#include <Windows.h>
// Базовий клас команди
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() {}
};

// Конкретні команди
class LightOnCommand : public Command {
public:
    void execute() override {
        std::cout << "Вмикаємо світло" << std::endl;
    }
};

class TVOnCommand : public Command {
public:
    void execute() override {
        std::cout << "Вмикаємо телевізор" << std::endl;
    }
};

// Клас для представлення макрокоманди
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
    // Створюємо окремі команди
    Command* lightOn = new LightOnCommand();
    Command* tvOn = new TVOnCommand();

    // Створюємо макрокоманду
    MacroCommand* macroCommand = new MacroCommand();
    macroCommand->addCommand(lightOn);
    macroCommand->addCommand(tvOn);

    // Виконуємо макрокоманду
    macroCommand->execute();

    // Звільняємо пам'ять
    delete macroCommand;

    return 0;
}
