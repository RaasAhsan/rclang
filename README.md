# rclang

rclang is a self-hosted C89 compiler.

## Test
```
$ yacc -d c.y && lex lex.l && clang lex.yy.c y.tab.c main.c -ll && ./a.out
```

## Status
