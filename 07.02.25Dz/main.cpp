#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <ctype.h>


void PrintApartment();
void DisplayInfo2();

void Entrance() {
    int choose = 0;

    std::cout << "Здравствуйте!";
    Sleep(2000);
    system("cls");
    std::cout << "Если вы хотите узнать данные о квартире, то напишите 1\n";
    std::cout << "Если вы хотите зайти в класс дроби, то напишите 2\n";
    std::cout << "Если выходите напишите 0: ";
    std::cin >> choose;
    system("cls");

    if (choose == 1) {
        PrintApartment();
    }
    else if (choose == 2) {
        DisplayInfo2();
    }
    else {
        std::cout << "Вы вышли из программы\n\n";
    }
}

void BackEntrance() {
    int choose = 0;
    std::cout << "Если вы хотите узнать данные о квартире, то напишите 1\n";
    std::cout << "Если вы хотите зайти в класс дроби, то напишите 2\n";
    std::cout << "Если выходите напишите 0: ";
    std::cin >> choose;
    system("cls");
    if (choose == 1) {
        PrintApartment();
    }
    else if (choose == 2) {
        DisplayInfo2();
    }
    else {
        std::cout << "Вы вышли из программы\n\n";
    }
}
class Human {
public:
    Human(const std::string& name) : name(name) {}

    std::string GetName() const {
        return name;
    }

private:
    std::string name;
};

class Apartment {
public:
    Apartment(const std::string& address, int square) : address(address), square(square) {}

    void GetHuman(const Human& human) {
        tenants.push_back(human);
    }

    void DisplayInfo() const {
        std::cout << "Адрес квартиры: " << address << "\n";
        std::cout << "Площадь квартиры: " << square << " м²" << "\n";
        std::cout << "Список жильцов:" << "\n";
        for (const auto& human : tenants) {
            std::cout << "- " << human.GetName() << "\n";
        }
        std::cout << "Коэффициент проживания: " << Cost_Of_Living_Coefficient() << "\n";
    }

    double Cost_Of_Living_Coefficient() const {
        return static_cast<double>(tenants.size()) / square;
    }

private:
    std::string address;
    int square;
    std::vector<Human> tenants;
};

void PrintApartment() {
    std::cout << "Загрузка данных...";
    Sleep(3000);
    system("cls");
    std::cout << "Загрузка списка жильцов квартиры...";
    Sleep(3000);
    system("cls");
    std::cout << "Подождите...";
    Sleep(2000);
    system("cls");

    Apartment apartment("Ул.Фурманова 57, г.Екатеринбург", 60);
    apartment.GetHuman(Human("Адольф Гитлер"));
    apartment.GetHuman(Human("Ленин"));
    apartment.DisplayInfo();
    std::cout << "\n\nЧтобы вернуться на главное меню нажмите люб клавишу: ";
    _getch();
    system("cls");
    BackEntrance();
}

int GCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {
            denominator = 1; 
        }
        Simplification();
    }

    void Enter() {
        std::cout << "Введите числитель: ";
        std::cin >> numerator;
        system("cls");
        std::cout << "Введите знаменатель: ";
        std::cin >> denominator;
        system("cls");
        while (true) {
            if (denominator != 0)
                break;
            std::cout << "Знаменатель не может быть 0. Пожалуйста, введите снова: ";
            system("cls");
        }

        Simplification();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void Show() const {
        std::cout << numerator << " / " << denominator << "\n";
    }

private:
    int numerator;
    int denominator;

    void Simplification() {
        int gcd = GCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
};

void DisplayInfo2() {
    Fraction fraction1, fraction2, result;

    std::cout << "Введите первую дробь: ";
    fraction1.Enter();

    std::cout << "Введите вторую дробь: ";
    fraction2.Enter();

    std::cout << "Сложение дробей: ";
    result = fraction1 + fraction2;
    result.Show();

    std::cout << "Вычитание дробей: ";
    result = fraction1 - fraction2;
    result.Show();

    std::cout << "Умножение дробей: ";
    result = fraction1 * fraction2;
    result.Show();

    std::cout << "Деление дробей: ";
    result = fraction1 / fraction2;
    result.Show();

    std::cout << "\n\nЧтобы вернуться на главное меню нажмите люб клавишу: ";
    _getch();
    system("cls");
    BackEntrance();

}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Entrance();
    return 0;
}