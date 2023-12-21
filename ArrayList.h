#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream> 

template <class T> 
struct ArrayList{
    T* data; //data list 
    int count; //the number of elements stores 
    int capacity; //the capacity of the list 

public: 
    //default constructor 
    ArrayList(){
        capacity = 1; 
        count = 0;
        data = new T[capacity]; 
    }
    //default constructor with input capacity 
    ArrayList(int capacity){
        this->capacity = capacity;
        count = 0;
        data = new int[capacity];
    }
    //function uses to clean not used capacity if element < capacity / 2 
    void CleanMemory(){
        if(count < capacity /2){
            capacity /=2;
            T* temp = new T[capacity];
            for(int i = 0; i < count; i++){
                temp[i] = data[i]; 
            }

            T* oldData = data;
            data = temp;
            delete[] oldData; 
        }
    }
    //copy constructor 
    ArrayList<T>(const ArrayList<T>& other){
        count = other.count;
        capacity = other.capacity; 
        data = new T[capacity]; 
        for(int i =0; i < count; i++){
            data[i] = other.data[i]; 
        }
    }
    //append a value at the end of the list and double the capacity if neccessory 
    void append(T value){
        data[count] = value; 
        count++;

        if(count == capacity){
            int oldCapacity = capacity; 
            capacity *= 2; 
            T* temp = new T[capacity];
            for(int i = 0; i < oldCapacity; i++){
                temp[i] = data[i]; 
            }
            T* oldlocation = data; 
            data = temp;
            delete[] oldlocation; 
        }
    }
    //add a value to the front of the list 
    void prepend(T value){
        append(value); 
        for(int i = count - 1; i > 0; i--){
            data[i] = data[i-1]; 
        }
        data[0] = value; 
    }
    //remove the first element 
    void removeFirst(){
        if(count > 0){
            count --; 
            for(int i = 0; i < count; i++){
                data[i] = data[i+1]; 
            }
        }
        else{
            throw std::invalid_argument("List is Empty"); 
        }
        this->CleanMemory(); 
    }
    //remove the last element 
    void removeLast(){
        if(count > 0){
            count --; 
            data[count] = 0; 
        }
        else{
            throw std::invalid_argument("List is Empty"); 
        }
        this->CleanMemory(); 
    }
    //remove an element by its index 
    void removeByIndex(int index){
        if(count > 0 && index >= 0 && index < count){
            count--; 
            data[index] = 0;
            for(int i = index; i < count; i++){
                data[i] = data[i+1]; 
            }
        }
        else{
            throw std::invalid_argument("Either List is Empty or '"+ std::to_string(index) +"' is not a valid index"); 
        }
        this->CleanMemory();
    }
    // remove an element by its value 
    void removeByValue(T value){
        int index = 0;
        for(int i = 0; i < count; i++){
            if(data[i] == value){
                index = i;
                break; 
            }
            else{
                throw std::invalid_argument("Can not find value '" + std::to_string(value) + "'"); 
            }
        }
        removeByIndex(index); 
    }
    // insert a value at a specific index 
    void insert(int index, T value){
        if(index >=0 && index < count){
            append(value);
            int j = count - 1;
            while(j > index){
                data[j] = data[j - 1];
                j--;
            }
            data[index] = value;
        }
        else{
            throw std::invalid_argument("'"+ std::to_string(index) +"' is not a valid index");
        }
    }
    // return the value at the index 
    T& get(int index) const{
        return data[index];
    }
    // reverse the list 
    void reverse(){
        for(int i = 0; i < count/2; i++){
            T temp = data[i];
            data[i] = data[count - i - 1];
            data[count - i - 1] = temp; 
        }
    }

    //===== operators ======//
    // [] operator 
    T& operator[](int index){
        if(index >=0 && index < count){
            return data[index];
        }
        else{
            throw std::invalid_argument("'"+ std::to_string(index) +"' is not a valid index");
        }
    }
    // equal = operator 
    ArrayList<T>& operator=(const ArrayList<T>& other){
        count = other.count;
        if (capacity != other.capacity){
            capacity = other.capacity; 
            T* old = data; 
            data = new T[capacity];
            delete[] old; 
        } 
        for(int i = 0; i < capacity; i++){
            data[i] = other.data[i]; 
        }
        return *this; 
    }
    // + operator, add two list together 
    ArrayList<T>& operator+(const ArrayList<T>& other){
        int totalCount = count + other.count; 
        T* temp = new T[capacity + other.capacity]; 
        for(int i = 0; i < count; i++){
            temp[i] = data[i]; 
        }
        int j = 0; 
        for(int i = count; i < totalCount; i++){
            temp[i] = other.data[j]; 
            j++; 
        }
        this->data = temp; 
        this->count = totalCount;
        this->capacity = capacity + other.capacity; 
        return *this; 
    }
    // == operator, compare two list 
    // Also compare the capacity 
    bool operator==(const ArrayList<T>& other){
        if(this->count != other.count){
            return false; 
        }
        else if(this->capacity != other.capacity){
            return false; 
        }
        else{
            for(int i = 0; i < count; i++){
                if(data[i] != other.data[i]){
                    return false; 
                }
            }
        }
        return true; 
    }
    
    //================= Searching =================//
    bool linear_search(const T& value){
        for(int i = 0; i < count; i++){
            if(data[i] == value){
                return true;
            }
        }
        return false; 
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while(left < right){
            int mid = (left + right) / 2;
            if(data[mid] == value){
                return true;
            }
            else if(data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1; 
            }
        }
        return false; 
    }
    //================ END SEARCHING ==============//

    //================== SORTING ==================//
    void selection_sort(){
        if(typeid(data[0]) != typeid(0)){
            throw std::invalid_argument("The list is not int type");
        }
        else{
            for(int i = 0; i < count; i++){
                T minVal = data[i];
                int minPos = i;  
                for(int j = i; j < count; j++){
                    if(data[j] < minVal){
                        minVal = data[j];
                        minPos = j;
                    }
                }
                T temp = data[i];
                data[i] = data[minPos];
                data[minPos] = temp; 
            }
        }
    } //The best time complexity is O(n^2), the average is O(n^n), and the worst is O(n^2)

    void insertion_sort(){
        if(typeid(data[0]) != typeid(0)){
            throw std::invalid_argument("The list is not int type");
        }
        else{
            for(int i = 0; i < count; i++){
                int j = i; 
                while(j > 0 && data[i-1] > data[j]){
                    T temp = data[j];
                    data[j] = data[j-1]; 
                    data[j-1] = temp; 
                    j--; 
                }
            }
        }
    }// The best time complexity is O(n), and the average is O(n^2), the worst is O(n^2) which is the list is reverse-sorted list

    //==== quick sort ====// 
    private:
    int partition(int start, int end){
        T pivot = data[start]; 
        int count = 0;
        for(int i = start + 1; i <= end; i++){
            if(data[i] <= pivot){
                count++; 
            }
        }

        int pivotIndex = start + count; 

        T temp = data[start];
        data[start] = data[pivotIndex]; 
        data[pivotIndex] = temp;

        int left = start; 
        int right = end; 

        while(left < pivotIndex && right > pivotIndex){
            while(data[left] <= data[pivotIndex]){
                left++;
            }
            while(data[right] >= data[pivotIndex]){
                right--; 
            }
            if(left < pivotIndex && right > pivotIndex){
                T temp = data[left];
                data[left] = data[right];
                data[right] = temp; 
            }
        }
        return pivotIndex; 
    }
    void helper_Quick_Sort(int start, int end){
        if(start >= end)
            return; 
        int p = partition(start, end); 
        helper_Quick_Sort(start, p - 1);
        helper_Quick_Sort(p + 1, end);
    }
    public: 
    void quick_sort(){
        if(typeid(data[0]) != typeid(0)){
            throw std::invalid_argument("The list is not int type");
        }
        helper_Quick_Sort(0, count - 1); 
    }//Best Time complexity is O(nlog(n)), average is O(nlog(n)), the worst is O(n^2) which include sorted and reverse-sorted list 
     // This also depends on the position of hte pivot 
    // ================== END QUICKSORT ==================//

    //starting mergeSort
    void mergeSort(){
        if(typeid(data[0]) != typeid(0)){
            throw std::invalid_argument("The list is not int type");
        }
    }


    ~ArrayList(){
        delete[] data;
    }


};

template<class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for(int i = 0; i < list.count; i++){
        os << list.data[i] << " ";
    }
    return os; 
}

#endif