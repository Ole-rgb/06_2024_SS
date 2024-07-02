/*
Compile: 
javac -cp .:prog1javalib.jar IsSearchTree.java
Run:
java -cp .:prog1javalib.jar IsSearchTree
Compile and run:
javac -cp .:prog1javalib.jar IsSearchTree.java && java -cp .:prog1javalib.jar IsSearchTree
*/

import prog1.base.Base;

class SearchTreeNode {
    public int value;
    public SearchTreeNode left, right;

    public SearchTreeNode(SearchTreeNode left, int value, SearchTreeNode right) {
        this.left = left;
        this.value = value;
        this.right = right;
    }

    public SearchTreeNode(int value) {
        this.value = value;
        left = null;
        right = null;
    }

}

class SearchTree {

    private SearchTreeNode root = null;
    
    public SearchTree() { }

    public SearchTree(SearchTreeNode root) {
        this.root = root;
    }

    public String toString() {
        return toStringRec(root);
    }

    private String toStringRec(SearchTreeNode n) {
        if (n == null) {
            return "E";
        } else {
            return "Node(" + toStringRec(n.left) 
                    + ", " + n.value + ", "
                    + toStringRec(n.right) + ")";
        }
    }
    
    /** Returns true if this is a search tree. Returns false otherwise.
      * May need a helper method. */
    public boolean isSearchTree() {
        return false; // todo: implement
    }
    
}

public class IsSearchTree {

    public static SearchTreeNode n(int value) {
        return new SearchTreeNode(value);
    }
    
    public static SearchTreeNode n(SearchTreeNode left, int value, SearchTreeNode right) {
        return new SearchTreeNode(left, value, right);
    }

    public static void test() {
        SearchTree t = new SearchTree();
        Base.checkExpect(t.isSearchTree(), true);
        
        t = new SearchTree(n(100));
        Base.checkExpect(t.isSearchTree(), true);
        
        t = new SearchTree(n(n(100), 101, n(102)));
        Base.checkExpect(t.isSearchTree(), true);
        
        t = new SearchTree(n(n(101), 100, n(99)));
        Base.checkExpect(t.isSearchTree(), false);
        
        t = new SearchTree(n(n(101), 100, n(199)));
        Base.checkExpect(t.isSearchTree(), false);
        
        t = new SearchTree(n(n(11), 100, n(99)));
        Base.checkExpect(t.isSearchTree(), false);
        
        t = new SearchTree(n(n(n(25), 50, n(75)), 100, n(n(125), 150, n(175))));
        Base.checkExpect(t.isSearchTree(), true);
        
        t = new SearchTree(n(n(n(55), 50, n(75)), 100, n(n(125), 150, n(175))));
        Base.checkExpect(t.isSearchTree(), false);
        
        t = new SearchTree(n(null, 101, n(100)));
        Base.checkExpect(t.isSearchTree(), false);
        
        t = new SearchTree(n(n(50), 100, null));
        Base.checkExpect(t.isSearchTree(), true);

        Base.summary();
    }
            
    public static void main(String[] args) {
        test(); 
    }

}
