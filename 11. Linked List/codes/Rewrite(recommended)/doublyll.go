package main

import "fmt"

type Node struct {
	data     int
	prevNode *Node
	nextNode *Node
}

type DoublyLinkedList struct {
	head *Node
}

func (DL *DoublyLinkedList) AddToHead(val int) {
	var node = Node{}
	node.data = val

	if DL.head == nil {
		DL.head = &node
		return
	}
	node.nextNode = DL.head
	DL.head.prevNode = &node
	DL.head = &node
}

func (DL *DoublyLinkedList) AddToEnd(val int) {
	var node = &Node{} // Or, *Node
	node.data = val

	var temp *Node = DL.head

	if temp == nil {
		DL.head = node
		return
	}

	for {
		if temp.nextNode == nil {
			temp.nextNode = node
			node.prevNode = temp
			return
		}
		temp = temp.nextNode
	}

}

func (DL *DoublyLinkedList) Display() {
	var temp *Node = DL.head
	for temp != nil {
		fmt.Print(temp.data, " ")
		temp = temp.nextNode
	}
}

func main() {
	var dll1 = DoublyLinkedList{}
	dll1.AddToHead(3)
	dll1.AddToHead(4)
	dll1.AddToEnd(4)
	dll1.AddToHead(8)
	dll1.AddToEnd(7)
	dll1.AddToHead(9)
	dll1.Display()
}
