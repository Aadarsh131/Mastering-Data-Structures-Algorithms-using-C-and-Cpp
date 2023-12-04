package main

import (
	"fmt"
)

type Stack struct {
	arr []int // since, slice stores a ref to underlying array, we dont need to explicitly use an "array" with a fixed size before compile time, "slice" is doing the exact same thing for us here
	//also, it will handle the capacity for us at runtime, it actually is working like a "vector" in c++
	top int
}

func main() {
	stack := Stack{}
	stack.top = -1
	//we dont need to scan for size also here
	fmt.Println(stack)
	stack.push(2)
	stack.push(6)
	stack.push(5)
	stack.push(4)
	stack.push(1)
	fmt.Println(stack.pop())
	stack.display()
	fmt.Println(stack.peek(3))
	fmt.Println(stack.removeItemAtPos(3))
	stack.display()
}
func (s *Stack) push(item int) {
	s.arr = append(s.arr, item)
	s.top += 1
}

func (s *Stack) pop() (int, error) {
	if len(s.arr) == 0 {
		return 0, fmt.Errorf("Stack is empty")
	}

	popedItem := s.arr[s.top]
	s.arr = s.arr[:s.top]
	s.top--
	return popedItem, nil
}

func (s *Stack) removeItemAtPos(pos int) (int, error) {
	if pos <= 0 {
		return 0, fmt.Errorf("cannot be index zero or negative number")
	} else if pos > s.top+1 {
		return 0, fmt.Errorf("cannot remove item beyond the stack size")
	} else {
		//removing top-pos+1
		index := s.top - pos + 1
		removedItem := s.arr[index]
		s.arr = append(s.arr[:index], s.arr[index+1:]...)
		s.top--
		return removedItem, nil
	}
}

//stack way of peeking
func (s *Stack) peek(pos int) (int, error) {
	if pos <= 0 {
		return 0, fmt.Errorf("cannot be index zero or negative number")
	} else if pos > s.top+1 {
		return 0, fmt.Errorf("cannot peek beyond the stack size")
	} else {
		return s.arr[s.top-pos+1], nil
	}
}

//stack way of displaying
func (s *Stack) display() {
	for i := len(s.arr) - 1; i >= 0; i-- {
		fmt.Print(s.arr[i], " ")
	}
	fmt.Print("\n")
}
