#include "Dictionary.h"

int main() {
    Trie dictionary;
    dictionary.insert("apple");
    dictionary.insert("app");
    dictionary.insert("apricot");
    dictionary.insert("banana");
    dictionary.insert("bat");
    dictionary.insert("batman");

    while (true) {
        cout << "������� ����� ����� (��� Enter ��� ������): ";
        string prefix;
        getline(cin, prefix);

        if (prefix.empty()) {
            break;
        }

        vector<string> suggestions = dictionary.findWordsWithPrefix(prefix);
        if (!suggestions.empty()) {
            cout << "���������� �������� ����: ";
            for (const string& word : suggestions) {
                cout << word << " ";
            }
            cout << endl;
        }
        else {
            cout << "��� ���������� ���������." << endl;
        }
    }

    return 0;
}