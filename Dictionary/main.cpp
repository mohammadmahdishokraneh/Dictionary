#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct synonyms{
    char* synonym = nullptr;
    synonyms *nxt = nullptr;
};

struct dictionary{
    char* word = nullptr;
    synonyms *synonyms = nullptr;
    dictionary *nxt = nullptr;
};

dictionary *Head = nullptr;

bool word_is_available(const char*);
dictionary *find_word(const char*);
void arrange();
void add_word(char*, char*);
void delete_word(char*);
void delete_synonym(char*, const char*);
void show_word(char*);
void show_words();
void change_spelling_of_word(char* ,char*);
void words_storage();
void read_words();

int main() {
    cout << "Welcome to the dictionary" << endl;
    for (int i = 0; i > -1; ++i) {
        cout << "---------------------" << endl;
        cout << "Enter 1 to add the word and synonyms" << endl;
        cout << "Enter 2 to delete the word" << endl;
        cout << "Enter 3 to delete the synonym" << endl;
        cout << "Enter 4 to show the word and synonyms" << endl;
        cout << "Enter 5 to show the dictionary" << endl;
        cout << "Enter 6 to change the word" << endl;
        cout << "Enter 7 to save the words and synonyms" << endl;
        cout << "Enter 8 to load the words and synonyms" << endl;
        cout << "Enter 0 to exit" << endl;
        cout << "---------------------" << endl;
        cout << "choose: ";
        int condition, size;
        char *word, *synonym, *wrong_word;
        cin >> condition;
        switch (condition) {
            case 1: {
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the number of synonyms: ";
                cin >> size;
                for (int j = 0; j < size; ++j) {
                    cout << "Enter the synonym: ";
                    cin >> synonym;
                    add_word(word, synonym);
                    arrange();
                }
                break;
            }
            case 2: {
                cout << "Enter the word: ";
                cin >> word;
                delete_word(word);
                break;
            }
            case 3: {
                cout << "Enter the word: ";
                cin >> word;
                cout << "Enter the synonym: ";
                cin >> synonym;
                delete_synonym(word, synonym);
                break;
            }
            case 4: {
                cout << "Enter the word: ";
                cin >> word;
                show_word(word);
                break;
            }
            case 5: {
                show_words();
                break;
            }
            case 6: {
                cout << "Enter the wrong word: ";
                cin >> wrong_word;
                cout << "Enter the correct word: ";
                cin >> word;
                change_spelling_of_word(wrong_word, word);
                arrange();
                break;
            }
            case 7: {
                words_storage();
                break;
            }
            case 8: {
                read_words();
                break;
            }
            case 0: {
                cout << "Do save information? y/n" << endl;
                char condition1;
                cin >> condition1;
                if (condition1 == 'y')
                    words_storage();
                break;
            }
            default:
                break;
        }
        if (condition == 0)
            break;
    }
    return 0;
}

bool word_is_available(const char* word){
    dictionary *temp = Head;
    while (temp != nullptr){
        if (strcmp(temp->word, word) == 0){
            return true;
        }
        temp = temp->nxt;
    }
    return false;
}

dictionary *find_word(const char* word){
    dictionary *temp = Head;
    while (temp != nullptr){
        if (strcmp(temp->word, word) == 0){
            return temp;
        }
        temp = temp->nxt;
    }
    return nullptr;
}

void arrange(){
    dictionary *temp_w1, *before = Head, *temp_w2 = Head;
    if(Head->nxt != nullptr && Head != nullptr){
        while (temp_w2 != nullptr){
            if (strcmp(Head->word, Head->nxt->word) > 0 ){
                Head = Head->nxt;
                temp_w1 = Head->nxt;
                Head->nxt = before;
                before->nxt = temp_w1;
            }
            before = Head;
            temp_w1 = before->nxt;
            while (temp_w1 != nullptr){
                if (strcmp(temp_w1->word, temp_w1->nxt->word) > 0){
                    before = temp_w1->nxt;
                    before->nxt = temp_w1;
                    temp_w1->nxt = temp_w1->nxt->nxt;
                }
                before = temp_w1;
                temp_w1 = temp_w1->nxt;
            }
            temp_w2 = temp_w2->nxt;
        }
        temp_w2 = Head;
        synonyms *temp_s1, *before_s, *temp_s2;
        while (temp_w2 != nullptr){
            before_s = temp_w2->synonyms;
            temp_s2 = temp_w2->synonyms;
            while (temp_s2 != nullptr){
                if (strcmp(temp_w2->synonyms->synonym, temp_w2->synonyms->nxt->synonym) > 0 ){
                    temp_w2->synonyms = temp_w2->synonyms->nxt;
                    temp_s1 = temp_w2->synonyms->nxt;
                    temp_w2->synonyms->nxt = before_s;
                    before_s->nxt = temp_s1;
                }
                before_s = temp_w2->synonyms;
                temp_s1 = before_s->nxt;
                while (temp_s1 != nullptr){
                    if (strcmp(temp_s1->synonym, temp_s1->nxt->synonym) > 0){
                        before_s = temp_s1->nxt;
                        before_s->nxt = temp_s1;
                        temp_s1->nxt = temp_s1->nxt->nxt;
                    }
                    before_s = temp_s1;
                    temp_s1 = temp_s1->nxt;
                }
                temp_s2 = temp_s2->nxt;
            }
            temp_w2 = temp_w2->nxt;
        }
    }

}

void add_word(char* word, char *synonym){
    dictionary *temp_w;
    synonyms *temp_s;

    if (word_is_available(word)){
        temp_w = find_word(word);
        temp_s = temp_w->synonyms;
        while (temp_s != nullptr)
            temp_s = temp_s->nxt;
        temp_s = new synonyms;
        temp_s->synonym = synonym;
        temp_s->nxt = nullptr;
    }else if (Head == nullptr){
        Head = new dictionary;
        Head->word = word;
        Head->synonyms = new synonyms;
        Head->synonyms->synonym = synonym;
        Head->synonyms->nxt = nullptr;
        Head->nxt = nullptr;
    }else {
        temp_w = Head;
        while (temp_w != nullptr)
            temp_w = temp_w->nxt;
        temp_w = new dictionary;
        temp_w->word = word;
        temp_w->synonyms = new synonyms;
        temp_w->synonyms->synonym = synonym;
        temp_w->synonyms->nxt = nullptr;
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

void delete_synonym(char* word, const char *synonym){
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
    cout << endl;
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

void change_spelling_of_word(char* wrong_word,char* correct_word){
    dictionary *temp = find_word(wrong_word);
    temp->word = correct_word;
}

void words_storage(){
    ofstream output("file", ios::out);

    if (!output){
        cerr << "some thing wrong" << endl;
        exit(1);
    }

    while (Head != nullptr){
        while (Head->synonyms != nullptr){
            output << Head->word << " " << Head->synonyms->synonym << endl;
            Head->synonyms = Head->synonyms->nxt;
        }
        Head = Head->nxt;
    }
    output << ".";
    while (Head != nullptr){
        delete_word(Head->word);
    }

}

void read_words(){
    ifstream input("file", ios::in);

    if (!input){
        cerr << "some thing wrong" << endl;
        exit(1);
    }

    char *word, *synonym;
    while (true){
        input >> word;
        input >> synonym;
        if (strcmp(word, ".") != 0)
            break;
        add_word(word, synonym);
    }
}

// compiler man cigwin hastesh va error compile nemide
// dar github gharad dadam
// iradat proje 1) dar listpeyvandy faghat akharin node gharar darad
//              2) function haye delet_synonym , read_word (ta dar main farakhany mishavad az barname kharej mishe)
// mamnoon misham begid chejory in moshkelatesh hal mishe chon man natonestam befahmam