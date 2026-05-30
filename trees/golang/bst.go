package main

import "fmt"

type Node struct {
	data int
	left *Node
	right *Node
}

type BST struct {
	root *Node
}

func insert(root *Node,val int) *Node {
	if root == nil {
		return &Node{data:val}
	}

	if val < root.data {
		root.left = insert(root.left,val)
	}else{
		root.right = insert(root.right,val)
	}
	return root
}

func (bst *BST) Insert(val int){
	bst.root = insert(bst.root,val)
}

func search(root *Node,target int) bool {
	if root == nil {
		return false
	}

	if target == root.data {
		return true
	}else if target < root.data{
		return search(root.left,target)
	}else{
		return search(root.right,target)
	}

}

func (bst *BST) Search(val int) bool {
	return search(bst.root,val)
}

func findMin(root *Node) *Node {
	for root.left != nil {
		root = root.left
	}
	return root
}

func deleteNode(root *Node,val int) *Node {
	if root == nil {
		return root
	}

	if val < root.data {
		root.left = deleteNode(root.left,val)
	}else if val > root.data{
		root.right = deleteNode(root.right,val)
	}else{
		// no child or one child
		if root.left == nil {
			return root.right
		}
		if root.right == nil {
			return root.left
		}

		// both child nodes present
		// delete inorder successor
		minNode := findMin(root.right)
		root.data = minNode.data
		root.right = deleteNode(root.right,minNode.data)
	}
	return root
}

func (bst *BST) Delete(val int){
	bst.root = deleteNode(bst.root,val)
}

func inorder(root *Node){
	if root == nil {
		return
	}
	inorder(root.left)
	fmt.Print(root.data," ")
	inorder(root.right)
}

func main(){
	bst := &BST{}

	bst.Insert(5)
	bst.Insert(3)
	bst.Insert(7)
	bst.Insert(2)
	bst.Insert(4)

	fmt.Print("Inorder: ")
	inorder(bst.root)
	fmt.Println()

	fmt.Println("Search 4: ",bst.Search(4))
	bst.Delete(3)

	fmt.Print("After delete: ")
	inorder(bst.root)
}
