Some important terms:
1.Root 		:-Node with no parents.
2.Edge 		:-refers to the link from parent to child
3.leaf Node :-node with no children
4.depth of node  :-length of path from root to x.
				 			or
				    No. of edges in path from root to x.

5.Height of Node :-	No. of edges in longest path from node to a leaf.
-------------------------------Binary trees-----------------------
1.Binary trees :- A tree in which each node can have at most two children.

2.Strict/Proper Binary tree :- each node can have 0 or 2 children

3.Complete Binary tree :- All levels except possibly the last are completely filled and all nodes are as left as possible.

4.Perfect Binary tree  :- All levels are completely filled.

5.Binary Search Tree   :- A BT in which for each node value of all the nodes in left subtree is lesser or equal in comparison to the value of all the nodes in right subtree is greater. 


three types of traversal:
			1,2,3 are depth first type and 4 is breath first type
1.Preorder (DLR) Traversal
2.Inorder (LDR) Traversal    //Whenever we perform inorder traversal on binary search tree we get output in sorted order

3.Postorder (LRD) Traversal
4.Level Order Traversal: This method is inspired from Breadth First Traversal (BFS of Graph algorithms).

gfg articles link :- https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/;

Post-In-Pre  //
 
 PostOrder : left,right,root

 Inorder   : left,root,right

 PreOrder  : root,left,right 
 
 


 DELETE NODE FROM TREE:-


  case 1 : Node to be deleted is leaf
  	Simply remove from the tree
  case 2 : Node to be deleted has only one child
  	copy the child to the node and delete the child
  case 3 : Node to be deleted has two children
  	1.Find inorder successor of the node.
  	2.Copy contents of inorder successor to the node.
  	3.Delete inorder successor.
  	(#####NOTE:-Inorder predecessor can also be used#####)
  	INORDER SUCCESSOR :- The node that comes immediately after given node in Inorder traversal of the tree.

//Generic Trees 
	/*
		user defined datatype that contains 
		struct genericTrees{
			int data;
			genericTrees *firstChild;
			genericTrees *nextSibling;
		}
	*/
//Threaded Binary Trees

Binnary Search Trees
  imp Notes:
    1.Inorder Traversal produces sorted list
    2.BST can only be constructed with (Pre or Post or Level)*order traversal.
    3.We can always get inorder traversal by sorting the only given traversal.
    4.Number of unique BSTs with n distinct keys is Catalan Number(Read this from gfg quite an interesting thing regarding fibonacci number)

  questions/operations that can be performed on BST
    1.Searching an element
    2.Find MIN
    3.Find MAX
  Lowest Common Ancestor.//See this its and imp question  
  INORDER predecessor and Successor
    X has two children then its inorder predecessor is the maximum value in its left subtree and its inorder successor the minimum value in its right 		subtree.
    If it does not have a left child, then a node’s inorder predecessor is its first left ancestor.
  Inserting and Deleting elements from BST 
    1.inserting ke liye code dekho just easy
	2.Deleting ke liye three cases:
		1.Find location of element which you want to delete
		case 1 : If element == leafNode
				return NULL ***TO ITS PARENT***
			//Above point just means that make the corresponding pointer NULL.
		case 2 : If element has one child
			send that child to the parent of node that is to be deleted.
		case 3 : If element has both children
			1.Replace the key of this node with largest element of the left subtree.
			2.Recurssively delete the node which is now empty.
			3.
				 		
						
#################################################################    AVL TREES   ########################################################
four cases 
  Single rotation :
                    left left
                    right right
  Double rotation :
                    right left :- 1.rotateRight  2.rotateLeft
                    left right :- 1.rotateLeft   2.rotateRight
###########################################################################################################################################
  checking a given tree is binary search tree or not
  set upperBound = +infinity
  set lowerBound = -infinity
  if we go left then range changes to lowerBound to  node.data
  if we go right then range changes to node.data to upperBound
  CODE
  bool isBST(Node *root,int min,max){
  	if(root == NULL)
  		return true;
  	if(root->data < min || root->data > max)
  		return false;
  	return isBST(root->left,min,root->data) && isBST(root->right,root->data,max);		
  }               
                    
                                       

