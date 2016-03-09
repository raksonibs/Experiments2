module labK;
reg a, b, c;
wire x, y, z, notc, lowerc, lowerx, lowery;

not my_not (notc, c);
and my_and (x, a, lowerc);
and my_and2 (y, c, b);
or my_or (z, lowerx, lowery);

assign lowerc = notc;
assign lowery = y;
assign lowerx = x;

initial
begin
         a = 1; b = 0; c = 0;
        $monitor("a=%b, b=%b, c=%b, x=%b; y=%b, z=%b",a, b, c, x, y, z);
        $finish;
end

initial
begin 
    a = 1; b = 0; c = 0;                    
    $monitor("a=%b, b=%b, c=%b, x=%b; y=%b, z=%b",a, b, c, x, y, z);
    $finish; 
end
endmodule