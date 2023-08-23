COMPILE_FLAGS = -Wall -Wextra -Werror

%.o: %.c
	gcc -c $< -o $@

test: test.c stack.o
	gcc ${COMPILE_FLAGS} $^ -o $@