module Lab7_part2;
 reg [31:0] x, y, z;
 initial
 begin
#10x = 5;
$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z);
#10y = x + 1;
$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z);
#10z = y + 1;
$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z);
$finish;
 end
 endmodule