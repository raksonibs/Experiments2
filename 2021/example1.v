module example1(a,b,c,z);
  input a,b,c;

  //input [1:0] a, b if mux and two into
  // if mux output has to be output [1:0] z;
  wire tmp;
  output z;
  //output z, c;

  assign tmp = ~a & c;
  assign z = ~tmp ^ b;

  endmodule


  module yMux1(z,a,b,c);

    output z;
    input a,b,c;
    wire tmp, tmp2;

    assign tmp = ~c & a;
    assign tmp2 = c & b;
    assign z = tmp | tmp2;
  endmodule


module yMux2(z,a,b,c);
  parameter SIZE = 2;
  output[SIZE - 1:0] z;
  input[SIZE - 1:0] a,b;
  input c;
  yMux1 mine[1:0](z, a, b, c);
endmodule

