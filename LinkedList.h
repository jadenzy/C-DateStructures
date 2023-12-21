#ifndef LINDED_LIST_H
#define LINDED_LIST_H

#include <ostream>
#include <stdexcept>
#include "Node.h"

template <class T> 
struct LinkedList{
    Node<T>* head; 

    LinkedList(){
        head = nullptr; 
    }

    //copy constructor 
    LinkedList<T>(const LinkedList<T>& other){ 
        if(other.head == nullptr){
            head = nullptr; 
        }
        Node<T>* temp; 
        temp->data = other.head->data;  
        temp->next = nullptr; 
        head = temp; 
        Node<T>* secondTemp = head; 
        Node<T>* copy = other.head->next; 
        while(copy != nullptr){
            secondTemp->next->data = copy->data; 
            secondTemp->next->next = nullptr; 
            secondTemp = secondTemp->next; 
            copy = copy->next; 
        }
    }

    void prepend(T value){
        if (head == nullptr){
            head = new Node<T>(value);
        }
        else{
            Node<T>* temp = new Node<T>(value); 
            temp->next = head; 
            head = temp; 
        }
    }

    void append(T value){
        if (head == nullptr){               
            head = new Node<T>(value);         
        }
        else{                               
            Node<T>* temp = new Node<T>(value);   

            Node<T>* last = head;              
            while (last->next != nullptr){  
                last = last->next;
            }

            last->next = temp;            
        }
    }

    bool search(T value){
        Node<T>* temp = head; 
        while(temp != nullptr){
            if(temp->data == value)
                return true; 
            temp = temp->next; 
        }
        return false; 
    }

    int getPos(T value){
        int position = 0;
        Node<T>* temp = head; 
        while(temp->data != value){
            temp = temp->next; 
            position++; 
            if(temp->data == value){
                return position; 
            }
        }
        throw std::invalid_argument("the value is not in the list");
    }

    void removeFirst(){
        Node<T>* temp = head; 
        head = head->next; 
        delete temp; 
    }

    void removeLast(){
        Node<T>* temp = head; 
        while(temp->next->next != nullptr){
            temp = temp->next; 
        }
        delete temp->next; 
        temp->next = nullptr; 
    }

    void removeByValue(T value){
        Node<T>* temp = head; 
        Node<T>* prev = nullptr; 
        if(temp != nullptr && temp->data == value){
            head = temp->next; 
        }
        else{
            while(temp != nullptr && temp->data != value){
                prev = temp;
                temp = temp->next; 
            }
            if(temp == nullptr){
                throw std::invalid_argument("The value is not in the list");
            }
        }
    }

    void insert(T value, int index){
        if(head == nullptr){
            head = new Node<T>(value); 
        }
        else{
            if(index == 0){
                Node<T>* temp = new Node<T>(value); 
                temp->next = head; 
                head = temp; 
            }
            else{
                Node<T>* val = new Node<T>(value);
                int count = 0; 
                Node<T>* rest = head;
                Node<T>* before = head;
                while(count != index - 1){
                    before = before->next; 
                    count++; 
                }
                int countR = 0;
                while(countR != index){
                    rest = rest->next; 
                    countR++; 
                }
                before->next = val; 
                val->next = rest; 
            }
        }
    }   

    void reverse(){
        Node<T>* current = head;
        Node<T>* prev = nullptr;
        Node<T>* next = nullptr; 

        while(current != nullptr){
            next = current->next; 
            current->next = prev;
            prev = current; 
            current = next; 
        }
        head = prev; 
    }

    ~LinkedList(){
        Node<T>* temp = head; 
        while(head != nullptr){
            head = head->next;
            delete temp;
            temp = head; 
        }
    }
}; 

template <class T>
std::ostream& operator << (std::ostream& os, LinkedList<T>& list){
    Node<T>* current = list.head; 
    while(current != nullptr){
        os << current->data << " ";
        current = current->next; 
    }
    return os; 
}

#endif

