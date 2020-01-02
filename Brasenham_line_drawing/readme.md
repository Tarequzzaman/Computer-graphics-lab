<h3>Bresenham Line drawing algorithm<h3>
   
   
   
This algorithm is used for scan converting a line. It was developed by Bresenham

The method works as follows:
Assume a pixel P1'(x1',y1'),then select subsequent pixels as we work our may to the night, one pixel position at a time in the horizontal direction toward P2'(x2',y2').
   #Once a pixel in choose at any step
   #The next pixel is
Either the one to its right (lower-bound for the line)
One top its right and up (upper-bound for the line)
The line is best approximated by those pixels that fall the least distance from the path between P1',P2'.

