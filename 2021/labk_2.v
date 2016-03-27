module labK;
reg[31:0] x, y, z;
  initial
    $monitor("%2d: x=%1d y=%1d z=%1d", $time, x, y, z); 

 initial
 begin
 repeat (4)
  #7 x = x + 1;
 
end 
  initial 
begin
  //$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z); 
  #10x = 5;
  //$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z); 
  y = x + 1;
  //$display("%2d: x=%1d y=%1d z=%1d", $time, x, y, z); 
  z = y + 1;
  #1 $finish;
end
endmodule