module oracle_test;
  reg a,b,c,expect;
  wire z;
  integer i,j,k;
  example1 my_example(a,b,c,z);
  flag = $value$plusargs("a=%b", a);
  //to grab user input reg flag would be necessary;
  %h or %d for hexadecimal
  initial
    begin
    for (i =0;i<2;i++) 
      begin 
      for (j=0; j<2;j++)
        begin
        for (k=0; k<2;k++)
          begin
           a=i;b=j;c=k;
           expect = ~(~a&c) ^ b;
           #1
           if (expect === z) 
            $display("PASS a=%b b=%b c=%b z=%b",a,b,c,z);
          else
            $display("FAIL a=%b b=%b c=%b z=%b",a,b,c,z);
        end
      end
    end
  $finish;
  end
endmodule











module oracle_tester;
  reg a,b,c, expect;
  integer i,j,k;
  wire z;
  example1 my_example(a,b,c,z);

  initial
  begin

  a=i;b=j;c=k;
  expect = ~a();
  #1
  if (z === expect)

  end
  ed



  module example1(a,b,c,z);
    input a,b,c;
    ouput z;
    wire tmp;
    assign tmp;
    assign z;




    addiu t1, zero, 4;
    addiu t2, zero, 5;
    subu t3, t2, t1;
    div t3, t2
    mfhi t5;
    mflo t6;