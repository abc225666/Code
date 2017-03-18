lex lextemplate.l
gcc-6 -o scanner lex.yy.c -ll
./scanner < ./d
