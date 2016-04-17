- instruction set.
- design 1:simplicity favors regularity.
f = ( g + h ) - ( i + j)
add t0,g,h
add t1, i, j
sub f, t0, t1

design 2: smaller is faster
- artmitc oprations occur only on registers in mips instructions, thus mips must include instructions that transfer data between memories and registers.
- called data transfer instructions.
- to access a word in memory, must provide the memory address.
-address just single array.
- data transfer copies data from memory to a register is called a load.
- format of load is name of operation followed by the registe to be loarded, then a constant and register used to access memory.
- sum of constant portion and contents of second register form the mrmory address, called load word.
-g = h + A[B];
lw $to, 8($s3) // transfer a[8] to a register and found in elemnt 8 of register s3.
-add $s1, $s2, $t0 
-not t0 is a[8] wherein h is stored in s2, and then register the result in s1 register.. the constatn in a data transfer instrciton (8 here) is called the offset and the register added to form the address s3 here is called the base register
-the compiler also allocates data strucutres like arrays to locations i mmory. can then properly start address the data into data trnasfer isntructions.
- since 8bit bytes used, virtually all archetiures address individual bytes. therefore a words' address matches the address of one of the 4 bytes within the word, aand address of sequential words differ by 4.
-in MIPS words must start at addreses with multiple of fours, called allignment restirction. leads to faster data transfers
-computers divide into those use the address of the leftmost or bidend byte versus little end right bye. MIPS is the big-endina.
-byte addressing affects arra index in that to get proper byte address, the offset to be added to hte base register $s3 must be 4*8 or 32, so that the load address will select a{8} and not A[8/4].
- the sintruction complementary to load is traditioanlly called a store. it copies data from a register to a memory.  called store word.
-ex:
a[12] = h + a[8]

lw $t0, 32($s3)
add $t0,$s2,$t0
sw $t0,48(s3) / this is stores h + a[8] back into a[12] but 48 or 4*12 is difference. need proper offset for byte addressing in the load word to select a[8] and then a[12] needs propoer offset and resgister s3 as base register
- many programs have more variables than computers have reigsters. therefore compiler keeps most frequent vars in registers nad places rest in memory, using loads and stores ot move varaibles between registers and memory. process of pushing vars aside is called splitting registers
- memory is slower than registers
- data more useful in register, as mips arthmetic can read two registers, operate on them and write, but data transfer needs to read, and can't write without operating on it.
- thus registers take less time to access and have highe rthroughput than memoy, making them awesome.
- least most is the bit o, most signifanct is left most bit.
- reprsent numbers 0 to 2^32 - 1 
- leading zeros means positive, signed mean negative a la two's complement. s
- two's complement has one negative that there is no correpsonindg positive for.
- signed load copy the signe to fill rest of register. unsigned loads simply fill with 0s left to the data.
- shortcut on twos complete invert every 0 and 1 and add one to result
- s0 to s7 are registers 16-23 while t0 and t7 map to 8 and 15.
- add $t0, $s1, $s2 = 0 | 17 | 18 | 8 | 0 |32
- each segement of instruction is called a field, the first and last fields tell computer perfroming adition. second field gives number of the register that is is the first source operand, s1 or 17, third is the other operan, which is s2 or 18. the fourth contains the number of the register the sum, which is t0 or 8, the fifth is unused in this insturction, and converting to binary gives us 
00000 | 10001| 10010 | 01000 | 000000 | 100000
- called instruction format 
-takes exaclty 32 bits, same size as data word -
call numeric version machine language and sequence of such numbers machine code 
-binary to hex 4 to one, where a is ten, and f is 1111 (17)
-
mips fields are given names:
op (6 bits) | rs (5 bits) | rt (5 bits) | rd (5 bits) | shamt (5 bits) | funct (6 bits)
- op is basic operation or opcode 
- rs is the first register course 
-rt is second register 
- rd is the register destiation with resutl 
- shamt is the shift amount
- funct is the fucntion code and selects the specific variant of the operation in op field 
-problem occurs whe nneed more fields than above, example load word instruction specify two registers and a constant.
- design 3: good design demands good compromises.
- the above is called Rtype for register, second type is I type for immediate data transfers. these are:
op (6 bits) | rs (5 bits) | rt (5 bits) | constant or addresss (16 bits)
-16 bit addres means a load word instruction can load any word at 215 of the base register rs. similair add imperidate is limited.
-ex: lw $t0, 32($s3)
- here 19 for ($s3) placed in rs field, 8 (for $to) placed in the rt field, and 32 placed in the address field.  the rt for a load word instruction specifics destionation egister.
-formats are dinstinbuished by the values in the first field, each format is assigned a disntinct set of values in the first field (op), so thatthe hardware knows whether to treat the last half of the instruction as Rtype or I type.

ex: a[300] = h + A[300];
lw $t0, 1200($t1)
add $t0, $s2, $t0
sw $t0, 1200($t1) (rember times by 4 to grab address)

machine intrusctions:

op     | rs                  | rt                   | rd          | address/shamt | funct 
35(lw) | 9(register for $t1) | destination is 8 $t0 | 1200 -> because I type, address is the next three to store 300*4 addresss
0 add is 0 and 32| 18 for s2 | 8 other operand for t0 | 8 for destination | 0 | 32 
43 is sw | 9 is t1 | 8 is dest t0 | 1200 is address constant

- can convert the above to binary
-desire to keep all instructions same size is in conflict with desire to have as many reigsters as possible. increase in numbers of registers uses up at least one more bit in every register field of the instruction format 
- instructions represented as numbers, programs stored in memory. stored program concept.
- memory can contain the source code.
-shipped as binary numbers
- shift left << smaller
- shight right >> srl 
bit & and/andi 
- bit or | or/ori 
bit not ~ nor 
-the dual of a shift left is a sift right
ex: sll $t2, s0, 4 # shift into t2 the $s0 reguslts left byfour bits
op | rs | rt | rd | shamt | funct 
0 | 0 | 16 (s0)| 10 (t2) | 4 
- shifting left logical provdes bonus i bits and gives same result as multiplying by 2i.
- beq register1, register2, L! # go to stateent l1 if value in register equals register 2. branch if equal
- bne resgieter1, register2, L1 # if not qual go to l1.
ex: 
if (i==j) f = g + h; else f = g - h; 
bne s3, s4, Else 
add s0, s1, s2
j Exit #ends conditional branch. unconditional branch. j is jump
Else: sub s0, s1, s2 
Exit;

ex2: 
while (save[i] == k)
  i += 1;

assume i and k are s3 and s5 and base of array save is in s6
- need to load save[i] into tmp register., but need to get its address. before e can add i to base of arry save to fomr address, must multipy index i by 4 due to byte addressing problem. 
- but can use shift left logical, since shifting left by 2 bits multiples by 2*2 or 4. need to add loop so can branch back to instruction.
Loop: sll t1, s3, 2 
  add t1, t1, s6 
  lw t0, 0(t1) # save to tmp register 
  bne t0, s5, Exit #go to exit if save[i] != k
  addi s3, s3, 1 # add one to i and save i
  j Loop 
Exit;
# called a basic block of instructions without branches
- for for loops may want to see if index less than 0, so can use set on theas than
slt t0, s3, s4 # t0=1 is s3 < s4  otherwise set 0
unsigned intergers are compared using set on less than unsigned, or set on less than immediate unsigned
s0 = 1111 1111 1111 1111 1111 1111 1111 1111
s1 = 0000 0000 0000 0000 0000 0000 0000 0001
slt t0, s0, s1 #signed comparison  this is 1 since -1 < 1
sltu t1, so, s1 #unsigined comparison this is 0 since 4292929292 unsigned is greather than 1

- treating signed numbers as if unsigned gives quick way to check if 0<=x<y mathces the index out of bounds checks for arrays
- key is that negative integers in two's compleemnt look like larege numbers in unsigined notation, that is the most signifant bit is a sign bit but part of the larger bit when unsinged. thus unsigned compariosn of x < y also checks if x is ngeative as well as if x is less than y 
ex:

sltu t0,s1,t2 #to-0 if s1>-length or s1<0 
beq to, zero, IndexOutOfBounds 

- can make jump table for switch statements. is just an array of words containtg addresses that correpsond to labels.
- program loads teh appropriate entry from the jump table into a register
-Mips includes a jump register instruction (jr) meaning an uncondtional jump to the address specific in a register.
- procedure is function used to structure tools.
-execution of producre must: put apratmeters where procedure can access them, transfer control to the procedure, perfrom the desired task, put result where can be called, return control to point of origin since procedure can be caled from several points in a program 
-registers are fastest place to hold data in computer. mips has allocation for 32 registers:
a0-a3: four argument registers to pass paramters, v0-v1: two valuer registers to return values, ra: one return address register to tretun to point of origin 
- includes an instruction for procjedures, it jumps to an address and simluatenously saves the address into register ra (the return address resigter). the sump-and-link instruction )jal) is jal ProcedureAddress
-link portion means an address is formed that points to the calling site to alow the procudre to return to the proper address. this link stored in register ra (register 31) is called the return address. is needed because same procedure could be called from several parts of the program 
-to support mips use jump register instruction meaning an uncondtional jump to specified register. jr $ra . thus the calling program puts paratmer values in a0-a3 and uses jal X to jump to procude X (the calle). the callee performs the calculations, places the results in V0, and v1, and returns control to the caller using jr and ra .
- implicit in the stored program is needed to have a register to hold address of currenct instruction being executed, and this iis called the program counter. PC. jal instruction saves PC + 4 in register ra to link to the following instruction to set up the procedure return 
-suppose compiler needs more register sthan four arguments and two return value registers. any registers needed by caller must be resotred to the values they continaed before the procesure was invoked. we ned to spill registers into registers 
- the ideal structker for spilling registers is a stack, a last in first out queue. a stack needs a poiinter to the most recently allocated address in teh stack to show where the next prodcure should ptake place or where old register values are fond 
- the stack pointer is adjusgeted by one word for each egister and is saved or stored. register 29 is the stack pointer, given register name $sp. 
- push and pop 
- you push values onto stac by subtracting form the stack pointer. adding to stack pointer shrinks the stack and thereby pops values off stack 
ex:
 int leaf_example (int g, int h, int i, int j)
     {
int f;
          f = (g + h) – (i + j);
          return f;
     
}

#g,h,i,j correspond to a0,a1,a2,a3 and f is s0 
leaf_example: 
  addi $sp, sp, -12 #adust stack to make room for 3 items 
  sw t1, 8(sp) save register t1 to use afterwards 
  sw to, 4(sp) save t0 for afterwards 
  sw s0, 0(sp) save s0 for aftwareds

  add to, a0, a1 #register to contaings g + h 
  add t1, a2, a3 #register t1 containts i + j 
  sub s0, t0, t1 # f = to - t1
  add vo, s0, zero # returnfs f 
  # before returning we restore the three old values of the resiger we save dby popping them from stack 
  lw $s0, 0($sp)  # restore register $s0 for caller
  lw $t0, 4($sp)  # restore register $t0 for caller
  lw $t1, 8($sp)  # restore register $t1 for caller
  addi $sp,$sp,12 # adjust stack to delete 3 items
  jr ra # jump back to calling routine using return address


- to avoid saving and restoring registers whose value is never used, mips separates 18 registes into two groups:
t0-t9 : tmp registers not preserved by callee,
s0-s7: saved registers that must be preserved on procudre call 
this regudres register spilling. since called does not expecter reigster toand t1 to be preseverd across a procudre call, we can drop two stores and two loads from the code. we must still have and restore s0, since callee must assume need returned value 

- one solution is to push all other registers that must be presevered into stack, the caller pushes any arugment registers or temporary registers thatare needed after the call. the callee pushes the rteutn address ra and any saved registers used by calleee. the stack pointer sp i sadusted to account for number of registers placed on the stack, upon the retugn, the registers are restored from memory and rstacker pointer readjusted
ex:int fact (int n)
  {
      if (n < 1) return (1);
            else return (n * fact(n – 1));
}

fact: 
  addi sp, sp, -8 #adjust stack for 2 items 
  sw ra, 4(sp)
  sw ao, 0 (sp)

  slti t0, a0, 1 # test if n < 1 
  beq t0, zero, L1 #if n >=1, go to l1 

  # if n is less than 1, fact returns 1 into value register 
  addi, zero, 1 #return 1 
  addi sp, sp, 8 #pp two items off stack 
  jr ra # return to call 
  #if n is not less than one, ao must me smalled, and recall fact 
  L1: addi a0, a0, -1
    jal fact
  # where fact returns, returning old addressand numbers restored
    lw a0, 0 (sp) #return from jal,retstore argument n 
    lw ra, 4(sp) #restore the return address 
    addi sp, sp 8 # adjust to grab 2 items 
    mul vo, a0, v0 #return n * fact(n-1)
    jr ra

  -to simplifiy static data, MIPS reserves another register called global counter 
  - c programmers need space in memory for static variables and dynamic data structures: stack starts at high end of meomory and grows down. 
  - first part of low end memory is reserved, followed by home of MIPS machine code, called text segment.
  - avoce code is the static data segment, which is place for cosntants and other static variables 
  - data structures stored in the heap.

  so low end goes reserced -> text -> static data -? stack and dymoic data
  - c uses malloc and fee to allocate space on the heap and returns pointer to it. 
  -forgeting to free spcae leads to memory leak, which eventually uses up somuch memory operating system may crash 
  -free space early leaves to dangling pointers, whcih cause point t things instead 
  - more than four paramters places extra paramters on stack just above frame pointer. procudere then exprest the first four and rest via memory. frame pointer is convienent because all references to variables in stack within a procedure have same offset. 
  -
   ex2:
int sum (int n, int acc) { if (n >0)
  return sum(n – 1, acc + n); else
  return acc; 
}

sum: 
  slti t0, a0, 1 # test if n <= 0 
  bne t0, zer0, sum_exit #go to sum_exit if n <= 0
  add a1, a1, a0 #add n which is the arugment to acc 
  add a0, a0, -1 #subtract 1 from n 
  j sum #go to sum 
sum_exit:
  add v0, a1, zero  #return value of acc 
  jr ra @return to caller



  addition and subtraction pretty easy on binary.
  - overflow occurs when result from operation cannot be resperenset with available harare, in cae of 32 bit additon. when adding operainds with diff signs, ofervlow cannot occur.
  -when subtract overflow can't occur when signs are the same as always smaller 
  -lack of 33rd bit means when overflow occurs, sign bit is set with value instead of proper sign of result 
  -a carry out would have occured into the sign bit
  - we must then have a way to ignore overflow, where add unisigned ingore overflow 
  -mips determine overflow with an excpetion, also called an interrupt. an interurpot is an unschedulred procudre call. addres of isntruction that overlfow is svaed in a register and computer jumpts to a predfeined address to invoke the appropaite routine
  -mips only has integer arhtemitc ops on full words 
  -can have mips to detect overlfow
  addu t0, t1, t2 
  nor t3, t1, zero 
  sltu t3, t3, t2 
  bne t3, zero, Overflow 

  multiplcand has long process  shift left, and a bunch of other stuf, refer to paper notes.
  ex: multiplty 0010 by 0011 
  0
Initial values
 0011
0000 0010
0000 0000
1
1a: 1 ⇒ Prod = Prod + Mcand
0011
0000 0010
0000 0010
2: Shift left Multiplicand
0011
0000 0100
0000 0010
3: Shift right Multiplier
 0001
0000 0100
0000 0010
2
1a: 1 ⇒ Prod = Prod + Mcand
0001
0000 0100
0000 0110
2: Shift left Multiplicand
0001
0000 1000
0000 0110
3: Shift right Multiplier
 0000
0000 1000
0000 0110
3
1: 0 ⇒ No operation
0000
0000 1000
0000 0110
2: Shift left Multiplicand
0000
0001 0000
0000 0110
3: Shift right Multiplier
 0000
0001 0000
0000 0110
4
1: 0 ⇒ No operation
0000
0001 0000
0000 0110
2: Shift left Multiplicand
0000
0010 0000
0000 0110
3: Shift right Multiplier
0000
0010 0000
0000 0110

-

store multipler and muplicatnd and product.
if multipler least signifat is 1, then add prod + mulciandt. then shift left mulcand and shift right multipler 
if multipleiter is zero, just shift left multicand, and shift right multipler 
- to multiply signed numbers, just remember the sign, and then just change to negative after 
-faster multiplcations are possible by essentialy adding one 32 bit adder for each bit of multiper,
rather than using a single 32 bit adder 31 times, user 31 adders and organize to minimize delay.
- mips uses separate pair of 32 bit registers to cotina the 64 bit production called hi and lo. to fetch integer 32 bit product, uses mflo (move from lo). 
- no overflow in multipcation mips, so upt to software. if no overflow if Hi is 0 for multu or replicated sign of Lo for mult 
- divdend = quotient * divisor + remainder 
- divide 7 by 2:
1. subtract divior from remiander resgiter and  lace in raminder register. 
if remiander negative, restore original value by adding the divisor register to raminder register nad placing sum in the remainder register. also shift the quotient register to the left, settingthe new least significnat bit to 0.
if remainder greater or zero, shift quortient register left, setting new rightmost bit to 1.
- shift divisor register right 1 bit.
- no 33rd repsietions then done
- divisor into alu into remainder with control test
-negate the quotietn if signs disagree
-signed division must also set sign of reminader. make sure adds up toegher.
- be able to speed up division by throwing hardware add it, but can't do same trick for division. Reason is that we need to know sign of difference before can perform next step of alogrhtim, but we could do 32 partial products
-srt division is an example iwth a lookup table of various upper bits of reminader and dividedn
-divu/div in mips assign Hi with the reamidner and Lo contains the quotient. the mips assembler allos divide instructions to speficity three gereits, generating mflo and mfhi instrcutions to place the desired reuslt into a general purpose register
- can show scentigic notation in binary.  need a new dciaml point which is a binary decimal point 
-floating point because binary point is nto fixed.
- standard scientific notation for reals offers simply echange of data that includes floating point, simiplies algothirms, and increased accuracy of word because unnecessary leading 0s are replaced by real digits to right of binary point 
-must compromise between size of fraction and size of exponenet 
- (-1)S * F ( 2E where f is the fraction field at 23 bits and E is the exponent field, at 8 bits. 
  -Fractions as small as 2*10-38 are represened, and as large as 2.0 * 10^38). over flow still possible because exponenet is too large to be repsreneted 
- new king of excpeitona event because can be too small, which is underflow . the negative expontnent is too large to fit the exponnent field 
- one way to remove underflow or overflow is to offer another format that has a larger exponent, called double in C, which is double precision.. exponent becomes 11 bits, with faction being then 20 + another 32 bits with a 52 bit number. 
- biased notation, with bias being number subtracted from the normal, unsigned representation to determine the real value. bias of 127 for single perceiton so an expoent of -1 is represented by bit pattern of -1 + 127 and 1 is +127/ The exponenet for double percesion is 1023. 

ex: -0.75 in single and double perceison 
= -3/4 or -3/2^2
-11/2^2 in binary fraction 
-0.11 * 2^0 in scntific notation.
in normalized scientifc notation 01.1 * 2^-1 
for single percesion: (-1)^s * (1+ Fraction) * 2^(Exponent-127)
( 1)1   (1   .1000 0000 0000 0000 0000 000)  * 2&(126-127)
becomes 1011111101(and 22 zeros) and double point becomes same but with way more zeros.
- going other way, sign bit is 1, exponent fields contains 129, and frction field cointains 1 * 2^-2 or 0.25.
(-1)^s * (1 + fraction) * 2^(Exponent - Bias) = (-1)^1 *(1+0.25) *  2^(129-127) = -5.0

- to perfrom floating point properly align the point of number that has smallest exponent. 
- so shift the signifcand of the smaller number to the right until its corrected exponent mathes the larger number
- then comes addition of significands 
- the sum needs to be normalized
ex: ading 0.5 and -0.4375

0.5 = 1/2 = 1/2^1 = 0.1basetwo = 0.1basetwo * 2^0 = 1.000 * 2^-1
-0.4375 = -7/16 = -7/2^4 = - 0.0111 = -0.111 * 2^0 = -1.110 * 2^-2
- now the signifcand of number with lesser exponent, 2^-2, is shifted right until mathes larger number, therefore now -0.111 * 2^-1
- add the significands 1.000 * 2^-1 + (-0.111 * 2^-1) = 0.001 * 2^-1
- normalize it = 1.000 * 2^-4

- multiplcation: add exponenet of operands togheter, cannot add the biases as well, therefore subtract bias number of 127
- multiply out the singicands normally 
- normaliz the product. 
ex: 0.5 * -0.4375
 1.000two   2 1 by  1.110two   2 2
 -1 + -2 = -3 
 multiply signfancds ugly: 
 1.000two   1.110two
0000 1000
1000 1000
1110000two
, keep four digits so 1.110 * 2*03 
-since sign differs make the sign of the product negative. 
Floating-point addition, single (add.s) and addition, double (add.d)
■ Floating-point subtraction, single (sub.s) and subtraction, double (sub.d)
■ Floating-point multiplication, single (mul.s) and multiplication, double (mul.d)
■ Floating-point division, single (div.s) and division, double (div.d)
■ Floating-point comparison, single (c.x.s) and comparison, double (c.x.d), where x may be equal (eq), not equal (neq), less than (lt), less than or equal (le), greater than (gt), or greater than or equal (ge)
■ Floating-point branch, true (bc1t) and branch, false (bc1f)
-Mips designers user separtae floating pointe registers, included separate loads and stores for floating point numbers, lwcl and swc1. 
 lwc1      $f4,c($sp)  # Load 32-bit F.P. number into F4
    lwc1      $f6,a($sp)  # Load 32-bit F.P. number into F6
    add.s     $f2,$f4,$f6 # F2 = F4 + F6 single precision
    swc1      $f2,b($sp)  # Store 32-bit F.P. number from F2
-
float f2c (float fahr)
                {
                       return ((5.0/9.0) *(fahr – 32.0));
}

f2c:
  lwc1 $f16,const5($gp) # $f16 = 5.0 (5.0 in memory)
  lwc1 $f18,const9($gp) # $f18 = 9.0 (9.0 in memory)
  div.s $f16, $f16, $f18 # $f16 = 5.0 / 9.0
  lwc1 $f18, const32($gp)# $f18 = 32.0
  sub.s $f18, $f12, $f18 # $f18 = fahr – 32.0 Note: fahr was passed in f12.
  mul.s $f0, $f16, $f18 # $f0 = (5/9)*(fahr – 32.0)
  jr ra
 

- for every instruction first two steps are identical: send the program counter to memory that contains the code and fetch the instrucion from that memory 
- read one or two registers, using fields of the instructions to select the regersts to read. for the load word instructon, we need only one reigster, but for most we need two 
-then depends on function class 
- all instruction calsses except jump use the arhtmetic logic unit after reading reigsters. the memory refernece use ALU for an address calcultion, the arhtmetic logical instructions for the operation exectuion, andbranches for comparison.
- after ALU, differ on various instruction classes. 
- memory regerence intrsuction will need to access memory either to read data for a laord or write data to store. 
- an arthmetic logical or load instruction must write the data fro the ALU or memory back into regsiter. for bracnch instruction, may need to change next instruction address based on comparison, otehrisw PC should be incremented by 4 to get the address 
- cannot make data lines simply wired together, but instead must add a logic emelemnt that choeses among the multiple sources and steers one of those sources to its destination. done through a mulltierxer, which is more apt a data selector. 
- multiplexor selects from seveal inputs based on setting its control lines 
-several units also are controlled based on type of instruction. 
-all porgrams start in program counter to supply instruction address to instruction memory 
- after the isntruction is fetched, register operands used by instruction are specified by fields of that isntruction
- once the register operands have been fetched,they can be operated on to compute a memory address or arhtmetic result or compare result. if athetmic, alu must write to register. if operation ld, alu result is used as an address to either store a value or load a value from memory into registers
- the result from alu or memory is written back into resigter file. branches require use of alu ouput to determine the next instruction address, which comes from either the alu or from an adder which increments the current PC by 4. 
- data types elements consist of two different types of logic elements, those that operate on data values and elements that contain the state. elements that operate on data values are cominational. given same input, always output same output 
- ALU has no internal storage so always the same output 
- element contatins state elements like instruction and data memores as well as registers are state elements 
- state element has at least two inputs and one output. reuqired inputs are the data value to be writtein into the elment and the clock, which determins when the data value is written 
-one of simplest state elements is a Dtype flipflop, which has a value and a clock 
- the clock is used to determine when the state element should be written, a state element can be read at any time 
- logic componenets contain state are called sequenetial because outputs depend on both their inputs and the contents of the internal state .
-for example output of functional uint reprenseting registers depends both on the register numbers supplied and on what was written to registers previosuly 
- clocking methodology defines when signals can be read and when can be written 
-edgetriggered clocking methodology in which all state changes offur ona  clock edge (a quick transition from low to high or vice versa). inputs written in previous clock clycly,e and outputs in following clock cycle 
-control signal is a singal formultplexor sleection or for directing the operation of a functional unit, contrasts with a data signal which continas information that is operated o by a functional unit. 
- asserted is a logical high or true and dessarted is oposite. 
- both clock singal and write control signal are inputs, and the state element is chaned only when the write control signal is asserted and a clock edge occurs 
-an edgetrigged methodlogy alllows to read contents of a register, sned value through some cominbintaonal logic, and write that register in same clock cycle. 
- for mips 32, nearly all of these state and logic elements have inputs and ouuts 32 bits wide. figures wil indiciate buses which are singals wider than 1 bit. 
- we need first a memory unit to store instructions of a program and supply instrcutions to given address. program counter is the reigste rholding the address of current instruction, and need adder so that can increment PC to addresss of next insturction, the adder which is combintational can be built from the ALU simply by wiring control ines so the control always specifies an add operation 
- first fetch instruction from memory, increment counter to next intrsution 4 bytes later. 
- the r format instructions read two registers, perfrom an ALU operation on the contents of registers and wrte the result to a register, either R type instructions or athemticalogica operations. 
- the processers 32 general purpose registers care stored in register file which is a collection of registers inw hcih any register can be read or written by specifying the number of registe rin file . 
-r format instructions have three register oprands, two data words from reigser and write one data word into register file for each isntruction 
- for each data word to be read from registers, need an input to register file that specifics the register number to be read and an output register.
-the register file always outputs contents of whatever register numbers are on the read reigster inputs, write however are ontrolled by the write control signal, which must be asserted for a write to occur at clock edge 
- need a total of four inuts then with three reigster numbers and one for data and two outputs, both for data 
- register number inputs are 5 bits wide to specifiy of 32 registers whereas the data input and two data output buses are each 32 bits wide 
-- inputs carrying register number are 5 bytes wide but lines arraying data are 32 bits wide.  operation to be perfromed by ALU is controleld with ALU operation signal, whcih is 4 bits wide. 
- considerI type, these instructions compute a memory adress by adding base reigster to 16bit signed offset field continaed in the instruction 
- if instruction is a store, the value to be stored must also be read from the register file where it resies. if insturction is a load, the value read from memory bust be written into the register file in the specified register 
- need a unit to sign extend the 16 bit offset field in sintruction to a 32 bit offset field, and a data memory unti to read from or write from.
-data memory has read and write control signals, an address input, and an input for the data to be written into memory 
-beq has three operands, two regerds that are compare,d and 16bit offset used to compute branch target address. 
- must compute the branch target address by adding the sign extend (to increase the size of a data tiem by replicating the high order sign bit of the original data tiem in the high order bits of the larger, destination data item) of the instruction to the PC:
  1) instruction set archtiture speciifs that the base for the branch address calculation is the address of the isntruction, since we compute PC + 4, easy value as base for computing branch target address
  2) also states offset field is shifted left 2 bits so it is a word ofset, increases the effective range of the offset by a factor of 4 . thus will need to shift the offset field by 2
- when condition is tue, the branch target addres become sthe new PC and bracnh is taken, if not equal, the incremented PC should replace currenct PC.
- thus branch datapath must do two operations: compute the branch target address and compare registers. 
- needs the data memory unit is  a state element with inputs for adress and write data, and a single output for read result. separate read and write cotnrols, although only one may be asserted on any given clock. memory unit needs a read singla. sign extenton has a 16 bit input that is sing extened into a 32 bit result appearing on the oput. data memory is edge triggerd for writes. 
- the alu provdes an output signal indicates where result is zero, can send two register operands to ALU with control set to do a subtract. If zero signal is asserted, know they are equal .
-jump insturction oeprates by replacing the lower 28 bits of the PC with the lower 26 bits of instruction shopfted by 2 bits. Simply adding 00 to jump offset accomplishes this
-delayed branches when true, a delayed branch first executes the instruction immediately following the branch in sequential instruction order before jumping to the specified branch target address 
- differences between r time arhtmetic logical and memory instructions are arthemtic lgoical use the ALU ith inputs coming from the two reigstes. memory instruction also use ALU for address calcaultion, although second input is the sign extend 16 bit offset 
- value stored into a destination fromes from ALU for an r type or memory for a load. 
-to create datapath with only a single register file and single ALU, must support two different sources for the second ALU input, as well as two different sources for that data stored into the register file. thus one multiplexor is placed at the ALU input and nother at the data input to the register file 
- can create for datpath for instruction fetch, the data path for r type and memory instructions, and datapabth for branches 
- mips alu defines 6 combinations of four control inputs: and, or, add, sutract, set on less than, nor 
- for load word and store word we use the alu to compute the memory address by addition 
- for rtype alu performs first five, depdning on value of 6 bit function field in low order of bits. for branch equal, alu must perform a subtraction 
-can generate 4bit control input using small contril unit as inputs the function field of instruction and a 2 bit control field, called aluop
- ALUop indicates whether the operation to be performed should be add (00) for load and stroes, subtract (01) for bew, or detemined by operation (10) in funct field 
- output of ALU control unit is a 4bit signal that directlty controls the ALU be generating one of the 4 bit combintaitons 
- main control unit generates the ALUop bits, which are then used as input to ALU control that generates signals to control ALU. using multiple levels of control decreases file size and increases speed. 
- set control signals baed solely on the opcode field of instruction. PSCr is an exception and should be asserted if instruction is branch on equal and the zero output of the ALU which is used for equality comparison.
memtoreg -> register write data 
memwrite -> write data input 
memread -> data memory contnets designed by address are on read data output 
aluop -> aly controlalusrc -> goes to multipxpler 
pscrc - 
regdest -> goes to multiplexer before registers 
regwrite - goes to registers 
- input to control unit is the 6bit opcode field from the instruction
-the outputs of control unit conist of three 1 bit signals that are used to control mulplxiers (regdest, alusrc, memtoreg), three signals for controlling reads and writes in register file and data memory(regwrite, memread, memewrite), and 1 bit signal used to determine where branch (branch), and a 2 bit control signal for the ALU (aluop). an and gate is used to branch and Sero output from ALU, the and controls selection of next PC. 
1.instruction is fetched and PC incremented,
2. registers are read from register file, also main control unit computes the setting of control lines during this step
3. the ALU operates on the data read from the register file, using the function code (bits 5:0 funt field) to generate ALU function 
4. the result from the ALU is written into the register file using 15:11 of the instruction to select destination register 
# for add t1, t2, t3 
#for lw t1, offset(t2)
1. an instruction is fetched from memeory, and PC is incremented 
2. A register t2 value is read from the register file 
3. the ALU computesthe sum of the value read from register file and the signextended, lower 16 bits of the instruction (offset)
4. the sum from the ALU is used as the address for the data memory 
5. The data from the memory unit is written into the register file, the register destination is given by bits 20:16
#beq t1, t2, offset
1; An instruction is fetched from instruction memory, and PC is incremented
2. two registers t1 and t2 are read from register file 
3. the ALU performs a subtract on data values. THe PC + 4 is added to sign extend, lower 16 bits of the instruction offset shifted left by two to get branch target address
4. The zero result from the ALU is used to decide which adder result to store into the PC 
- setting of cntrol lines is completelt determing by opcode fields of instruction
- outputs are control lines, input is the 6bit opcode filed OP[5:0]
jump instruction computes targe PC and not coditional.
  - low order bits always 00. next twenty 26 bits are the immediatel field instruction, upper 4 bits are address should replace te PC + 4 
  - upper for 
  - load the longest thus single cycle design not proper (uses five: insturction memory, register file, ALU, data memory, and register file)
- piplinging is multiple instructions are overlapped in execution 
- hence pipling would ot decrease the time to complete one task, but when many tasks, the improvement in throughput decreases the total time to complete all tasks 
-classic five steps:
  1. fetched instruction from memory 
  2. read registers while decoding the instruction 
  3. execute operation or calcuate an address  
  4. access an operand in daata memory 
  5. write result into a register 

- time between instructionspiplined = timebetweeninstructionnonpipeleing / number of pipe stages 
-pipeline stage times lmited by slwest resocce, either the alu operation or meory access 
-pipinling increases intrusction throughput as opposed to decreaesing the execution time of an individual instruction 
- in mips all isnturctions are same length, restirction makes easy to fetch 
-  only has a few insturction formats, with soruce register fiels being located in same place in each instruction. thus symmetifc and can read gister at smae time derteming what type of instruction was fetched
- third memory operands only appear in loads or stores. can excute stage to calculate memory address and then access in following stage 
- fourth is operands must be algined in memory 
- three types of hazards when next instruction cannot execute in following clock cycle:
  1. structural hazard: when a planned isntruction did not excute because hardware does not support the combination of instructions that are set to execute 
  2. data hazard (pipeline data hazard): data that is needed to execture the instruction is not yet avaialble. don't need to wait though. as soon as ALU creates, we can supply as input for next operation. adding extra hardware to retreive the missing item early from intenral resoruces is called forwarding or bypassing. 
    - load use data hazard in which being loaded by a load instruction has not yet become availabe when it is needed by another isntruction . a pipeline stall but also a bubble:.
    a = b + e;
    c = b + e#assume all in memory
    lw t1, 0(t0)
    lw t2, 4(t0)
    lw t4, 8(t0)
    add t3, t1, t2 
    sw t3, 12(t0)
    add t5, t1, t4 
    sw t5, 16(t0)
    - control hazards arise from need to make decisin based on resuults of one intrscution (branch harazed) while others are exectuing 
    - computers use prediction to handle branches. always predict that branches will be untaken. can have some taken and untaken. 
    - dnyanic hardware predcitors make guesses based on behavior of each branch. can hae delayed decsicon as well, delayed branch alwaus excutes the next sequential instruction, with branch taking place after that one instruction delay. it is hidden rom mip. 
    - pipelingin explorts parallelism among instructins in sequential isnturctin stream, it is invisible. 
    - 

    if: instruction fetch 
    id: instruction decode and register file read 
    ex: execution or address calculation 
    mem: data memory access
    wb: write back 

    tow excpetion to left to right flow: the write back stage, which places result back into register file , or selection of next value of PC chosing between incremented PC and the branch address from the MEM stage 
    - right to left lead to data hazards (not really strucual) and second lead to control hazards 
    - 
- highight rgiht half of registers when being read and left half when written 
- instruction fetch, read from memory using address in PC and then placed in IF/ID pipplein reigster. PC address is incremented by 4 and written back into PC to be ready of rnext clock cycle. This incremented address is also saved in the IF/ID pipeline register in case needed later for beq..
- intrusction decfoe and filte resgister read: if/id pipeline register suplyies the 16 bit immediate field, which is  sign extened to 32 bits, and the register numbers to read the two registers. all three values are stored in the ID/ex pipeline register, along with incremented PC address. 
execute o raddress caclulation: load instruction reads contents of register 1 and signextended immediate from the ID/EX pipeline register and adds them to ALU. the sum is placed in the EX/MEM pipeline register 
- memory access: load instruction reading the data memory using the address from the EX/MEM pipeline register and loading the data into the MEM/WB pieplien register
- read data from MEM/WB pipieline register and write to register file 

for store:
instruction fetch: read from mmory using address in PC and placed in IF/ID pipleing 
- the instructin in IF/ID pipeline register supplies the register numbers for reading two registers and extends the siggn of the 16bit immediate. These three 32 bit values stores in the ID/EX pipeline register. 
Execute: the effective address placed in the EX/MEM pipeline 
Memory: Register containg the data to be stored was readed and stored in ID/EX. Only way to make data avaialbe during MEM stage is to place data into EX/MEM pipeline register in the EX stage.
write back: nothing hapens since every instruction behind the store is already in progress. 

- add control to pipelined datapath.
1.intrsuction fetch: control signals to read instruction memory and to write the PC are always asserted, nothing tocntrol.
2. Instruction decode: same thing happens everytime 
3. Execution: signals to be set are RegDst, ALUOp, and ALUSrc. SIgnals select the result regiseter and the ALU operation, and either read data 2 or a sign exteneded immediate for the ALU 
4. memory access: control lintes set in this stage are branch, memread, and memwrite. the branch equal, load, and store instructions set these signals. PCsrc selectes next sequential address unless control asserts Branch and the ALU result was 0.
5. Write back: control lines MemToReg which decides between sending the ALU result or memory value to register file, and RegWrite, which writes the chosen value 

- although complier generally relies upon the hardware to resolve hazards and therby ensure correct execution, complier must undersand the pipeline to acheive the best perfromance otherwise unexpected stalls will reduce the perofrmance of compiled code. 
