make fclean
gcc -fsanitize=address */*.c -Iincludes -o a.out
./a.out
rm a.out
