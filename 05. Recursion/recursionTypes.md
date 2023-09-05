# 5 types of recursion

1. Tail recurison
2. Head recurison
3. Tree recurison
4. Indirect recurison
5. Nested recurison

### 1. Tail recursion
```cpp
void fun(int n)
{
    if(n>0)
    {
        printf("%d",n);
        fun(n-1); //when there is no statement after the recursive function call, then it is tail recursion
    }
}
```
> Time complexity: **O(n)**  
> Space complexity: **O(n)**


> Same above tail recursion example can be converted into loop, that would be more memory efficient, like this- 
>```cpp
>void fun(int x)
>{
>   while(n>0)
>    {
>       printf("%d",n);
>       n--; 
>    }  
>}
>```
> Time complexity: **O(n)**  
> Space complexity: **O(1)** (constant space)  
>
> **NOTE:** *some modern compilers internally converts (in its code optimization phase) the Tail recursion codes into its corresponding loop version to reduce the space usage*

### 2. Head recursion
```cpp
void fun(int n)
{
    if(n>0)
    {
        fun(n-1);//if the recursive function call is at the head(no statements above it), and there are some statements presents after it, then it is Head recursion
        printf("%d",n);
    }
}
```
> We can convert it into loop, but the method might not be straightforward as in Tail recursion