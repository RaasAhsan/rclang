#include <stdlib.h>
#include <stdio.h>

struct x {
    int a;
    int b;
};

struct y {
    int a;
};

int main() {
    struct x *x = (struct x*) malloc(sizeof(struct x));
    x->a = 4;
    x->b = 8;
    struct y *y = (struct y*) x;
    struct x *x2 = (struct x*) y;
    printf("%d\n", y->a);
    printf("%d\n", x2->b);

    if (1 == 1) {
        struct point {
            int x, y;
        };

        struct point p;
    }

    struct point p;
    p.x = 4;

    return 0;
}
