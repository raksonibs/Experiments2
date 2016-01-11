2.7
  - MIPS asembly has similiar to if with a go to.
    - beq register1, register2, L1 (go to statement lb if value in register1 equals register2)
    - bne register1, register 2, l1 (go to L! if register1 and register2 not equal)
    ex: if (i == j) f = g + h; else f = g - h;
      -compiled: bne $s3,$s4, Else // go to Else if i =/ j -> code is more efficent if we test the optioopiste coniditon to branch over that performs the subeqestn then part of the if (the label Else is defined below).
        - then: add $so,$s1,$s2 \\ f = g + h (skipped if i =/ j)

3.1
  - digits added bit by bit ex: 7 = 0111 + 6 = 0110 == 13 = 1101
  -add, addi, and sub cause excpetions on overlfow
  - addu, addiu, and subu do not cause excpetions on overflow
  -overflow occurs when the result from an operation cannot be reperesented with the hardware. the sum cannot be larger than the operands. since the operands fit in 32 bits and the sum is no larger than an operand, the sum must fit in 32 bits as well.overflow when adding two positive numebers and the sum is negative, or when adding two negative numbers and the result is positive.         