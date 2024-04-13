q1: 1_tokens_counter.l
	@flex 1_tokens_counter.l
	@gcc lex.yy.c
	@./a.out

q2: 2_odd_or_even.l
	@flex 2_odd_or_even.l
	@gcc lex.yy.c
	@./a.out

q3: 3_odd_b.l
	@flex 3_odd_b.l
	@gcc lex.yy.c
	@./a.out

q4: 4_b___a.l
	@flex 4_b___a.l
	@gcc lex.yy.c
	@./a.out

q5: 5__baba_.l
	@flex 5__baba_.l
	@gcc lex.yy.c
	@./a.out

q6: 6_calculator.y 6_calculator.l
	@yacc -d 6_calculator.y
	@lex 6_calculator.l
	@cc lex.yy.c y.tab.c -ll
	@./a.out

q7: 7_leftrecursion.c
	@gcc 7_leftrecursion.c
	@./a.out

q8: 8_first_follow.cpp
	@g++ 8_first_follow.cpp
	@./a.out

q9: 9_quadruples.c
	@gcc 9_quadruples.c
	@./a.out

q10: 10_triples.c
	@gcc 10_triples.c
	@./a.out