package main

import "fmt"

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	head *Node
}

func (ll *LinkedList) InsertAtHead(data int){
	newNode := &Node{data: data}
	newNode.next = ll.head
	ll.head = newNode
}

func (ll *LinkedList) InsertAtEnd(data int){
	newNode := &Node{data:data}

	if ll.head == nil{
		ll.head = newNode
		return
	}

	curr := ll.head
	for curr.next != nil {
		curr = curr.next
	}
	curr.next = newNode
}

func (ll *LinkedList) Search(target int) bool {
	curr := ll.head
	for curr != nil {
		if curr.data == target {
			return true
		}
		curr = curr.next
	}
	return false
}

func (ll *LinkedList) Delete(data int) {
	if ll.head == nil {
		return
	}

	if ll.head.data == data {
		ll.head = ll.head.next
		return
	}

	curr := ll.head

	for curr.next != nil{
		if curr.next.data == data{
			curr.next = curr.next.next
			return
		}
		curr = curr.next
	}
}

func (ll *LinkedList) Print(){
	curr := ll.head

	for curr != nil {
		fmt.Print(curr.data," -> ")
		curr = curr.next
	}
	fmt.Println("nil")
}

func main(){
	ll := &LinkedList{}

	ll.InsertAtHead(3)
	ll.InsertAtHead(1)
	ll.InsertAtHead(5)

	ll.Print()

	fmt.Println(ll.Search(3))

	ll.Delete(3)
	ll.Print()

}
