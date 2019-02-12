#include <iostream>
#include "binaryTree.cpp"

int main(){
    binaryTree<int> t;
    t.insert(50);
    t.insert(90);
    t.insert(30);
    t.insert(10);
    t.insert(40);
    t.insert(45);
    t.insert(85);
    t.erase(30);
    int k = t.search(10);
    t.print();
    binaryTree<int> p;
    p = t;
    std::cout<<std::endl;
    p.print();
    std::cout<<std::endl<<k;
    return 0;
}
           

                
              
