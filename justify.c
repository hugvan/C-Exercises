#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_WORD 20
#define PAGE_WIDTH 60

int get_num_of_words();
void get_word(char word[], int* length);
void print_spaces(int num);

int main(int argc, char* argv[]) {
    char buffer[PAGE_WIDTH][MAX_WORD + 1] = {0};
    int line_length = 0, line_words = 0;
    
    while (true) {
        char word[MAX_WORD + 1] = {0};
        int length;
        get_word(word, &length);

        if (length == 0) {
            for (int i = 0; i < line_words; i++) {
                printf("%s ", buffer[i] );
            }
            printf("\n");
            break;
        }

        if (line_length + line_words + length <= PAGE_WIDTH) {
            line_length += length;
            strcpy(buffer[line_words], word);
            line_words++;
        } else {
            //Print out buffer
            int leftover = PAGE_WIDTH - (line_length + line_words - 2);
            
            for (int i = 0; i < line_words; i++) {
                printf("%s", buffer[i] );
                print_spaces(i < line_words - 1 ? (i < line_words - 2 ? 1 : leftover) : 0);
            }
            printf("\n");
            //Reset Buffers to new word
            line_length = 0, line_words = 0;

            line_length += length;
            strcpy(buffer[line_words], word);
            line_words++;
        }
    }

    return 0;
}

void print_spaces(int num) {
    for (int i = 0; i < num; i++) {
        printf(" ");
    }
}


void get_word(char word[], int* length) {
    bool in_word = false;
    int i = 0;

    for (int ch; (ch = getchar()) != EOF;) {
        if (in_word && (ch == ' ' || ch == '\n' || ch == '\t'))
            break;
            
        if ((!in_word && !(ch == ' ' || ch == '\n')) || in_word) {
            in_word = true;
            if (i < MAX_WORD) {
                word[i] = ch;
                i++;
            }
                
        }
    }

    *length = i;
    
}

int get_num_of_words() {
    int words = 0;
    bool in_word = false;
    
    for (int ch; (ch = getchar()) != EOF;) {
        if (in_word && (ch == ' ' || ch == '\n'))
            in_word = false;

        if (!in_word && !(ch == ' ' || ch == '\n'))
            in_word = true, words++;
    }
        
    return words;
}