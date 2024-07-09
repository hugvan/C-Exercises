#include <string.h>
#include <stdbool.h>
#include <stdio.h>

struct color {
    const int red;
    const int green;
    const int blue;
};

struct color make_color(int r, int g, int b);
void print_color(struct color c);
bool equal_color(struct color c1, struct color c2);
struct color brighter(struct color c);
struct color darker(struct color c);

int main(int argc, char* argv[]) {
    
    struct color light_red = make_color(200, 100, 100);
    struct color pink = make_color(200, 100, 100);
    struct color vanta_black = make_color(0, 1, 3);

    print_color(make_color(-1, 20, 300));
    printf("%d \n", equal_color(pink, light_red));
    printf("%d \n", equal_color(pink, vanta_black));
    print_color(light_red);
    print_color(brighter(darker(light_red)));
    print_color(darker(brighter(light_red)));

    return 0;
}

struct color make_color(int r, int g, int b) {
    struct color c = {
        .red = (r < 0 ? 0: (r > 255? 255: r )),
        .green = (g < 0 ? 0:(g > 255? 255: g )),
        .blue = (b < 0 ? 0:(b > 255? 255: b ))
    }; 
    return c;
}

void print_color(struct color c) {
    printf("Red:%d Green:%d Blue:%d \n", c.red, c.green, c.blue);
}

bool equal_color(struct color c1, struct color c2) {
    return (c1.red == c2.red) && (c1.green == c2.green) && (c1.blue == c2.blue);
}

struct color brighter(struct color c) {
    struct color c_new = make_color(
        c.red == 0? 3: c.red < 3? 4: (int) (c.red / 0.7) , 
        c.green == 0? 3: c.green < 3? 4: (int) (c.green / 0.7), 
        c.blue == 0? 3: c.blue < 3? 4: (int) (c.blue / 0.7)
    );
    
    return c_new;
}

struct color darker(struct color c) {
    struct color c_new = make_color(
        (int) (c.red * 0.7) , 
        (int) (c.green * 0.7), 
        (int) (c.blue * 0.7)
    );
    
    return c_new;
}