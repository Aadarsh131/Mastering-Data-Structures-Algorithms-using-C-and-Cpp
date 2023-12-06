package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type Stack struct {
	head *Node
}

func (s *Stack) push(val int) {
	// var newNode *Node = stack.head
	//OR
	newNode := &Node{}
	newNode.data = val

	if s.head == nil {
		s.head = newNode
		return
	}

	newNode.next = s.head
	s.head = newNode
}

func (s *Stack) Display() {
	temp := s.head
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.next
	}
}

func (s *Stack) pop() {
	temp := s.head

	if temp == nil{
		fmt.Println("Stack is already empty")
		return
	}
	if temp.next == nil{
		s.head = nil
		return
	}

	for temp.next.next != nil {
		temp = temp.next
	}
	temp.next = nil
}

func main() {
	// var head *Node
	//OR
	s1 := Stack{}
	s1.push(3)
	s1.push(4)
	s1.push(9)
	s1.Display()
	fmt.Print("\n")

	s1.pop()
	s1.pop()
	s1.Display()
}
