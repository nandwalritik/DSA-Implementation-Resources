package main

import "fmt"

type Node struct {
	data int
	left *Node
	right *Node
}

func buildTree() *Node {
	root := &Node{data:1}

	root.left = &Node{data:2}
	root.right = &Node{data:3}

	root.left.left = &Node{data:4}
	root.left.right= &Node{data:5}

	return root
}

func inorder(root *Node){
	if root == nil {
		return
	}
	inorder(root.left)
	fmt.Print(root.data," ")
	inorder(root.right)
}

func preorder(root *Node){
	if root == nil {
		return
	}
	fmt.Print(root.data," ")
	preorder(root.left)
	preorder(root.right)
}


func postorder(root *Node){
	if root == nil {
		return
	}

	postorder(root.left)
	postorder(root.right)
	fmt.Print(root.data," ")
}

func main() {
	root := buildTree()

	fmt.Print("Inorder: ")
	inorder(root)
	fmt.Println()

	fmt.Print("Preorder: ")
	preorder(root)
	fmt.Println()

	fmt.Print("Postorder: ")
	postorder(root)
	fmt.Println()
}
