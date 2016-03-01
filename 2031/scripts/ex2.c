#include <stdio.h~
1*countdigits,whitespace,others*1 maine )
{
}
The output
nwhite, nother);
of this program on itself is
int c, i, nwhite, nother; int ndigit[10];
nwhite =nother =0;
for (i = 0; i < 10; ++i)
ndigit[i] =0;
while «c = getchar(» 1= EOF) if(c>= '0'&&c<= '9')
++ndigit[c-'O'];
e1se if (c== ' ,I I c == '\n' I I c == '\t')
++nwhite; ~lse
++nother;
printf("digits =");
for (i =0; i < 10; ++i)
printf(" %<i", ndigit[i]);
printf(", white space::;%d, other =%d\n",