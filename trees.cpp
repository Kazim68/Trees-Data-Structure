#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Node {
    public:
        string data;
        Node* left;
        Node* right;

        Node(string d){
            data = d;
            left = NULL;
            right = NULL;
        }
};


class Tree{
    public:
        Node* root;

        Tree(){
            root = NULL;
        }
        Tree(Node* n){
            root = n;
        }   

        // printing the tree using preorder traversal
        void depthFirstApproach(){
            stack<Node*> s;
            s.push(root);

            while (!s.empty()){
                    Node *current = s.top();
                    s.pop();

                    if (current->right){
                        s.push(current->right);
                    }
                    if (current->left){
                        s.push(current->left);
                    }
                    cout << current->data << "-->";
            }
        }

        // return an array in depth first order

        // iterative approach
        vector<string> depthFirstValues(){

            if (root == NULL){
                return vector<string>();
            }

            vector<string> result;
            stack<Node*> s;

            s.push(root);

            while (!s.empty()){
                Node* current = s.top();
                s.pop();

                if (current->right){
                    s.push(current->right);
                }
                if (current->left){
                    s.push(current->left);
                }

                result.push_back(current->data);
            }

            return result;
        }

        // recursive approach
        vector<string> depthFirstValuesRecursive(Node* current){
            vector<string> result;

            if (!current)
                return result;

            vector<string> left = depthFirstValuesRecursive(current->left);
            vector<string> right = depthFirstValuesRecursive(current->right);

            result.push_back(current->data);

            for (int i = 0; i < left.size(); i++){
                result.push_back(left[i]);
            }

            for (int i = 0; i < right.size(); i++){
                result.push_back(right[i]);
            }
            
            return result;
        }
};

int main(){
    Node* a = new Node("a");
    Node *b = new Node("b");
    Node *c = new Node("c");
    Node *d = new Node("d");
    Node *e = new Node("e");
    Node *f = new Node("f");

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

        //     a
        //    / \
        //   b   c
        //  / \   \ 
        // d   e   f

    Tree t(a);

    vector<string> temp = t.depthFirstValuesRecursive(t.root);

    for (int i = 0; i < temp.size(); i++){
        cout << temp[i] << "-->";
    }


    return 0;
}