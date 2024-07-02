## 1a)

    int count(string s, char c)
{
    int l = 0, max = 0;
    char a;
    while (a = *(s++))
    {
        if (a == c)
            l++;
        else
            l = 0;
        if (l > max)
            max = l;
    }
    return max;
}

## 1b) (Bonus)

    int isdigit(string s)
{
    return (s[s_length(s) - 1] >= '0' && s[s_length(s) - 1] <= '9');
}

## 2)

    class Node
{
    Node right;
    Node left;
    int value;

### a)

    	public int sum()
{
    int ret = this.value;
    if (this.left != null)
        ret += this.left.sum();
    if (this.right != null)
        ret += this.right.sum();
    return ret;
}

### b)

    	public int minSubTree()
{
    int min = this.sum();
    if (this.left != null)
    {
        int minleft = this.left.minSubTree();
        if (minleft < min)
            min = minleft;
    }
    if (this.right != null)
    {
        int minright = this.right.minSubTree();
        if (minright < min)
            min = minright;
    }
    return min;
}
}

// 2)

class Node
{
    Node right;
    Node left;
    int value;

### a)

    public int sum()
{
    int ret = this.value;
    if (this.left != null)
        ret += this.left.sum();
    if (this.right != null)
        ret += this.right.sum();
    return ret;
}

### b)

    public int maxSubTree()
{
    int max = this.sum();
    if (this.left != null)
    {
        int maxLeft = this.left.maxSubTree();
        if (max < maxLeft)
            max = maxLeft;
    }
    if (this.right != null)
    {
        int maxRight = this.right.maxSubTree();
        if (max < maxRight)
            max = maxRight;
    }
    return max;
}
}

bool
contains(string s, string t)
{

    int pos = 0;

    for (int i = 0; i < s_length(s); i++)
    {

        if (pos == s_length(t) - 1 || t[0] == '\0')
        {
            return true;
        }

        if (s[i] == t[pos] || t[pos] == '?')
        {
            pos++;
        }
        else
        {
            pos = 0;
        }
    }

    return false;
}