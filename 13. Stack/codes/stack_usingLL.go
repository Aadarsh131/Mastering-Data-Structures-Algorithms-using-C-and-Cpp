package main

type Node struct {
	data int
	next *Node
}

func (n *Node) Insert(val int) {
	var newNode *Node
	newNode.data = val

}

func main() {
	var head *Node
	//OR
	// head := Node{}

	head.data = 4
	head.next = nil

}
