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
        cout << "Введите часть слова (или Enter для выхода): ";
        string prefix;
        getline(cin, prefix);

        if (prefix.empty()) {
            break;
        }

        vector<string> suggestions = dictionary.findWordsWithPrefix(prefix);
        if (!suggestions.empty()) {
            cout << "Подходящие варианты слов: ";
            for (const string& word : suggestions) {
                cout << word << " ";
            }
            cout << endl;
        }
        else {
            cout << "Нет подходящих вариантов." << endl;
        }
    }

    return 0;
}