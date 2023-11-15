#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <string>
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

        // breadth first approach
        // iterative approach
        vector<string> breadthFirstValuesIterative(){
            vector<string> result;
            queue<Node*> q;

            q.push(root);

            while(!q.empty()){
                Node* current = q.front();
                q.pop();

                if (current->left){
                    q.push(current->left);
                }
                if (current->right){
                    q.push(current->right);
                }

                result.push_back(current->data);
            }

            return result;
        }

        bool treeIncludes(string value){
            if (!root) return false;

            queue<Node*> q;
            q.push(root);

            while(!q.empty()){
                Node *current = q.front();
                q.pop();

                if (current->data == value){
                    return true;
                }

                if (current->left){
                    q.push(current->left);
                }

                if (current->right){
                    q.push(current->right);
                }
            }

            return false;
        }

        // recursive approach
        bool treeIncludesRecursive(Node* current, string value){
            if (!current) return false;

            if (current->data == value){
                return true;
            }

            return treeIncludesRecursive(current->left, value) || treeIncludesRecursive(current->right, value);
        }

        // calculate sum
        // iterative approach
        int sumIterative(){
            if (!root)
                return 0;
            
            queue<Node*> q;
            q.push(root);

            int sum = 0;
            Node* current = root;

            while (!q.empty()){
                current = q.front();
                q.pop();

                sum += stoi(current->data);

                if (current->left){
                    q.push(current->left);
                }

                if (current->right){
                    q.push(current->right);
                }

            }

            return sum;
        }

        // recursive approach
        int sumRecursive(Node* current){
            if (!current){
                return 0;
            }
            return stoi(current->data) + sumRecursive(current->left) + sumRecursive(current->right);
        }

        // find max
        // iterative approach
        int maxIterative(){
            if (!root){
                return 0;
            }

            queue<Node *> q;
            q.push(root);

            int max = INT16_MIN;

            while (!q.empty()){
                Node *current = q.front();

                if (stoi(current->data) > max){
                    max = stoi(current->data);
                }

                q.pop();

                if (current->left){
                    q.push(current->left);
                }

                if (current->right){
                    q.push(current->right);
                }

            }

            return max;
        }

        // recursive approach
        int maxRecursive(Node* current){
            if (!current){
                return INT16_MIN;
            }

            int max = stoi(current->data);
            int leftMax = maxRecursive(current->left);
            int rightMax = maxRecursive(current->right);

            if (leftMax > max){
                max = leftMax;
            }

            if (rightMax > max){
                max = rightMax;
            }

            return max;
        }

        // find min
        // iterative approach
        int minIterative(){
            if (!root){
                return 0;
            }
            
            int min = INT16_MAX;

            queue<Node*> q;
            q.push(root);

            while (!q.empty()){
                Node* current = q.front();

                if (stoi(current->data) < min){
                    min = stoi(current->data);
                }

                q.pop();

                if (current->left){
                    q.push(current->left);
                }

                if (current->right){
                    q.push(current->right);
                }
            }

            return min;
        }

        // recursive approach
        int minRecursive(Node* current){
            if (!current){
                return INT16_MAX;
            }

            int min = stoi(current->data);
            int leftMin = minRecursive(current->left);
            int rightMin = minRecursive(current->right);

            if (leftMin < min){
                min = leftMin;
            }

            if (rightMin < min){
                min = rightMin;
            }

            return min;
        }

        // max sum of a path
        // recursive approach
        int maxSum(Node* current){
            if (!current){
                return 0;
            }
            if (!current->left && !current->right){
                return stoi(current->data);
            }

            int leftMax = maxSum(current->left);
            int rightMax = maxSum(current->right);

            if (leftMax > rightMax){
                return stoi(current->data) + leftMax;
            } else {
                return stoi(current->data) + rightMax;
            }
        }

        // inserting into binary search tree
        // iterative approach
        Node* insertIterative(string val){
            if (!root){
                return new Node(val);
            }

            Node* temp = root;

            while(temp){
                if (stoi(val) > stoi(temp->data)){
                    if (!temp->right){
                        temp->right = new Node(val);
                        return root;
                    }
                    temp = temp->right;
                }
                else{
                    if (!temp->left){
                        temp->left = new Node(val);
                        return root;
                    }
                    temp = temp->left;
                }
            }
        }

        // recursive approach
        Node* insertRecursive(Node* current, string val){
            if (!current){
                return new Node(val);
            }

            if (stoi(val) > stoi(current->data)){
                current->right = insertRecursive(current->right, val);
            } else {
                current->left = insertRecursive(current->left, val);
            }

            return current;
        }

        // deleting a node
        Node* deleteNode(Node* current, string val){
            if (!current)
                return current;

            if (stoi(val) > stoi(current->data)){
                current->right = deleteNode(current->right, val);
            }
            else if (stoi(val) < stoi(current->data)){
                current->left = deleteNode(current->left, val);
            }
            else{
                if (!current->left){
                    return current->right;
                }
                else if (!current->right){
                    return current->left;
                }
                else{
                    Node* temp = current->right;
                    while (temp->left){
                        temp = temp->left;
                    }
                    current->data = temp->data;
                    current->right = deleteNode(current->right, temp->data);
                }
            }
            return current; 
        }

};

int main(){
    Node* a = new Node("1");
    Node *b = new Node("2");
    Node *c = new Node("3");
    Node *d = new Node("4");
    Node *e = new Node("5");
    Node *f = new Node("6");

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

    t.deleteNode(t.root, "3");

    vector<string> result = t.breadthFirstValuesIterative();

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << "-->";
    }

    return 0;
}