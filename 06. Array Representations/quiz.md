
### Multi-dimentional array values/address can be found using pointer dereferencing like this (NOTE: the formula and concept is very different from array of pointers)-

> General pattern **(to get the address of the array items)**-` *(X+a)+b` , where a is the row number and b is column number 
>
> General pattern **(to get the value of the array items)**-` *(*(X+a)+b)` , where a is the row number and b is column number 
>
>For 2D Array:  `*(*(X+a)+b)` will dereference ***( NOTE: n number of `*` for `nD` array to dereference)*** and the actual integer data value will be the output
>
> **NOTE:** `X` and `*X` will both output the address of the 0th row and 0th column, for `2D` array, because it require 2 `*` to deference the 2D array values (to dereference the `nD` array value, it requires n number of `*`) but we only had 1. So, `**X` will dereference and will actually output the integer value in our case
 

<img src='./res/q2.png'>