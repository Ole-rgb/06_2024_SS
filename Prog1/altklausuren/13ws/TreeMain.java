class TreeMain{
	
	public static TreeNode root; 	

	
	public static void main(String[] args){
		root = new TreeNode(9);
		root.left = new TreeNode(14);
		root.left.left = new TreeNode(10);
		root.left.right = new TreeNode(8);
		root.left.right.left = new TreeNode(7);
		root.left.right.left.left = new TreeNode(1);
		root.left.right.left.right = new TreeNode(2);
		root.right = new TreeNode(15);
		root.right.left = new TreeNode(3);
		root.right.right = new TreeNode(4);
		root.right.right.left = new TreeNode(5);
		root.right.right.right = new TreeNode(6);
		
		TreePrint.treePrint();
	}
}