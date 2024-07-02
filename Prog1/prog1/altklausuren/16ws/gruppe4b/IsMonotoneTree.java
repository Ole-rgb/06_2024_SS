/*
Compile and run:
javac -cp .:prog1javalib.jar IsMonotoneTree.java && java -cp .:prog1javalib.jar IsMonotoneTree
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

    public void insert(int v) {
       if(value < v) {
            if(right != null) {
                right.insert(v);
            } else {
                right = new Node(v);
            }
       } else {
            if(left != null) {
                left.insert(v);
            } else {
                left = new Node(v);
            }
       }
    }


    public boolean isMonotone() {
        if(left != null && right != null) {
            if(value > left.value || value > right.value) {
                return false;
            } else {
                return left.isMonotone() && right.isMonotone();
            }
        } else if(left != null) {
            if(value > left.value) {
                return false;
            } else {
                return left.isMonotone();
            }
        } else if(right != null){
            if(value > right.value) {
                return false;
            } else {
                return right.isMonotone();
            }
        }
        return true;
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

    public boolean isMonotone() {
        if(root == null) {
            return true;
        } else {
            return root.isMonotone();
        }
    }

}

public class IsMonotoneTree {

    public static Node n(int value) {
        return new Node(value);
    }
    
    public static Node n(Node left, int value, Node right) {
        return new Node(left, value, right);
    }

    public static void test() {
        Tree t = new Tree();

        t = new Tree();
        Base.checkExpect(t.isMonotone(), true);

        t = new Tree(n(null, 100, null));
        Base.checkExpect(t.isMonotone(), true);

        t = new Tree(n(n(50), 24, n(25)));
        Base.checkExpect(t.isMonotone(), true);

        t = new Tree(n(n(50), 100, null));
        Base.checkExpect(t.isMonotone(), false);

        t = new Tree(n(n(n(55), 50, n(75)), 20, n(n(125), 150, n(175))));
        Base.checkExpect(t.isMonotone(), false);

          t = new Tree(n(n(n(55), 50, n(75)), 20, n(n(151), 150, n(175))));
        Base.checkExpect(t.isMonotone(), true);

        Base.summary();
    }
            
    public static void main(String[] args) {
        test(); 
    }

}
