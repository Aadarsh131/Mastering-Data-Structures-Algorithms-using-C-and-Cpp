Lets suppose we have this dangerous code, we'll see its not so dangerous as we thought until we are bare metal. 
```cpp
Node *newNode = new Node;
while (true)
{
    newNode = new Node; //should throw and error (for memory overflow case) in this infinte loop, but it doesn't, because of the OOM killer (out of memory killer) implemented in the linux
    std::cout << newNode->data;
}
```
   >Surpringly!!! `newNode` will always point to a valid data, meaning it is never a `nullptr`, but how is that possible?  
   >That is happening because of the `OOM killer` (I am on linux btw) of the linux (maybe different term for different OS).
   >
   >
   >So, what I just saw that my CPU usage was not going above 99.8%, infact it is fluctuating frequently revolving around 99.6% to 99.8%, this might be an example of OOM killer helping us not to go out of bound memory (making sure the pointer always stores a valid data), and so the `new` (which should throw execption error when heap is full) is never coming across the memory overflow case and hence we see no exception being thrown.
   >
   >Ofcouse, now if we are bare metal with no OS, we would see the compiler throw that error.

