# get_next_line
This project was all about reading one line at a time from a file, each line ending with a newline character read from a file descriptor. 

This project allowed us to use our earlier created C library, together with these three malloc, free and read libc functions.

This project gave me a better understanding of stack and heap memory, how memory is allocated and freed when stack or heap is used. I also learned about memory leaks.
To get a better understanding of the computer's memory I also studied the computer's RAM memory.

# How to

To compile the function and the libft.

The main.c found in the repo can be used for testing purposes or then one of your own.
```
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft

```
