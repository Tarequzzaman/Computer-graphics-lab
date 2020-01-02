<h3>Bresenham Line drawing algorithm<h3>
   
   
   
<p>This algorithm is used for scan converting a line. It was developed by Bresenham<p>
<p>The method works as follows:<p>
                             Assume a pixel P1'(x1',y1'),then select subsequent pixels as we work our may to the night, one pixel position at a time in the horizontal direction toward P2'(x2',y2').
   1. Once a pixel in choose at any step
   2. The next pixel is
               2.1  Either the one to its right (lower-bound for the line)
               2.2  One top its right and up (upper-bound for the line)
The line is best approximated by those pixels that fall the least distance from the path between P1',P2'.

