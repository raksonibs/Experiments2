module Lab7_Part3;
 reg a, b, c, flag; // reg without size means 1-bit
 wire tmp, z;
 not my_not(tmp, b);
 and my_and(z, a, tmp);
initial
 begin
flag = $value$plusargs("a=%b", a);
flag = $value$plusargs("b=%b", b);
flag = $value$plusargs("c=%b", c);
$display("a=%b b=%b z=%b", a, b, z);
 $finish;
end
endmodule