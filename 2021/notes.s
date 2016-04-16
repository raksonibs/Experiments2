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