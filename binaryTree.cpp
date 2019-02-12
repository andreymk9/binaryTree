#ifndef Bt
#define Bt
#include <iostream>
#include "binaryTree.h"

template <class T>
binaryTree<T>::binaryTree(const binaryTree& obj){
    root = new Node;
    root->key = obj.root->key;
    root->val = obj.root->val;
    ++tSize;
    copy(obj.root);
}

template <class T>
binaryTree<T>::binaryTree(binaryTree&& obj){
    root = new Node;
    root->key = obj.root->key;
    root->val = obj.root->val;
    ++tSize;
    copy(obj.root);
    obj.clear();
}

template <class T>
void binaryTree<T>::insert(const T& val){
    if(tSize == 0){
        root = new Node;
        root-> val = val;
        root-> key = 1;
        ++tSize;
    }
    else{
        ++tSize;
        Node* ptr = new Node;
        ptr-> key = tSize;
        ptr-> val = val;
        compare(ptr, root);
    }
}

template <class T>
int binaryTree<T>::search(const T& val){
    Node* ptr = root;
    while(ptr-> val != val && ptr != nullptr){
        if(val >= ptr->val)
            ptr = ptr->right;
        else ptr = ptr->left;
    }
    return ptr->key;
    
}

template <class T>
void binaryTree<T>::clear(){
    remove(root);
    root = new Node;
    tSize = 0;
}

template <class T>
void binaryTree<T>::erase(const T& val){
   Node* ptr = root;
    while(ptr-> val != val && ptr != nullptr){
        if(val >= ptr->val)
            ptr = ptr->right;
        else ptr = ptr->left;
    }
    if(ptr->left == nullptr && ptr->right == nullptr){
        if(ptr->parent->left == ptr){
            ptr->parent->left = nullptr;
            delete ptr;
        }
        if(ptr->parent->right == ptr){
            ptr->parent->right = nullptr;
            delete ptr;
        }
    }
    else if(ptr->left != nullptr && ptr->right == nullptr){
            if(ptr->parent->left == ptr){
                ptr->parent->left = ptr->left;
                delete ptr;
            }
            if(ptr->parent->right == ptr){
                ptr->parent->right = ptr->left;
                delete ptr;
            }
    }
        else if(ptr->left == nullptr && ptr->right != nullptr){
                if(ptr->parent->left == ptr){
                    ptr->parent->left = ptr->right;
                    delete ptr;
                }
                if(ptr->parent->right == ptr){
                    ptr->parent->right = ptr->right;
                    delete ptr;
                }
        }
            else if(ptr->left != nullptr && ptr->right != nullptr){
                    Node* p = ptr;
                    p = p->right;
                    while(p->left != nullptr){
                        p = p->left;
                    }
                    if(p->right != nullptr && p->parent == ptr){
                        p->parent->right = p->right;
                    }
                    if(p->parent != ptr){
                        p->parent->left = nullptr;
                    }
                    if(p->right != nullptr && p->parent != ptr){
                        p->parent->left = p->right;
                    }
                    ptr->val = p->val;                        
                    delete p;
            }
}

template <class T>
void binaryTree<T>::print(){   // inorder traversal
    inTraversal(root);
}

template <class T>
binaryTree<T>& binaryTree<T>::operator= (const binaryTree<T>& obj){
    if(this == &obj)
        return *this;
    clear();
    root = new Node;
    root->key = obj.root->key;
    root->val = obj.root->val;
    ++tSize;
    copy(obj.root);
}

template <class T>
binaryTree<T>& binaryTree<T>::operator= (binaryTree<T>&& obj){
    if(this == &obj)
        return *this;
    clear();
    root = new Node;
    root->key = obj.root->key;
    root->val = obj.root->val;
    ++tSize;
    copy(obj.root);
    obj.clear();
}

#endif