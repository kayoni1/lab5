#include <iostream>
#include <string>
using namespace std;

// Класс для моделирования работы кондиционера
class AirConditioner {
private:
    bool power;       // Состояние: включен/выключен
    int temperature;  // Температура (допустимые значения: 16–30)
    string mode;      // Режим работы (например: "Охлаждение", "Обогрев", "Вентиляция")

public:
    // Конструктор по умолчанию
    AirConditioner() : power(false), temperature(24), mode("Охлаждение") {}

    // Конструктор с параметрами
    AirConditioner(bool pwr, int temp, string md) : power(pwr), temperature(temp), mode(md) {}

    // Метод для включения/выключения кондиционера
    void changePower() {
        power = !power;
        cout << "Кондиционер " << (power ? "включен" : "выключен") << endl;
    }

    // Метод для изменения температуры
    void setTemperature(int temp) {
        if (temp >= 16 && temp <= 30) {
            temperature = temp;
            cout << "Температура установлена на " << temperature << " градусов.\n";
        } else {
            cout << "Ошибка: допустимые значения температуры от 16 до 30 градусов.\n";
        }
    }

    // Метод для изменения режима работы
    void setMode(const string& newMode) {
        if (newMode == "Охлаждение" || newMode == "Обогрев" || newMode == "Вентиляция") {
            mode = newMode;
            cout << "Режим работы изменён на: " << mode << endl;
        } else {
            cout << "Ошибка: некорректный режим работы.\n";
        }
    }

    // Метод для отображения текущего состояния
    void displayState() const {
        cout << "\nТекущее состояние кондиционера:\n";
        cout << "Состояние: " << (power ? "Включен" : "Выключен") << endl;
        cout << "Температура: " << temperature << " градусов" << endl;
        cout << "Режим работы: " << mode << endl;
    }
};

// Главное меню программы
void menu(AirConditioner& ac) {
    int choice;
    while (true) {
        cout << "\nМеню управления кондиционером:\n";
        cout << "1. Включить/выключить кондиционер\n";
        cout << "2. Изменить температуру\n";
        cout << "3. Изменить режим работы\n";
        cout << "4. Показать текущее состояние\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                ac.changePower();
                break;
            case 2: {
                int temp;
                cout << "Введите температуру (16–30): ";
                cin >> temp;
                ac.setTemperature(temp);
                break;
            }
            case 3: {
                string mode;
                cout << "Введите режим работы (Охлаждение, Обогрев, Вентиляция): ";
                cin >> mode;
                ac.setMode(mode);
                break;
            }
            case 4:
                ac.displayState();
                break;
            case 5:
                cout << "Завершение работы.\n";
                return;
            default:
                cout << "Некорректный ввод. Попробуйте снова.\n";
        }
    }
}

int main() {
    // Создание объекта кондиционера с конструктором по умолчанию
    AirConditioner ac;

    // Демонстрация работы программы через меню
    menu(ac);

    return 0;
}
