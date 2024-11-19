#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string ProcessBrackets(string s)
{
    size_t start = 0,
        finish;
    while ((start = s.find('(', start)) != string::npos)
    {
        finish = s.find(')', start + 1);
        if (finish == string::npos)
        {
            start++;
            continue;
        }
        // перевіряємо наявність вкладених дужок
        size_t nested_start = s.find('(', start + 1);
        if (nested_start != string::npos && nested_start < finish)
        {
            // шукаємо останню закриваючу дужку
            size_t outer_finish = finish;
            while (true)
            {
                size_t next_finish = s.find(')', outer_finish + 1);
                if (next_finish == string::npos) break;
                outer_finish = next_finish;
            }
            // видаляємо все між зовнішніми дужками включно з дужками
            s.erase(start, outer_finish - start + 1);
        }
        else
        {
            // видаляємо вміст між дужками разом з дужками
            s.erase(start, finish - start + 1);
        }
    }
    return s;
}

int main()
{
    // Відкриваємо вхідний файл t1
    ifstream input_file("t1.txt");
    if (!input_file) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    // Відкриваємо вихідний файл t2
    ofstream output_file("t2.txt");
    if (!output_file) {
        cerr << "Error creating output file" << endl;
        return 1;
    }

    // Зчитуємо рядок з вхідного файлу
    string line;
    while (getline(input_file, line)) {
        // Обробляємо рядок функцією ProcessBrackets
        string processed_line = ProcessBrackets(line);

        // Записуємо оброблений рядок у вихідний файл
        output_file << processed_line << endl;
    }

    // Закриваємо файли
    input_file.close();
    output_file.close();

    cout << "File processed successfully" << endl;
    return 0;
}
