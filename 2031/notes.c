// 1978 - deniis ritchie brian kernighn
// ansi completed standard for C approved in 1989 known as c89
// - c99 standard
// almost low level, small permissive
// efficent
// ideas/specs, design, debugging coding, program, testing
// testing show presnce of faults, not their absence
// syntax, runtime, logic
// runtime errors: violation of rules during execution
// logical -> not detected by compiler may not produce error
// no garbage collection, no classes, no exception, no type strings
// 4 basic types: char, int, float, double
// modifiers -> signed (unsigned) int long int, 
// char -> one byte // reg bools. 
// i/o -> stderr, stdin, stdout  
//  %d int, %s string, %c char, %f float, %if double precision
// int get char -> next char of standinput or eof if no characters left
// int putchar -> write character to standard output
//var can't start with num or keyword
// /#define abc zux replaces every occurence of abc with zxy
// (double) varB doesn't change value of varB but just the type to double
// prepost operators
// obvious bitwise operators &, |, ^, ~
//x << y means shift x to the left y times
// if unsiged left shfit, if unsigned 0, if signed undefined.
// bool false is zero
// limits.h proives some constants z = (a > b)? a : b
// stream any source of input or any desition for output/
// .. file Pointer is FILE *
// open file before read or write and returns nonnegative integer known as file description, all read through this.
// • FILE *fp1;
// • FILE *fopen(char *name, char *mode)
// • fp1=fopen(name, mode);
// do not assume file open, check null pointer.
// read or write characters int fgetc
// int fputc returns a byte from a file or EOF
// \ in file name might be escape character
//

FILE *fp
fp = fopen(“name”, “r”);
if(fp == NULL) {printf (…); exit }

// gets reads character tille new line, fgsets reals till newline or n-1 character, if newline added to string
//fseek set file position for stream pointed to by stream. the new postion, measured in bytes from beginnig, shall be.
//fscanf and printf with first paramater as file pointer, but error may be feof(fp) end of file or read error, both retugning nonzero value, or even a matching error