using namespace std;

#include <vector>
#include <mutex>
#include "ThreadPool.h"

class generator {
public:
    void gen(int size, ThreadPool & tp);
    void func(int i );
    generator();   
private:
    
    vector<int> vect;
    
    // synchronization
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};




generator::generator(){}

void funct2(int i ){
    i++;
}

void  generator::gen(int size, ThreadPool & tp){
    for (int i = 0; i < size; i++)
    {
        tp.enqueue([&](int j) {this->func(j);}, i);
    }  
    
}

void generator::func(int i){
    this->vect.push_back(i);
}