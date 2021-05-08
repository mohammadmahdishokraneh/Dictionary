#include <iostream>

using namespace std;

struct dictionary{
    string word;
    dictionary* nxt;
    struct synonyms;
};

struct synonyms {
    string synonym;
    synonyms *nxt;
};

void add_word(string ,string);
void delete_word(string);
void delete_synonym(string);
void show_word(string);
void show_words();
void change_spelling_of_word(string ,string);
void words_storage();
void read_words(files name);

int main() {

    return 0;
}

