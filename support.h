#ifndef SUPPORT_H
#define SUPPORT_H

#include <iostream>
#include <stdexcept>
#include "BTSNode.h"

BSTNode* insert_helper(BSTNode* root, int value, BSTNode* parent){
    if(root == nullptr){
        root = new BSTNode(value, parent);
    }
    else{
        if(value < root->data){
            root->left = insert_helper(root->left, value, root); 
        }
        else{
            root->left = insert_helper(root->right, value, root); 
        }
    }
    return root; 
}

BSTNode* insert(BSTNode* root, int value){ // O(n)
    return insert_helper(root, value, nullptr); 
}

void traverse(BSTNode* root){
    if(root != nullptr){
        traverse(root->left);
        std::cout << root->data << std::endl;
        traverse(root->right); 
    }
}

BSTNode* search(BSTNode* root, int value){//time complexity is O(log(n))
    if(root != nullptr){
        if(root->data == value){
            return root; 
        }
        else{
            if(value < root->data){
                return search(root->left, value); 
            }
            else{
                return search(root->right, value); 
            }
        }
    }
    else{
        return nullptr; 
    }
}
#endif