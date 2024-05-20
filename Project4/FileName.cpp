#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string>
#include <fstream>
#include <conio.h>
#include <clocale>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include<vector>

using namespace std;

const int NotUsed = system("color 07");

string element_menu[5] = { "Об авторе", "Справочник", "Обучающая программа","Заставка", "Выход" };
string element_dictionary[4] = { "Весь список", "Поиск", "Добавление в справочник", "Выход" };
string element_translation[5] = { "Весь список", "Поиск", "Добавление в справочник", "Проверка знаний", "Выход в главное меню" };
string element_search[6] = { "Поиск по книге", "Поиск по жанру", "Поиск по дате прочтения", "Поиск по аннотации", "Поиск по автору", "Выход" };
string element_search_translation[5] = { "Поиск по слову", "Поиск по переводу", "Поиск по структуре", "Поиск по примеру", "Выход" };
string element_author[4] = { "Файфер Антон", "Группа ИВТ-233", "Нажмите любую кнопку для выхода в МЕНЮ", "Нажмите Esc для выхода" };

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
HWND hwnd = GetConsoleWindow();
HDC dc = GetDC(hwnd);
RECT window = {};
HBRUSH brush;
HPEN hPen;

void Animation()
{//луна
    system("cls");
    HDC hdc = GetDC(GetConsoleWindow());
    double R = 55, x = 900, y = 9;
    HPEN pen1 = CreatePen(PS_SOLID, 2, RGB(100, 100, 100));
    HBRUSH brush1 = CreateSolidBrush(RGB(100, 100, 100));
    SelectObject(hdc, brush1);
    SelectObject(hdc, pen1);
    Ellipse(hdc, x, y, x + R, y + R);
    DeleteObject(pen1);
    DeleteObject(brush1);
    //дома
    double x1 = 100, y1 = 270, x2 = 200, y2 = 500, x3 = 110, x4 = 135, y3 = 320, y4 = 365;//x6=500;
    for (int i = 0; i < 790; i += 200)
    {
        HPEN pen2 = CreatePen(PS_SOLID, 2, RGB(218, 164, 32));
        HBRUSH brush2 = CreateSolidBrush(RGB(218, 164, 32));
        SelectObject(hdc, brush2);
        SelectObject(hdc, pen2);
        Rectangle(hdc, x1, y1, x2, y2);
        Rectangle(hdc, x1 + i, y1, x2 + i, y2);
        //Rectangle(hdc, x3, y1, x6, y2);
        //Rectangle(hdc, x4, y1, x7, y2);

        DeleteObject(pen2);
        DeleteObject(brush2);
    }
    //окна
    for (int i = 0; i < 790; i += 200)
    {
        for (int j = 0; j < 200; j += 100)
        {
            double x5 = 160, x6 = 185;
            HPEN pen3 = CreatePen(PS_SOLID, 2, RGB(255, 255, 255));
            HBRUSH brush3 = CreateSolidBrush(RGB(255, 255, 255));
            SelectObject(hdc, brush3);
            SelectObject(hdc, pen3);
            Rectangle(hdc, x3 + i, y3 + j, x4 + i, y4 + j);
            Rectangle(hdc, x5 + i, y3 + j, x6 + i, y4 + j);

            DeleteObject(pen3);
            DeleteObject(brush3);
        }
    }
    //метеориты и их падение

/*след падения метеоритов  */


    const int cometCount = 3; // количество комет
    vector<double> cometX(cometCount);
    vector<double> cometY(cometCount);
    vector<double> cometSpeedX(cometCount);
    vector<double> cometSpeedY(cometCount);

    // Инициализация начальных координат и скоростей для каждой кометы
    for (int i = 0; i < cometCount; i++) {
        cometX[i] = rand() % 700 + 100;
        cometY[i] = rand() % 50 + 10;
        cometSpeedX[i] = static_cast<double>(rand() % 3 + 1); // случайная скорость по оси X
        cometSpeedY[i] = static_cast<double>(rand() % 2 + 1); // случайная скорость по оси Y
    }

    for (int i = 0; i < 700; i += 1) {
        for (int j = 0; j < cometCount; j++) {
            HPEN pen5 = CreatePen(PS_SOLID, 1, RGB(168, 167, 145));
            HBRUSH brush4 = CreateSolidBrush(RGB(189, 184, 87));
            SelectObject(hdc, brush4);
            SelectObject(hdc, pen5);

            // Рисуем комету
            Ellipse(hdc, static_cast<int>(cometX[j]), static_cast<int>(cometY[j]), static_cast<int>(cometX[j] + 14), static_cast<int>(cometY[j] + 14));

            // Рисуем след за кометой
            MoveToEx(hdc, static_cast<int>(cometX[j]), static_cast<int>(cometY[j]), NULL);
            LineTo(hdc, static_cast<int>(cometX[j]), static_cast<int>(cometY[j]));

            // Двигаем комету
            cometX[j] += cometSpeedX[j];
            cometY[j] += cometSpeedY[j];

            DeleteObject(brush4);
            DeleteObject(pen5);

            Sleep(3); // Задержка между кадрами
        }
    }



}
void Author()
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n";
    for (int i = 0; i < 4; i++)
    {
        cout << "\t\t\t\t\t" << element_author[i] << endl << endl;
    }
    char c = _getch();
    if (c == 27) exit(0);
}

void menu(int pos, int n, int element)
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

    for (int i = 0; i < n; i++)
    {
        SetConsoleTextAttribute(hConsole, 6);
        if (i == pos)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << "\t\t\t\t\t\t" << " --> ";
        }
        else
            cout << "\t\t\t\t\t\t" << " ";
        if (element == 0)cout << element_menu[i] << endl;
        if (element == 1)cout << element_dictionary[i] << endl;
        if (element == 2)cout << element_search[i] << endl;
    }
}

void menuTranslation(int pos, int n, int element)
{
    setlocale(LC_ALL, "Rus");
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";

    for (int i = 0; i < n; i++)
    {
        SetConsoleTextAttribute(hConsole, 6);
        if (i == pos)
        {
            SetConsoleTextAttribute(hConsole, 14);
            cout << "\t\t\t\t\t\t" << " --> ";
        }
        else
            cout << "\t\t\t\t\t\t" << " ";
        if (element == 0) cout << element_menu[i] << endl;
        if (element == 1) cout << element_translation[i] << endl;
        if (element == 2) cout << element_search_translation[i] << endl;
    }
}

struct TranslationOfC
{
    string word, translation, Structure, Example, Knowledge;
};

struct dictionary
{
    string book, genre, DateOfReading, Author, aboutWhat;
};

string ToLower(string s) {
    setlocale(LC_ALL, "Russian");
    string str;
    transform(s.begin(), s.end(), s.begin(), tolower);
    return s;
}

void all_dict(dictionary arrey[], int a)
{
    for (int i = 0; i < a; i++)
    {
        cout << "________________________________________________________" << endl;
        cout << "                |" << endl;
        cout << " Книга:         | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].book << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Жанр:          | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].genre << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Дата прочтения:| ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].DateOfReading << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Автор:         | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].Author << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|---------------------------------------------------------------" << endl;
        cout << " О чем:         | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].aboutWhat << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "________________|____________________________________" << endl;
        cout << "///////////////////////////////////////////////////////////////////////////////////" << endl;
    }
}

int search(string str1, int i, dictionary arrey[], int pos, int er) //поиск в названии
{
    string str, str2;
    const char SEP = ' ';
    int c = 0;
    if (pos == 0)
    {
        str = ToLower(arrey[i].book);
    }
    if (pos == 1)
    {
        str = ToLower(arrey[i].genre);
    }
    if (pos == 2)
    {
        str = ToLower(arrey[i].DateOfReading);
    }
    if (pos == 3)
    {
        str = ToLower(arrey[i].Author);
    }
    if (pos == 4)
    {
        str = ToLower(arrey[i].aboutWhat);
    }
    str1 = ToLower(str1);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') { str.erase(i, 1); }
    }
    istringstream ist(str);//превращаем строку в поток
    while (getline(ist, str2, SEP))
    {
        if (str2 == str1)
        {
            SetConsoleTextAttribute(hConsole, 7);
            cout << "_________________________________________________" << endl;
            cout << "                |" << endl;
            cout << " Книга:         | ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << arrey[i].book << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "----------------|---------------------------------------------------------" << endl;
            cout << " Жанр:          | ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << arrey[i].genre << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "----------------|---------------------------------------------------------" << endl;
            cout << " Дата прочтения:| ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << arrey[i].DateOfReading << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "----------------|----------------------------------------------------" << endl;
            cout << " Автор:         | ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << arrey[i].Author << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "----------------|-------------------------------------------------------" << endl;
            cout << " О чем:         | ";
            SetConsoleTextAttribute(hConsole, 11);
            cout << arrey[i].aboutWhat << endl;
            SetConsoleTextAttribute(hConsole, 7);
            cout << "________________|______________________________" << endl;
            cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
            er = 1;
        }
    }
    return er;
}

void add_word()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path1 = "book.txt";
    fstream fs1;
    char my_str[255];
    fs1.open(path1, ios_base::out | ios_base::app);
    if (!fs1.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        printf("Введите название книги: ");
        cin.getline(my_str, 255);
        fs1 << my_str << endl;
        printf("Введите жанр: ");
        cin.getline(my_str, 255);
        fs1 << my_str << endl;
        printf("Введите дату прочтения: ");
        cin.getline(my_str, 255);
        fs1 << my_str << endl;
        printf("Введите автора: ");
        cin.getline(my_str, 255);
        fs1 << my_str << endl;

        printf("Напишите о чем книга: ");
        cin.getline(my_str, 255);
        fs1 << my_str << endl;
    }
    fs1.close();
}

void full_dictionary(int pos)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    setlocale(LC_ALL, "Russian");
    dictionary arrey[20];
    string path1 = "book.txt";
    string my_word;
    int a = 0, j = 1;
    fstream fs1;
    int er = 0;
    fs1.open(path1, fstream::in | fstream::out | fstream::app);
    if (!fs1.is_open())
    {
        cout << "Ошибка открытия файла!" << endl;
    }
    else
    {
        string str;
        while (!fs1.eof())
        {
            str = "";
            getline(fs1, str);
            if (j % 5 == 1) arrey[a].book = str;
            if (j % 5 == 2) arrey[a].genre = str;
            if (j % 5 == 3) arrey[a].DateOfReading = str;
            if (j % 5 == 4) arrey[a].Author = str;
            if (j % 5 == 0) arrey[a].aboutWhat = str;
            if (j % 5 == 0) a++;
            j++;
        }
        fs1.close();
    }

    string str1;
    if (pos == 5) all_dict(arrey, a);
    else
    {
        int er = 0;
        printf("Поиск по слову: ");
        cin >> str1;
        cout << endl;
        for (int i = 0; i < a; i++)
        {
            if (pos == 0) er = search(str1, i, arrey, pos, er);
            if (pos == 1) er = search(str1, i, arrey, pos, er);
            if (pos == 2) er = search(str1, i, arrey, pos, er);
            if (pos == 3) er = search(str1, i, arrey, pos, er);
            if (pos == 4) er = search(str1, i, arrey, pos, er);
        }
        SetConsoleTextAttribute(hConsole, 7);
        if (er == 0) cout << "Ошибка поиска. Попробуйте еще раз." << endl << endl;
    }
    SetConsoleTextAttribute(hConsole, 6);
    system("pause");
}

void menu_search()
{
    setlocale(LC_ALL, "Russian");
    int pos = 1;
    while (true)
    {
        menu(pos, 6, 2);
        char c = _getch();
        if (c == 'w' || c == 72 && pos > 0) pos--;
        if (c == 's' || c == 80 && pos < 5) pos++;
        if (c == 13)
        {
            if (pos == 0) full_dictionary(pos);
            if (pos == 1) full_dictionary(pos);
            if (pos == 2) full_dictionary(pos);
            if (pos == 3) full_dictionary(pos);
            if (pos == 4) full_dictionary(pos);
            if (pos == 5) break;
        }
        if (c == 27) exit(0);
    }
}

int menu_dict()
{
    setlocale(LC_ALL, "Russian");
    int pos = 1;
    while (true)
    {
        menu(pos, 4, 1);
        char c = _getch();
        if (c == 'w' || c == 72 && pos > 0) pos--;
        if (c == 's' || c == 80 && pos < 3) pos++;
        if (c == 13)
        {
            if (pos == 0) full_dictionary(5);
            if (pos == 1) menu_search();
            if (pos == 2) add_word();
            if (pos == 3)break;
        }
        if (c == 27) exit(0);
    }
}

void all_translation(TranslationOfC arrey[], int a)
{
    for (int i = 0; i < a; i++)
    {
        cout << "________________________________________________________" << endl;
        cout << "                |" << endl;
        cout << " Слово:         | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].word << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Перевод:       | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].translation << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Стуктура:      | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].Structure << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|--------------------------------------------------------------------" << endl;
        cout << " Пример:        | ";
        SetConsoleTextAttribute(hConsole, 11);
        cout << arrey[i].Example << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "----------------|---------------------------------------------------------------" << endl;
        SetConsoleTextAttribute(hConsole, 7);
        cout << "________________|____________________________________" << endl;
        cout << "///////////////////////////////////////////////////////////////////////////////////" << endl;
    }
}

int search_translation(string str1, TranslationOfC arrey[], int pos, int er, int arraySize)
{
    string str, str2;
    const char SEP = ' ';
    str1 = ToLower(str1);
    istringstream ist;

    for (int i = 0; i < arraySize; ++i)
    {
        switch (pos)
        {
        case 0: str = ToLower(arrey[i].word); break;
        case 1: str = ToLower(arrey[i].translation); break;
        case 2: str = ToLower(arrey[i].Structure); break;
        case 3: str = ToLower(arrey[i].Example); break;
        case 4: str = ToLower(arrey[i].Knowledge); break;
        default: return er;
        }

        str.erase(remove(str.begin(), str.end(), ','), str.end());
        ist.clear();
        ist.str(str);

        while (getline(ist, str2, SEP))
        {
            if (str2 == str1)
            {
                SetConsoleTextAttribute(hConsole, 7);
                cout << "_________________________________________________" << endl;
                cout << "                |" << endl;
                cout << " Слово:         | ";
                SetConsoleTextAttribute(hConsole, 11);
                cout << arrey[i].word << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "----------------|---------------------------------------------------------" << endl;
                cout << " Перевод:       | ";
                SetConsoleTextAttribute(hConsole, 11);
                cout << arrey[i].translation << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "----------------|---------------------------------------------------------" << endl;
                cout << " Структура:     | ";
                SetConsoleTextAttribute(hConsole, 11);
                cout << arrey[i].Structure << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "----------------|----------------------------------------------------" << endl;
                cout << " Пример:        | ";
                SetConsoleTextAttribute(hConsole, 11);
                cout << arrey[i].Example << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "----------------|-------------------------------------------------------" << endl;
                SetConsoleTextAttribute(hConsole, 7);
                cout << "________________|______________________________" << endl;
                cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
                er = 1;
                break;
            }
        }
    }
    return er;
}

void add_word_translation()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string path1 = "translation.txt";
    fstream fs1;
    char my_str[255];

    fs1.open(path1, ios_base::out | ios_base::app);
    if (!fs1.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    printf("Введите слово: ");
    cin.getline(my_str, 255);
    fs1 << my_str << endl;

    printf("Введите перевод: ");
    cin.getline(my_str, 255);
    fs1 << my_str << endl;

    printf("Введите структуру: ");
    cin.getline(my_str, 255);
    fs1 << my_str << endl;

    printf("Введите пример: ");
    cin.getline(my_str, 255);
    fs1 << my_str << endl;

 

    fs1.close();
}

void full_translation(int pos)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls");
    setlocale(LC_ALL, "Russian");

    TranslationOfC arrey[20];
    string path1 = "translation.txt";
    int a = 0, j = 1;
    fstream fs1;

        fs1.open(path1, fstream::in | fstream::out | fstream::app);
    if (!fs1.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return;
    }

    string str;
    while (getline(fs1, str)) {
        if (j % 5 == 1) arrey[a].word = str;
        if (j % 5 == 2) arrey[a].translation = str;
        if (j % 5 == 3) arrey[a].Structure = str;
        if (j % 5 == 4) arrey[a].Example = str;
        if (j % 5 == 0) arrey[a].Knowledge = str;

        if (j % 5 == 0) a++;
        j++;
    }
    fs1.close();

    string str1;
    if (pos == 5) all_translation(arrey, a);
    else {
        int er = 0;
        printf("Поиск по слову: ");
        cin >> str1;
        cout << endl;

        er = search_translation(str1, arrey, pos, er, a);
        SetConsoleTextAttribute(hConsole, 7);
        if (er == 0) cout << "Ошибка поиска. Попробуйте еще раз." << endl << endl;
    }
    SetConsoleTextAttribute(hConsole, 6);
    system("pause");
}

void menu_searchTranslation()
{
    setlocale(LC_ALL, "Russian");
    int pos = 0;
    while (true) {
        menuTranslation(pos, 5, 2); // Используем menuTranslation() для отображения меню
        char c = _getch();
        if (c == 'w' || (c == 72 && pos > 0)) pos--;
        if (c == 's' || (c == 80 && pos < 4)) pos++;
        if (c == 13) {
            if (pos == 0) full_translation(0);
            if (pos == 1) full_translation(1);
            if (pos == 2) full_translation(2);
            if (pos == 3) full_translation(3);
            if (pos == 4) break;
        }
        if (c == 27) exit(0);
    }
}

int menu_dict_translation()
{
    setlocale(LC_ALL, "Russian");
    int pos = 0;
    while (true) {
        menu(pos, 4, 1);
        char c = _getch();
        if (c == 'w' || (c == 72 && pos > 0)) pos--;
        if (c == 's' || (c == 80 && pos < 3)) pos++;
        if (c == 13) {
            if (pos == 0) full_translation(5);
            if (pos == 1) menu_searchTranslation();
            if (pos == 2) add_word_translation();
            if (pos == 3) break;
        }
        if (c == 27) exit(0);
    }
    return 0;
}

void knowledge_check()
{
    setlocale(LC_ALL, "Russian");
    system("cls");

    string questions[6] = {
        "Вопрос 1: Для чего чаще всего используют язык С++",
        "Вопрос 2: Как переводится 'if'",
        "Вопрос 3: Как переводится 'but'",
        "Вопрос 4: Какая структура у 'if'?",
        "Вопрос 5: Какая можно использовать цикл 'for' ?",
        "Вопрос 6: Какая структура у 'while'?"
    };

    string answers[6];

    // Получаем размеры окна консоли
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    for (int i = 0; i < 6; i++)
    {
        // Вычисляем позицию для центрирования текста
        int questionLen = questions[i].length();
        int startX = (consoleWidth - questionLen) / 2;
        int startY = consoleHeight / 3 + i; // Смещение по вертикали

        // Устанавливаем курсор в центр экрана
        COORD coord = { startX, startY };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

        cout << questions[i] << endl;
        getline(cin, answers[i]);

        if (answers[i] == "Для операционных систем" && answers[i] == "если" && answers[i] == "но" && answers[i] == "if(){}else{}" && answers[i] == "for(int i=0;i<1;i++){}" && answers[i] == "while(){}") {
            cout << "Все ответы верны!" << endl;
        }
    }

    cout << "Спасибо за ответы! Нажмите любую кнопку для возврата в меню." << endl;
    _getch();
}

void menu_boss(int pos)
{
    while (true)
    {
        menu(pos, 5, 0); // Увеличено количество элементов в главном меню до 5
        char c = _getch();
        if (c == 'w' || c == 72 && pos > 0) pos--;
        if (c == 's' || c == 80 && pos < 4) pos++; // Изменен верхний предел для pos
        if (c == 13)
        {
            if (pos == 0) Author();
            if (pos == 1) menu_dict();
            if (pos == 2) {
                int sub_pos = 0;
                while (true) {
                    menuTranslation(sub_pos, 5, 1);
                    c = _getch();
                    if (c == 'w' || (c == 72 && sub_pos > 0)) sub_pos--;
                    if (c == 's' || (c == 80 && sub_pos < 4)) sub_pos++;
                    if (c == 13) {
                        if (sub_pos == 0) full_translation(5);
                        if (sub_pos == 1) menu_searchTranslation();
                        if (sub_pos == 2) add_word_translation();
                        if (sub_pos == 3) knowledge_check();
                        if (sub_pos == 4) break;
                    }
                    if (c == 27) exit(0);
                }
            }
            if (pos == 3) Animation(); // Добавлена заставка
            if (pos == 4) exit(0);
        }
        if (c == 27) exit(0);
    }
}

int main()
{
    int x1 = 0, y1 = 0, x2 = 200, y2 = 200;
    int dx = 350, dy = 150;

    x1 += dx;
    y1 += dy;
    x2 += dx;
    y2 += dy;
    int pace = 0;
    int stepY = (y2 - y1) / 4;

    menu_boss(1);
    ReleaseDC(hwnd, dc);
    std::cin.get();
    return 0;
}