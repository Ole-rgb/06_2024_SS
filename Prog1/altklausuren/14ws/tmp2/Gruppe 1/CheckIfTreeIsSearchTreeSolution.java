class Node
{
	int value;
	Node left;
	Node right;
	
	public Node(int v)
	{
		value = v;
		left = null;
		right = null;
	}
	
	public Node (Node l, int v, Node r)
	{
		value = v;
		left = l;
		right = r;
	}
}

class Tree
{
	public Node root = null;
	
	public Tree()
	{
		
	}
	
	//Diese Methode implementieren
	public boolean checkIfTreeIsSearchTree()
	{	
		return (root != null ? check(root) : true);
	}
	
	public boolean check(Node n)
	{
		if (n.left != null && n.right != null)
		{
			if (n.value > n.left.value && n.value <= n.right.value)
				return check(n.left) && check(n.right);
			else
				return false;
		}
		else if (n.left != null)
		{
			if (n.value > n.left.value)
				return check(n.left);
			else
				return false;
		}
		else if (n.right != null)
		{
			if (n.value > n.right.value)
				return check(n.right);
			else
				return false;
		}
		else
			return true;
	}
	
}

public class CheckIfTreeIsSearchTreeSolution
{
	public static void main(String [] args)
	{
		Tree test0 = new Tree();
		if (test0.checkIfTreeIsSearchTree() == true)
			System.out.println("Test passed!");
		else
			System.out.println("Test failed!");
		
		Tree test1 = new Tree();
		test1.root = new Node( new Node( new Node( 1 ) , 2 , null ) , 5 , new Node(6) );
		if (test1.checkIfTreeIsSearchTree() == true)
			System.out.println("Test passed!");
		else
			System.out.println("Test failed!");
		
		Tree test2 = new Tree();
		test2.root = new Node( new Node( new Node( 1 ) , 2 , null ) , 0 , new Node(6) );
		if (test2.checkIfTreeIsSearchTree() == false)
			System.out.println("Test passed!");
		else
			System.out.println("Test failed!");
		
		Tree test3 = new Tree();
		test3.root = new Node( new Node( new Node( new Node(0), 1, null ) , 2 , null ) , 5 , new Node(6) );
		if (test3.checkIfTreeIsSearchTree() == true)
			System.out.println("Test passed!");
		else
			System.out.println("Test failed!");
	}
}






