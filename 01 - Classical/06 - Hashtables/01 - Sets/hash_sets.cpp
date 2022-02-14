#include <iostream>
#include <vector>

class MyHashSet {
   
public:
    int capacity;
    int size;
    std::vector<int> set;
    float load_factor;

    MyHashSet() {

        capacity=8;
        size=0;
        set=std::vector<int> (capacity,-1);
        load_factor=2.0f/3.0f;
        
    }

    int hash(int key){

        return key % capacity;
    }

    int rehash(int key){
        return (key*5+1) % capacity;
    }
    
    void add(int key) {

        if (float(size)/capacity>=load_factor){
            capacity<<=1;
            std::vector<int> new_set(capacity,-1);

            for (int i=0; i<capacity<<1; ++i){
                if (set[i]>0){
                    int idx=hash(set[i]);

                    while (new_set[idx]!=-1){
                        idx=rehash(idx);
                    }
                    new_set[idx]=set[i];

                }
            }
        }

        int idx=hash(key);

        while (set[idx]>=0){
            if (set[idx]==key) return;

            idx=rehash(idx);
        }
        
        set[idx]=key;

        ++size;

    }
    
    void remove(int key) {

        int idx=hash(key);

        while (set[idx]!=-1){

            if (set[idx]==key){
                set[idx]=-2;
                --size;
                break;
            }
            idx=rehash(idx);
        }
        
        
    }
    
    bool contains(int key) {

        int idx=hash(key);

        while (set[idx]!=-1){

            if (set[idx]==key){
                return true;
            }

            idx=rehash(idx);

        }

        return false;
    }

    
};



int main(){

    MyHashSet set;

    set.add(938);
    set.add(20);
    set.add(23);
    if (set.contains(938)){
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "FALSE" << std::endl;
    }
    std::cout << set.contains(938);
    



    return 0;
}