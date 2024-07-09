#include <string.h>
#include <stdbool.h>
#include <stdio.h>

struct point {int x; int y;};
struct rect {struct point topleft; struct point botright; };
struct point make_p (int x, int y);
struct rect make_r (int tx, int ty, int bx, int by);

int abs (int x);
int area (struct rect r);
struct point center (struct rect r);
void print_rect_details(struct rect r);


int main (void) {
    struct rect rect_1 = make_r(0,0, 4,4);
    struct rect rect_2 = make_r(4,4, 0,-10);

    print_rect_details(rect_1);
    print_rect_details(rect_2);

    return 0;
}

struct point make_p (int x, int y) {
    return (struct point) {.x = x, .y = y};
}

struct rect make_r (int tx, int ty, int bx, int by) {
    return (struct rect) {.topleft = make_p(tx, ty), .botright = make_p(bx, by),};
}

int abs (int x) {
    return x < 0? -x: x;
}

int area (struct rect r) {
    return abs(r.botright.x - r.topleft.x) * abs(r.botright.y - r.topleft.y);
}

struct point center (struct rect r) {
    return make_p( (r.topleft.x + r.botright.x) / 2 , (r.topleft.y + r.botright.y) / 2) ;
}

void print_rect_details(struct rect r) {
    printf("Corners: (%d, %d) - (%d, %d) \n", r.topleft.x, r.topleft.y, r.botright.x, r.botright.y);
    printf("Area: %d \n", area(r));
    struct point c = center(r);
    printf("Center (%d, %d) \n", c.x, c.y);
}