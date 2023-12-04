package main

import "fmt"

type Node struct {
	data int
	next *Node
}

func main() {
	// head := Node{}
	//OR
	var head *Node

	(*head).data = 6
	(*head).next = nil

	fmt.Println(&head)
}
