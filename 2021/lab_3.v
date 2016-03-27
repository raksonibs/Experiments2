module Lab7_3;
  reg a,b;
  wire tmp, z;
  not my_not(tmp, b);
  and my_and(z,a,tmp);

initial
begin
  a = 1;
  b = 1;
  $display("a=%b b=%b z=%b", a, b, z);
  $finish;
end
endmodule
