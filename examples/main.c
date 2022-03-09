
#include <stdio.h>

int thing(void) {
    printf("hello\n");
    return 4;
}

void foo(int x(void)) {
    x();
}

int main() {
    foo(&thing);
    int a = 10;
}
