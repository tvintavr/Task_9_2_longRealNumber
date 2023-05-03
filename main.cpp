#include <iostream>
#include <cmath>
#include <windows.h>
#include <limits>
#include <numeric>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    /* Проверка ввода данных (справочно)
    while(true)
    {
        float value; // попробуйте разные типы данных
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n')
        {
            std::cerr << "Ошибка ввода данных\n";

            // Данные две строки необходимы для очистки буфера ввода, без них, при последующем вводе данных, произойдёт зацикливание:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Если нужно прервать программу:
            // return 1; // выход из функции main, соответственно и из программы
            // exit(1); // а так можно выйти из программы в любом месте
            // цифры - это номера ошибок передаваемые программой в ОС,
            // 0 - всё хорошо, не 0 - какой-то код, который разработчик устанавливает сам...
        }
        else
            std::cout << value << '\n';
    }

    return 0;
     */
    std::string number;
    int numLength;
    int i;
    int pointCount;
    int pointPos;

    bool rightNumber=true;

    while (true) {
        std::cout << "Enter number: ";
        std::cin>>number;
        pointCount=0;
        pointPos=-1;

            //Check data entry
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Error\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //Check data entry


        } else {
            numLength=number.length();
            std::cout<<numLength;

                //points number check
            for (i=0;i<numLength;i++) {
                if (number[i]=='.') {
                    pointCount++;
                    pointPos=i;
                }
            }
            if (pointCount>1) {
                std::cout << "Too many points!\n";
                //points number check

            } else {
                for (i=(number[0]=='-'? 1 : 0);(i<numLength) && rightNumber;i++) {
                    if (number[i]=='.') {
                        i++;
                    }
                    if (number[i] < '0' || number[i] > '9') {
                        rightNumber = false;
                    }

                }
                std::cout<<(rightNumber? "Right number\n" : "Wrong Number!\n");
            }
        }
    }
}