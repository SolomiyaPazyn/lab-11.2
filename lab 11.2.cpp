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
        // ���������� �������� ��������� �����
        size_t nested_start = s.find('(', start + 1);
        if (nested_start != string::npos && nested_start < finish)
        {
            // ������ ������� ���������� �����
            size_t outer_finish = finish;
            while (true)
            {
                size_t next_finish = s.find(')', outer_finish + 1);
                if (next_finish == string::npos) break;
                outer_finish = next_finish;
            }
            // ��������� ��� �� �������� ������� ������� � �������
            s.erase(start, outer_finish - start + 1);
        }
        else
        {
            // ��������� ���� �� ������� ����� � �������
            s.erase(start, finish - start + 1);
        }
    }
    return s;
}

int main()
{
    // ³�������� ������� ���� t1
    ifstream input_file("t1.txt");
    if (!input_file) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    // ³�������� �������� ���� t2
    ofstream output_file("t2.txt");
    if (!output_file) {
        cerr << "Error creating output file" << endl;
        return 1;
    }

    // ������� ����� � �������� �����
    string line;
    while (getline(input_file, line)) {
        // ���������� ����� �������� ProcessBrackets
        string processed_line = ProcessBrackets(line);

        // �������� ���������� ����� � �������� ����
        output_file << processed_line << endl;
    }

    // ��������� �����
    input_file.close();
    output_file.close();

    cout << "File processed successfully" << endl;
    return 0;
}
