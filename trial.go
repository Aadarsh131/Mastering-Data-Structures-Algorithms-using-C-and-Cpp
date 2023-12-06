package main

import "fmt"

type Node struct {
	data int
	next *Node
}

//LinkedList Class
type LinkedList struct {
	headNode *Node
}

func (L *LinkedList) AddToHead(val int) {
	var node = Node{}
	node.data = val
	if L.headNode != nil {
		node.next = L.headNode
	}
	L.headNode = &node
}

func (L *LinkedList) AddToEnd(val int) {
	var node = Node{}
	var temp = L.headNode

	node.data = val
	if temp == nil {
		L.headNode = &node
		return
	}

	for {
		if temp.next == nil {
			temp.next = &node
			break
		}
		temp = temp.next
	}
}

func (L *LinkedList) Display() {
	var temp *Node = L.headNode
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.next
	}
}

func main() {
	var ll1 = LinkedList{}
	ll1.AddToHead(3)
	ll1.AddToHead(5)
	ll1.AddToHead(9)
	ll1.AddToEnd(1)
	ll1.AddToEnd(54)
	ll1.AddToHead(0)
	ll1.Display()
}
