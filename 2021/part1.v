module labK;
 reg [31:0] x; // a 32-bit 
 reg [0:0] one; // a 32-bit 
 reg [1:0] two; // a 32-bit 
 reg [2:0] three; // a 32-bit register
 initial
 begin
 $display("time = %5d, x = %b", $time, x);
 x = 32'hffff0000; 
 one = &x; 
 two = x[1:0];
 three = {one, two};
 $display("time = %5d, x = %b", $time, x);
 x = x + 2;
 $display("time = %5d, x = %b", $time, x);
 $finish;
end
 endmodule