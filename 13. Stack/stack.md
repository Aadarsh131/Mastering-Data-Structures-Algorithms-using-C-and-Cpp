# Stack
implementation using-
- Array
- Linked List

**NOTE:** insert from the side where the time complexity remains `O(1)`

1. #### <u>using Array- </u> 
    > Implementations in-
    >- [basic C++ (from the tutorial)](./codes/stack.cpp)
    >- [C++ (from chatgpt)](./codes/stack_chatgpt.cpp)  
    >- [go](./codes/stack.go)

    > Important to know-  
    > [how to remove an item from a slice in go](./importants/remvoingFromSlice.go)
    
    
2. #### <u> using LinkedList-</u>  
    The time complexity would remain **O(1)**, if we insert from the *List head* side-
    <img src="./img resources/stackUsingLL.png">

    > Implementations in-
    >- [C++ (from tutorial)](./codes/stack_usingLL.cpp)
    >- [Go](./codes/stack_usingLL.go)

    > Important to know-  
    > [How OOM is working behing the scenes](./importants/oomKiller.md)

## Example Problems using Stack

#### 1. Paranthesis matching
- Basic solution
    - [C++](./codes/problem_solution/basicParanthesis.cpp)
- Solution (considering multiple paranthesis types)
    - [Go](./codes/problem_solution/paranthesis_multipleTypes.go)

#### 2. Infix to Postfix
- Basic solution
    - [C++](./codes/problem_solution/toPostfix.cpp)