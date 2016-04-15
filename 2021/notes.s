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
sw $t0,48(s3)