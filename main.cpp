#include <iostream> 
#include "ArrayList.h"
#include "LinkedList.h"
#include <typeinfo>
#include "HashTable.h"
#include "BTSNode.h"
using namespace std; 
int main(){
    ArrayList<int> list; 
    list.append(54);
    list.append(22);
    list.append(31); 
    list.append(46);
    list.append(5); 
    list[0] = 1; 
    list.mergeSort(); 
    cout << list << endl; 

    // ArrayList<int> other; 
    // other.append(6);
    // other.append(7);
    // other.append(8); 
    // other.append(9); 
    // other.append(10); 
    // bool x = (list == other); 
    
    // list+(other); 
    // list.reverse(); 
    // cout << list << endl; 
    // list.quick_sort();
    // cout << list << endl;

    // list = other; 
    

    // cout << list << endl; 
    
    // list.selection_sort(); 

    // LinkedList<int> x; 
    // x.append(1);
    // x.append(2);
    // x.append(3); 

    // cout << x << endl; 
    
    // HashTable<int> y(10); 
    // y.add(0); 
    // y.add(1);
    // y.add(50);
    // y.add(3); 
    // y.add(100); 


    // cout << y << endl; 

    // BSTNode z; 
    return 0; 
}