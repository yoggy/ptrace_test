TARGET=all

all: test

test: ptrace_test
	./ptrace_test

ptrace_test: ptrace_test.c
	gcc ptrace_test.c -o ptrace_test

clean:
	rm -rf ptrace_test

