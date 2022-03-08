all: lex yacc out

out: ast.c lex.yy.c y.tab.c main.c
	clang lex.yy.c y.tab.c main.c ast.c -ll

lex: rclang.l
	lex rclang.l

yacc: rclang.y
	yacc -d -Wno-yacc rclang.y
