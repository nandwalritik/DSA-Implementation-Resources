package main

import "fmt"

type Node struct{
	data int
	next *Node
	prev *Node
}

type DoublyLinkedList struct {
	head *Node
	tail *Node
}

func (dll *DoublyLinkedList) InsertAtHead(val int){
	newNode := &Node{data:val}

	if dll.head == nil {
		dll.head = newNode
		dll.tail = newNode
		return
	}

	newNode.next = dll.head
	dll.head.prev = newNode
	dll.head = newNode

}

func (dll *DoublyLinkedList) InsertAtTail(val int){
	newNode := &Node{data:val}

	if dll.tail == nil {
		dll.head = newNode
		dll.tail = newNode
		return
	}

	dll.tail.next = newNode
	newNode.prev = dll.tail
	dll.tail = newNode
}

func (dll *DoublyLinkedList) Delete(data int){
	curr := dll.head

	for curr != nil {
		if curr.data == data{

			// Case 1 head
			if curr.prev == nil {
				dll.head = curr.next
				if dll.head != nil {
					dll.head.prev = nil
				} else {
					dll.tail = nil
				}
				return
			}

			// Case 2 tail
			if curr.next == nil {
				dll.tail = curr.prev
				dll.tail.next = nil
				return
			}

			// Case 3 middle node
			curr.prev.next = curr.next
			curr.next.prev = curr.prev
			return
		}
		curr = curr.next
	}
}

func (dll *DoublyLinkedList) Search(data int) bool {
	curr := dll.head
	for curr != nil {
		if curr.data == data {
			return true
		}
		curr = curr.next
	}
	return false
}

func (dll *DoublyLinkedList) PrintForward(){
	curr := dll.head
	for curr != nil {
		fmt.Print(curr.data," <-> ")
		curr = curr.next
	}
	fmt.Println("nil")
}

func (dll *DoublyLinkedList) PrintBackward(){
	curr := dll.tail
	for curr != nil {
		fmt.Print(curr.data," <-> ")
		curr = curr.prev
	}
	fmt.Println("nil")
}

func main(){
	dll := DoublyLinkedList{}

	dll.InsertAtHead(2)
	dll.InsertAtHead(1)
	dll.InsertAtTail(3)
	dll.InsertAtTail(4)

	dll.PrintForward()
	dll.PrintBackward()

	dll.Delete(3)
	dll.PrintForward()

}
