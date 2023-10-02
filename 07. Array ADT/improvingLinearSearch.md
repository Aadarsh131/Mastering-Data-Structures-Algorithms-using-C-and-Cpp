# 2 methods of improving the linear search

- there's a high probability of searching for the same book tommorow that you have searched today- this same ideology is taken here to improve the searchings
  
  ## 1. Transposition
  > Every time you search for 1 element, it is moved 1 step closer from the start index **(slow reduction is time complexity for next same search)**

  > In Transposition, if the element is not searched, we can predict that, it is slowly moving back(becuase other elements are moving closer)

     pseudocode-
  ```cpp
  for(int i=0; i<length; i++)
  {
    if(element == A[i])
    {
        swap(A[i], A[i-1]);
        return i-1; //index
    }
  }
  ```

  ## 2. Move to Front/Head
  > Once the element is searched move it to the first index **(sudden/constant change in time complexity for next same search)**
    
    pseudocode-
  ```cpp
  for(int i=0; i<length; i++)
  {
    if(element == A[i])
    {
        swap(A[i], A[0]);
        return 0; //index
    }
  }
  ```
