make fclean
gcc -g -fsanitize=address */*.c -Iincludes -o a.out
./a.out | cat -e
echo ""
echo "---"
./a.out | hexdump
rm a.out
rm -rf a.out.dSYM
