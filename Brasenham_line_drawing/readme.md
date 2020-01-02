<h3>Bresenham Line drawing algorithm</h3>
   
   
   
<p>This algorithm is used for scan converting a line. </p>
 
<p>The idea of Bresenham’s algorithm is to avoid floating point multiplication and addition to compute mx + c, and then computing round value of (mx + c) in every step. In Bresenham’s algorithm, we move across the x-axis in unit intervals.</p>
<p>1. We always increase x by 1, and we choose about next y, whether we need to go to y+1 or remain on y. In other words, from any position (Xk, Yk) we need to choose between</p>

- Either the one to its right (lower-bound for the line)
- One top its right and up (upper-bound for the line)
 (Xk + 1, Yk) and (Xk + 1, Yk + 1).

<div align="center">

<img src="https://media.geeksforgeeks.org/wp-content/uploads/BresenhamLine.png"/>

</div>

<p>2. We would like to pick the y value (among Yk + 1 and Yk) corresponding to a point that is closer to the original line.</p>

<p>For details visit <a href="https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/">here</a></p>