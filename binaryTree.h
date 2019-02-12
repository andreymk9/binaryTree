
template<class T>
class binaryTree{    
    public:
        struct Node{
            int key;
            T val;
            Node* left = nullptr;
            Node* right = nullptr;
            Node* parent = nullptr;
        };
        binaryTree(const binaryTree& val);
        binaryTree(binaryTree&& val);
        binaryTree() :root(nullptr),tSize(0){}
        ~binaryTree() {remove(root);}
        void clear();
        void insert(const T& val);
        void erase(const T& val);
        int search(const T& val);
        void print(); // inorder traversal
        binaryTree<T>& operator= (const binaryTree<T>& obj);
        binaryTree<T>& operator= (binaryTree<T>&& obj); 
    private:
        int tSize = 0;
        Node* root;
        void compare(Node* ptr, Node* current){
            if(current->val >= ptr->val && current->left == nullptr){
                ptr->parent = current;
                current->left = ptr;
            }
            else{ 
                if(current->val >= ptr->val && current->left != nullptr)
                    compare(ptr, current->left);
                else{
                    if(current->val < ptr->val && current->right == nullptr){
                        ptr->parent = current;
                        current->right = ptr;
                    }
                    else{
                        if(current->val < ptr->val && current->right != nullptr)
                            compare(ptr, current->right);   
                    }        
                }
            }
        }
        void inTraversal(Node* ptr){
            if(ptr == nullptr)
                return;
            inTraversal(ptr->left);
            std::cout<<ptr->val<<" ";
            inTraversal(ptr->right);
        }
        void remove(Node* ptr){
            if(ptr == nullptr)
                return;
            remove(ptr->left);
            if(ptr->right == nullptr)
                delete ptr;
            remove(ptr->right);
        }
        void copy(Node* ptr){
            if(ptr == nullptr)
                return;
            copy(ptr->left);
            if(root->key != ptr->key)
                insert(ptr->val);
            copy(ptr->right);
        }
};
