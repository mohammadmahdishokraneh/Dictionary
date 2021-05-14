#include <iostream>

using namespace std;

struct synonyms;

struct dictionary{
    string word;
    synonyms *synonyms = nullptr;
    dictionary *nxt = nullptr;
};

struct synonyms{
    string synonym;
    synonyms *nxt = nullptr;
};

dictionary *Head = nullptr;

void add_word(char*);
void delete_word(char*);
void delete_synonym(char*);
void show_word(char*);
void show_words();
void change_spelling_of_word(char* ,char*);
void words_storage();
// void read_words(files name);
bool word_is_available(char*);
dictionary *find_word(char*);
char** synonym_separation(char*);
int size_array(char**);

int main() {
    return 0;
}

void add_word(char* word_synonyms){
    char** array_w_s = synonym_separation(word_synonyms);
    int size = size_array(array_w_s);
    dictionary *temp;

    if (word_is_available(array_w_s[0])){
        temp = find_word(array_w_s[0]);
        if (temp->synonyms == nullptr){
            temp->synonyms = new synonyms;
            temp->synonyms->synonym = array_w_s[1];
            temp->synonyms->nxt = nullptr;
            for (int i = 2; i < size; ++i) {
                temp->synonyms->nxt = new synonyms;
                temp->synonyms = temp->synonyms->nxt;
                temp->synonyms->synonym = array_w_s[i];
                temp->synonyms->nxt = nullptr;
            }
        }else{
            while (temp->synonyms != nullptr)
                temp->synonyms = temp->synonyms->nxt;
            temp->synonyms = new synonyms;
            temp->synonyms->synonym = array_w_s[1];
            temp->synonyms->nxt = nullptr;
            for (int i = 2; i < size; ++i) {
                temp->synonyms->nxt = new synonyms;
                temp->synonyms = temp->synonyms->nxt;
                temp->synonyms->synonym = array_w_s[i];
                temp->synonyms->nxt = nullptr;
            }
        }
    }else if (Head == nullptr){
        Head = new dictionary;
        Head->word = array_w_s[0];
        Head->synonyms = new synonyms;
        Head->synonyms->synonym = array_w_s[1];
        Head->synonyms->nxt = nullptr;
        for (int i = 2; i < size; ++i) {
            Head->synonyms->nxt = new synonyms;
            Head->synonyms = Head->synonyms->nxt;
            Head->synonyms->synonym = array_w_s[i];
            Head->synonyms->nxt = nullptr;
        }
        Head->nxt = nullptr;
    }else {
        temp = Head;
        while (temp != nullptr)
            temp = temp->nxt;
        temp = new dictionary;
        temp->word = array_w_s[0];
        temp->synonyms = new synonyms;
        temp->synonyms->synonym = array_w_s[1];
        temp->synonyms->nxt = nullptr;
        for (int i = 2; i < size; ++i) {
            temp->synonyms->nxt = new synonyms;
            temp->synonyms = temp->synonyms->nxt;
            temp->synonyms->synonym = array_w_s[i];
            temp->synonyms->nxt = nullptr;
        }
        temp->nxt = nullptr;
    }
}