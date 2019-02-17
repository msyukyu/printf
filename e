make fclean
gcc -g -fsanitize=address */*.c -Iincludes -o a.out
./a.out
rm a.out
rm -rf a.out.dSYM
