#include <iostream>

using namespace std;
struct synonyms;

struct dictionary{
    char* word;
    synonyms *synonyms = nullptr;
    dictionary *nxt = nullptr;
};

struct synonyms{
    char* synonym;
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
void arrange();

int main() {
    return 0;
}

void add_word(char* word_synonyms){
    char** array_w_s = synonym_separation(word_synonyms);
    int size = size_array(array_w_s);
    dictionary *temp_w;
    synonyms *temp_s;

    if (word_is_available(array_w_s[0])){
        temp_w = find_word(array_w_s[0]);
        temp_s = temp_w->synonyms;
        if (temp_s == nullptr){
            temp_s = new synonyms;
            temp_s->synonym = array_w_s[1];
            temp_s->nxt = nullptr;
            for (int i = 2; i < size; ++i) {
                temp_s->nxt = new synonyms;
                temp_s = temp_s->nxt;
                temp_s->synonym = array_w_s[i];
                temp_s->nxt = nullptr;
            }
        }else{
            while (temp_s != nullptr)
                temp_s = temp_s->nxt;
            temp_s = new synonyms;
            temp_s->synonym = array_w_s[1];
            temp_s->nxt = nullptr;
            for (int i = 2; i < size; ++i) {
                temp_s->nxt = new synonyms;
                temp_s = temp_s->nxt;
                temp_s->synonym = array_w_s[i];
                temp_s->nxt = nullptr;
            }
        }
    }else if (Head == nullptr){
        Head = new dictionary;
        Head->word = array_w_s[0];
        Head->synonyms = new synonyms;
        Head->synonyms->synonym = array_w_s[1];
        Head->synonyms->nxt = nullptr;
        temp_s = Head->synonyms;
        for (int i = 2; i < size; ++i) {
            temp_s->nxt = new synonyms;
            temp_s = temp_s->nxt;
            temp_s->synonym = array_w_s[i];
            temp_s->nxt = nullptr;
        }
        Head->nxt = nullptr;
    }else {
        temp_w = Head;
        while (temp_w != nullptr)
            temp_w = temp_w->nxt;
        temp_w = new dictionary;
        temp_w->word = array_w_s[0];
        temp_s = temp_w->synonyms;
        temp_s = new synonyms;
        temp_s->synonym = array_w_s[1];
        temp_s->nxt = nullptr;
        for (int i = 2; i < size; ++i) {
            temp_s->nxt = new synonyms;
            temp_s = temp_s->nxt;
            temp_s->synonym = array_w_s[i];
            temp_s->nxt = nullptr;
        }
        temp_w->nxt = nullptr;
    }
}

void delete_word(char* word){
    if (word_is_available(word)){
        dictionary *temp_w1 = find_word(word), *temp_w2;
        synonyms *temp_s1 = temp_w1->synonyms, *temp_s2;
        while (temp_s1 != nullptr){
            temp_s2 = temp_s1->nxt;
            delete temp_s1;
            temp_s1 = temp_s2;
        }
        temp_w2 = Head;
        while (temp_w2->nxt == temp_w1)
            temp_w2 = temp_w2->nxt;
        temp_w2->nxt = temp_w1->nxt;
        delete temp_w1;
    }else
        cout << "The word is not available" << endl;
}

void delete_synonym(char* word_synonym){
    char** w_s = synonym_separation(word_synonym);
    char* word = w_s[0];
    char* synonym = w_s[1];
    dictionary *temp_w1;
    synonyms *temp_s1, *temp_s2;
    if (word_is_available(word)){
        temp_w1 = find_word(word);
        temp_s1 = temp_w1->synonyms;
        if (temp_s1->synonym == synonym){
            temp_s2 = temp_s1;
            temp_s1 = temp_s1->nxt;
            delete temp_s2;
            if (temp_s1 == nullptr)
                delete_word(temp_w1->word);
        }else {
            while (temp_s1->nxt->synonym != synonym)
                temp_s1 = temp_s1->nxt;
            temp_s2 = temp_s1->nxt;
            temp_s1->nxt = temp_s2->nxt;
            delete temp_s2;
        }
    }else
        cout << "The word is not available" << endl;
}

void show_word(char* word){
    dictionary *temp_w = find_word(word);
    synonyms *temp_s = temp_w->synonyms;
    cout << temp_w->word << ": ";
    while (temp_s != nullptr){
        cout << temp_s->synonym << ", ";
        temp_s = temp_s->nxt;
    }
}

void show_words(){
    dictionary *temp_w = Head;
    synonyms *temp_s = temp_w->synonyms;
    while (temp_w != nullptr){
        cout << temp_w->word << ": ";
        while (temp_s != nullptr){
            cout << temp_s->synonym << ", ";
            temp_s = temp_s->nxt;
        }
        cout << endl;
        temp_w = temp_w->nxt;
    }
}