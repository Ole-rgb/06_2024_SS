/*
Compile: 
javac -cp .:prog1javalib.jar NodesEqualToParent.java
Run:
java -cp .:prog1javalib.jar NodesEqualToParent
Compile and run:
javac -cp .:prog1javalib.jar NodesEqualToParent.java && java -cp .:prog1javalib.jar NodesEqualToParent
*/

import prog1.base.Base;

class Node {
    public int value;
    public Node left, right;

    public Node(Node left, int value, Node right) {
        this.left = left;
        this.value = value;
        this.right = right;
    }

    public Node(int value) {
        this.value = value;
        left = null;
        right = null;
    }

}

class Tree {

    private Node root = null;
    
    public Tree() { }

    public Tree(Node root) {
        this.root = root;
    }

    public String toString() {
        return toStringRec(root);
    }

    private String toStringRec(Node n) {
        if (n == null) {
            return "E";
        } else {
            return "Node(" + toStringRec(n.left) 
                    + ", " + n.value + ", "
                    + toStringRec(n.right) + ")";
        }
    }
    
    /** Returns the number of nodes that have the same value as their parent node. 
      * May need a helper method. */
    public int numberOfNodesThatAreEqualToTheirParent() {
        return 0; // todo: implement
    }
    
}
    
public class NodesEqualToParent {       

    public static Node n(int value) {
        return new Node(value);
    }
    
    public static Node n(Node left, int value, Node right) {
        return new Node(left, value, right);
    }

    public static void test() {
        Tree t = new Tree();
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 0);
        
        t = new Tree(n(100));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 0);
        
        t = new Tree(n(n(99), 100, n(100)));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 1);
        
        t = new Tree(n(n(100), 100, n(100)));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 2);
        
        t = new Tree(n(n(101), 100, n(100)));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 1);
        
        t = new Tree(n(n(n(25), 50, n(75)), 100, n(n(125), 150, n(175))));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 0);
        
        t = new Tree(n(n(n(0), 0, n(0)), 
                    0, 
                    n(n(0), 0, n(0))));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 6);
        
        t = new Tree(n(null, 100, n(100)));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 1);
        
        t = new Tree(n(null, 100, n(99)));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 0);
        
        t = new Tree(n(n(100), 100, null));
        Base.checkExpect(t.numberOfNodesThatAreEqualToTheirParent(), 1);
        
        Base.summary();
    }

    public static void main(String[] args) {
        test();
    }

}
