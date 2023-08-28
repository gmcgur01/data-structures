COMPILE_FLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@

test: test.c list.o
	gcc ${COMPILE_FLAGS} $^ -o $@