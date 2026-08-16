class Solution {
public:
    Node* intersect(Node* a, Node* b) {
        if (a->isLeaf) {
            if (a->val)
                return new Node(true, true);
            return b;
        }

        if (b->isLeaf) {
            if (b->val)
                return new Node(true, true);
            return a;
        }

        Node* tl = intersect(a->topLeft, b->topLeft);
        Node* tr = intersect(a->topRight, b->topRight);
        Node* bl = intersect(a->bottomLeft, b->bottomLeft);
        Node* br = intersect(a->bottomRight, b->bottomRight);

        if (tl->isLeaf && tr->isLeaf &&
            bl->isLeaf && br->isLeaf &&
            tl->val == tr->val &&
            tl->val == bl->val &&
            tl->val == br->val) {
            return new Node(tl->val, true);
        }

        return new Node(true, false, tl, tr, bl, br);
    }
};