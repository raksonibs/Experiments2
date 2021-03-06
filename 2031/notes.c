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
// generate bug-free code by genreationg from correct program
// test every piece. random inputs.
// blackbox testing-> assume no knowledge of implementation. 
// glassbox-> assume full knowledge of the program
// regression testing -> when fix bug, introduce more. fix that bug, may break fix. WHen you create a test, keep it and when fix a bug, apply all other tests
//boundary condition testing 
char s[MAX];
for(i=0; s[i] = (getchar()) != ‘\n’ && i<MAX-1; ++i)
;
s[--i]=‘\0’;
// after
int i;
char s[MAX];
for(i=0; i<MAX-1; i++)
if((s[i]=getchar()) == ‘\n’ || s[i] == EOF);
break;
s[i]=‘\0’;

// can use assertions in #inlcude <assert.h>
//

// arrays are data strucute of grouping by same tipe. set size explicityle. type name[value];
// declaring array allocates memory. can be int a[5] = {11,22}; declares first two elements while rest are zero
//int b[] = {1,2,3,4,5} declares array b an  intializes elements setting the length of array to five
//ar[i]++ increatements elemtn at i by one, ar[i++]; accesses element then increases i, ar[++i] increses i then access
// no string type, instead char greetings[]="hello" -> hello\n
// pointers are memory address of a variable.
// declared with double * p; has to be a * before each pointer variable
//address of (&), pointer_variable = &orindary_varaible => gets addres of
int * p1, v1;
v1 = 0;
p1 = &v1;
*p1 = 42;
printf("%d\n", v1); // 42
printf("%d\n", *p1); // 42 -> * pointer_varaible in executable statment, indicates value
//

int x,y;
int * z;
x= 25; //memory addres 1204, value 25
y =x; // value is 25, memory address 9608
z=&x; // memory address is 8404, value is x's memory address, so 1204. so when execute, gives 25!
z = *y; // y is memory address 8404, has value here of x memory of 1204, x has memory of 1204, value of 25, value of 25 corresponds now to z, with it's memory address of 9608. so z = *y assigns whatever *y memory value stored of x is to z

p1 = p2 // 9/9 + both equal 9 9.
// but *p1 = *p2 makes now both point to memory value of *p2, which stores value of nine, so both are now nine.
// identifier of an array is equivalent to address of first element. 
// int num[20]; int *p ; p = numbers -> valid but numbers = p; invalid. we can always assign anothe value to pointer b whereas numbers will always point to the first of the 20 interger numbers of type int
// void * (pointer to a void) is a genereic pointer replacing char *
//• Legal: add/sub a pointer and an integer,
// subtracting and comparing 2 pointers to
// members of the same array, and assigning or
// comparing to zero.
// • Illegal add, multiply or divide 2 pointers, or
// assign one type to another type except void *
// without a cast.
// • Any pointer can be cast to void * and back again
// without loss of information (used for pointer
// argument).
// arrays passed to functions are passed by reference.
// name of array is pointer to its first elemtny.
// does not copy the array, just a reference to it
//multip demintonal arrays int a[3][3]; inta[][3] = {{1,,3,4}, {4,5,6}}
// multi are arrays of array where m[0] is a pointer to the first row
// char * words[] = {"applie", "cheery", "banana"}
// pointers to pointers int **j; int *i, int k = 1-,
int **j;
int *i;
int k=10;
i=&k;
j=&i;
printf(“%d %d %d\n”,j,i,k); //-1073744352 -1073744356 10
printf(“%d %d %d\n”,j,*j,**j); // -1073744352 -1073744356 10
printf(“%x %x %x\n”,j,*j,**j); // bffff620 bffff61c a


void strcpy(char *s, char *t) {
int i;
i=0;
while( (s[i] = t[i]) != ‘\0’ )
i++;
}

void strcpy(char *s, char *t) {
while( (*s = *t) != ‘\0’ ) {
s++;
t++;
}
}

void strcpy(char *s, char *t) {
while( (*s++ = *t++) != ‘\0’ ) {};
}

char *words[] = { “apple”,
“cherry”,
“banana”};
Char **p;
p=words;
printf("%c\n", **p); // a
printf("%c\n",*(*(p+1)+2)); // e
printf("%c\n",*(*(p+2)+2)+1); // o -> goes n, then next char is an o

char (*p2)[100];
char name[100];
char *p1;
p1=name;
p2=name; // What is the difference?
// Consider p1+1 and p2+1

// main(int argc, char*argv[]) -> arc is num arguments, argv is array containt the arguments, argv[0] pointer to a string with program name
// although functions ar enot variables, possible to arrign pointer to a function.
// int (*comp)(void *, void *) -> comp is a pointer to a function that has two void arguments adn returns an int 
// int *comp(void *, void *) -> compi is a function that has two void * arguments and returns an *int
main() {
float y,z;
float (*myfun)(float);
x=0.76;
y=acosf(x);
printf("%f\n",y);
printf("===========\n");
myfun=acosf;
z=myfun(x);
printf("%f\n",z);
}

// above is pointer of function returning float whcih is asigned to acosf

//int *f() returns a pointer to int, int (*pf)() pf is a pointer to a function that returns int
// char **argv is a pointer to pointer to char; int (*daytab)[13] -> dayrab it pointer to an array [13] of int
//char (*(*x())[]){} -> x is a function returning pointer to array of poiinters to a function returning char
// char (*(*x[3]) ( ) ) [5] -> x is an array[3] of pointer to function returning pointer to array[5] of char
//functions are call by value
//functions must be declared first
//scope -> variables exist within their block. varaibles created at time function is called and vanish after function returncs (automatic variables)
//must be decaled before main to be global, but can be ovverridn by variable with same name in function
//extern variables msut be declared with exten. exten char line[];
// if function in same file, no need to extern
//if var is static outisde of main, not visible to other files
//if variable in function is declared static, does not vanish after function returns, it stays in the memory so the next call to the function will find the old value
//preproccsero before compile handles define and include ex: @defune ON 1 @define quare(x) x*x;
#if !defined(HDR)
#define HDR
//include the file here
#endif
#undef //x undefines x
//## means concatenate. if parameter nae is proceeded by a # in the replacement text, the combitinaiton will be expanded into a quoted string with the parameter replace by actual arcutment.
// #define dprint(expr) printf(#expr “ = %g \n”, expr) -> exp becomes in the function call
// #ifdef can also be used for conditional compilation
//cc file.c producec a.out.  convert .c file into assembly .s. make file into machine code .o, linking the .o file to the code library and named a.out
//all files can be compile to a final output cc File.o Myfunc.o
//makefile -> each depencdy handled. to compile just type make.:
OBJECTS = Comp.o Main.o io.o
Project: $(OBJECTS)
gcc $(OBJECTS) –o Project
Comp.o: Comp.c Common.h
gcc –c Comp.c
Main.o: Main.c Common.h io.h
gcc –c Main.c
io.o: io.c io.h
gcc –c io.c
// stdlib atof, atoi, stc. string.h ctrcomp, etc. ctype.h ?isdigit, is aplga. math.h sin cos, ceil

int c =10;
int myarray[c]; // not allowed
// use malloc in stdlib. allocate memory at runtime. rturns a pointer to at least n bytes, returns null if memory not allocated
//calloc, allocates an array of n elements where each has size s. calloc initlliazed memory to memory 0
//realloc, want to make grow or shrink. void * realloc(void * ptr, int n). resizes memory, 
// free, releases memory we previously allocated. ptr must be returned by malloc, alloc, realloc.
#include<stdio.h>
#include<stdlib.h>
main() {
int *a, i,n,sum=0;
printf(“Input an aray size “);
scanf(“%d”,&n);
a=calloc(n, sizeof(int));
for(i=0; i<n; i++) scanf(“%d”,&a[i]);
for(i=0; i<n; i++) sum+=a[i];
free(a);
printf(“Number of elelments = %d and the sum is %d\n”,n,sum);
}
// overruns and underruns occur when reference a memory beyond what you allocated
// could be unitliazed, example int *x; *x=20;
main() {
char *x[10];
strcpy(x[1],”Hello”);
}// also unitialized
main() {
int *x;
int size;
x=(int*) malloc(size);
*x = 20; // What is wrong
}// null pointers dereferencing
// better way incase null for x.
x=(int *) malloc(size);
if(x == NULL) {
printf(“ ERROR …\n”);
exit(1);
}
*x=20;

//memory leaks:
int *x;
x=(int *) malloc(20); //first block lost forever and may cause problems like exhaust memory.
x=(int *) malloc(30);

//problems with free pointers -> freed memory
char *x;
x=(char *) malloc(50);
free(x);
x[0]=‘A’;

// strucuts
struct chair{
  float width;
  float height;
} chair, table;

// chair and  table are variables whereas struct {...} is the type
// accessing is done via the . operator.
// strucuts cannot be assigned. ie: &chair is address of varaible chari of type strucut and chair = table
// strucuts have their own namespace separate. 
// ex:
struct dimension dimension;
struct dimension {
  float width;
} withd
// can pass strucut to arguments of functions:
float get_area(struct dimension d) {
  return d.width * d.height;
}
// cal by value, a copy of the strucutre is sent to the function
//structus can be returned ex:
struct dimension make_dim(int width, int height) {
 struct dimension d;
 d.width = width;
 d.height = height;
 return d;
}

//. has a higher precedence
//*p.width -> is wrong but can use (*p).width; or p->width
//inefficint to pass large structures to functions instead use pointers and you can manpulate the same structure
//
struct list {
 int data;
 struct list *next; //okay to use pointer to struct that is declared but not defined
};

//pointer points to first element head and alst element is pointer is null
#include <stdio.h>
#include <stdlib.h>
main() {
struct list{
int len;
struct list *next;
} *head,*p,*last;
head=(struct list *)malloc(sizeof(list));
head->len=1;
head->next=NULL;
last=head;
int i;
scanf("%d",&i);
while(i>=0) {
scanf("%d",&i);
p = (struct list *)malloc(sizeof(list));
p->len=i;
p->next=NULL;
last->next=p;
last=p;
}
printf("Enter the number you want to
search for ");
scanf("%d",&i);
for(p=head; p!=NULL; p=p->next)
if(p->len == i)
printf("FOUND \n");
}

void deleteit(dim **p, int i) {
 // DOES NOT WORK 1st element
 dim **p1,*temp;
 p1=p;
 while((*p1)->num != i) p1=&(*p1)->next;
 temp = *p1;
 *p1 = (*p1)->next;
 free(temp);
}

struct dimension *tables;
tables = (struct dimension*) malloc
(20*sizeoff(struct dimension));

// nested structus
struct point { int x, int;}
struct line {
  struct point a;
  struct point b;
} myline;

mylinfe.a.x = 0;
myline.a.y=5;

//define a new type of type with typedef ex:
typedef struct {
  int x,y;
} newtype;

// newtype a1,b1; now new type is a type in C just like int and float

union value {
  int i;
  char c;
}

// similir to sturct but all variables have same memory location and accessed differntly
unin value v;
c.i = 45;

enum state {
  IN,
  OFF
} x;

x=IN if (x==OFF) {...}
// just some large var i think?

// insert debugging statuemnts;
// conditional compilation
#define DEBUG 1
i=f(j);
#if DEBUG
printf(“f:in %d out %d\n”,i,j);
#endif

//gdb print varible, x contents of address, backtrace tells gdb to lit all function calls that lead to crash in stack frame. 
// common crashes: unaligned memory access (access to more than one byte must be aligned at a particular size); depends on cpu
// using unitinalized pointers, bounds on array
//good modular design, clear logic, assigning responsiblity
//when program dumps core, it creates a dump file called core. file is an image of mmeory, registers including stack and data at time of crash.
// also use #unclde <errno.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#define POSITIVE 25
#define NEGATIVE -25
int main() {
double ret;
errno = 0;
ret = sqrt(NEGATIVE);
if (errno == EDOM) /*EDOM
Signifies Domain Error*/
printf("Domain Error : Invalid Input
To Function\n");
else
printf("Valid Input To Function\n");
errno = 0;
ret = sqrt(POSITIVE);
if (errno == EDOM)
printf("Domain Error : Invalid Input
To Function\n");
else
printf("Valid Input To Function\n");
return 0;
}

#include <stdio.h>
 #include <errno.h>
 #include <math.h>
 void test(double value) {
 double ret;
 errno = 0;
 ret = sqrt(value);
 if ( errno )
 {
 perror("sqrt");
 }
  else
 {
 printf("ret = %g\n", ret);
 }
 }
 int main() {
 test(-25);
 test(25);
} 

 //int fseek -> fet file position indicator for the stream pointed to by stream, if error, error indicators stream shall be set and fseek fails. the new position, measured in btes,
// #include <stdlib.h> int rand() returns random numner. 
// srand(num) seeds random number generator. if want truly random have to read from /dev/random or /dev/urandom

FILE *fp1;
int c;
fp1=fopen(“/dev/urandom”,”r”);
c=getc(fp1);
printf(“%d\n”, (int)c);
fclose(fp1); 

// could use time_t time(time) with srand ie: srand((unsigned int) time(NULL)); from time.h

//os does file management, scheduling, memory management, i/o management
// includs kernel, system programs, shell
// each prog has a process with its own PID


// # Set the initial value.
// myvar=abc
// echo "Test 1 ======"
// echo $myvar # abc
// echo ${myvar} # same as above, abc
// echo {$myvar} # {abc}
// $ sh var_refs
// Test 1 ======
// abc
// abc
// {abc}
// echo "Test 2 ======"
// echo myvar # Just the text myvar
// echo "myvar" # Just the text myvar
// echo "$myvar" # abc
// echo ‘$myvar’
// echo "\$myvar" # $myvar
// Test 2 ======
// myvar
// myvar
// Abc
// $myvar
// $myvar
// echo "Test 3 ======"
// echo $myvardef # Empty line
// echo ${myvar}def # abcdef
// Test 3 ======
// abcdef

// $? - exit status 
// $$ - process id 
// $* string containg list of arguments
// $# number of arumgnet 
// $0 command line 

// • ${name-word} - value of name if it exists,otherwise word
// ${name+word} - “word” if name exists, blankotherwise
// • ${name=word} - if name does not exist, sets variable name to word, substitutes value of name
// • ${name?word} - if name does not exist then prints an error (“word”) then exits shell - otherwise substitutes value of name
// read is built in command with an exit status of 0, on failre or eof.
// read input default spearates words by spaces and tab charaters. can change separator by setting IFS: // ex: IFS=:
// z=`expr $z +1`
// bash alllos artheitc interger operatios via let or $(())
N=`echo “scale=3; 13 / 2” |bc`
echo $N

// set command resets position arguments. ex set apple banana cherry and echo $1, $2, $3
// test comman or [ $1 != Tom ] echo $? -u is suid bit. -L symboli link, -s is nonzero size.; bash extended operators allows for & and ||
// • [ $var = rightvalue ] && echo OK bad practce because text syntax error when var is blank
//[ "X$var" = "Xrightvalue" ] && echo OK // X infront protexts against unusual variable values
//• [ -d $dir ] || mkdir $dir -> create directory if does not exist
//

if [ $marks –ge 80 ]; then
grade=A
elif [ $marks –ge 70 ]; then
grade=B
elif [ $marks –ge 60 ]; then
grade=C
else
grade=D
fi
echo $grade

myprogram < data.in > result.out
if [ -s result.out ]; then
echo "Output generated !!"
else
echo "empty output!!"
fi

for SCRIPT in /path/to/scripts/dir/
do
if [ -f $SCRIPT -a -x $SCRIPT ]
then
$SCRIPT
fi
done

// -eq does compairson for value equal, and not =
$cd testdir 2>/dev/null && rm *.dat  // run second only if first succeeds
set –e // exits first time encounters and error
command1 || command2

for user in `cut -d: -f1 < /etc/passwd`
do
echo –n "$user:"
finger $user
done

while read line
do
echo line: $line
done <file

(while read line; do; echo line:$line;
done) <file
// each case must end in ;;
case $# in
0) set `date`; m=$2; y=$6;;
1) m=$1; set `date`; y=$6;;
2) m=$1; y=$2;;
esac
case $m in
jan*|Jan*) m=1;;
feb*|Feb*) m=2;;
mar*|Mar*) m=3;;
apr*|Apr*) m=4;;
may*|May*) m=5;;
jun*|Jun*) m=6;;
jul*|Jul*) m=7;;
aug*|Aug*) m=8;;
sep*|Sep*) m=9;;
oct*|Oct*) m=10;;
nov*|Nov*) m=11;;
dec*|Dec*) m=12;;
[1-9]|10|11|12) ;;
*) y=$m;m="";;
esac
/usr/bin/cal $m $y

// shift moves all arguments down 1
// so $2 bwcomws $1 and $1 gets throgwn away
while [ $# -gt 0 ]; do
echo "processing arg:  $1"
shift
done

// can write functions name() {...}
allfiles() {
// # true if all args are files
for x in $*; do
if [ ! -f $x ]; then
return 1
fi
done
return 0
}

// .. no local variables in shell but can be if set local x="hello"
x= # set x to blank
f1() {
x=“hello”
}
f1 ; echo $x # call f1()

n[iea]ce
^day 
day$
[^abc] // char not in abc
ab{3,5}c
// ab{1,}c matches at least one occurence of b
//? is optional in reg exp. zero or one.
// \<[tT]he\> matches words as well
a(xyz)*
a(xy){2,3}
// tr ab cd replaces every occuence of a by c and by by d
// xargs commands execute the given command for ach word in stdin
// • find . –type f –name “*.c” –print |xargs wc
// `back quotes are shell commands and double quotes are like single quote except the varaible subsimtiona nd back quotes are treated as special characters
//
#!/usr/bin/env bash
# cookbook filename: trackmatch
#
for CDTRACK in *
do
if [[ "$CDTRACK" =~ "([[:alpha:][:blank:]]*)- ([[:digit:]]*) - (.*)$" ]]
then
echo Track ${BASH_REMATCH[2]} is ${BASH_REMATCH[3]}
mv "$CDTRACK" "Track${BASH_REMATCH[2]}"
fi
done

sed 's/day/night'
sed 's/[0-9]*/& &/' //doubles a number at the beginning of a line

– sed -e 's/a/A/g' \
-e 's/e/E/g' \
-e 's/i/I/g' \
-e 's/o/O/g' \
-e 's/u/U/g' <old >new

– sed -f sedscript <old >new // if have large number of sed commands 
 # sed comment - This script changes lower case
vowels to upper case
s/a/A/g
s/e/E/g
s/i/I/g
s/o/O/g
s/u/U/g

// every line of input read into pattern space. after all lines read through pattern space, line is sent to piutput,.
//-n suppresses the automatic printing of pattern space. -e script to follow. -f script file
///^S/d delet all blank lines. 7d delete seventh line
// /a append /c change current line with new text.h/ copy pattern space. p print line, s is to susbtitue.
// sed –n ‘s/west/north/p’ print only line that contains the word after replacing it by north
// sed –n ‘s/west/north/gp’ print only line that contains the word after replacing it by north but replace every occurrence (g for globally)
// sed ‘/James/r newfile’ file Looks for lines that contains James and right after it, sed read and includes the contents of “newfile”
// • sed –n ‘/north/ a\ <---Moved------->’ file It will append the string “<---Moved--->” after each line that contains “north
// sed ‘1,3y/abcdef/ABCDEF/’ datafile Capitalize letters a-f in// the first three lines
// awk consists of inscturcions and action.
// actions are separate my semiconl
// awk NR is record number while NF is the number of fields in a record
//

BEGIN { print "Beginning of file";
print "-----------------" ;
}
// # Print every line in the file.
END { print "------------"; print "End of file."}

//• awk ‘$3 ~ /Bill/{print $3}’ file
// date | awk ‘{print “Month: “ $2 “\nYear: “ $6}’ // columnar data



// explore is x[i] same as *(x+i)
// should make linked list code
// struct dimension *tables; -> student question
// tables = (struct dimension*) malloc
// (20*sizeoff(struct dimension));
