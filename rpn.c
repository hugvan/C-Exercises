#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define MAX_DIGITS 10

enum term_type {NUMBER, OPERATOR};
struct term make_term(enum term_type t, int data);

const char DIGITS[] = {'0','1','2','3','4','5','6','7','8','9',};
const char OPERATORS[] = {'+','-','*','/','%'};

struct term {
    enum term_type type;
    union {
        int num;
        char op;
    } data;  
};

int main (void) {

}

struct term make_term(enum term_type t, int data) {
    struct term ret = {.type = t};
    if (t == NUMBER) {
        ret.data.num = data;
    } else {
        ret.data.op = data;
    }
    return ret;
}

struct term scan_term() {
    
}