#include <iostream>
#include <vector>
#include <chrono>

#include "generator.h"

int main()
{
    const uint32_t num_threads = std::thread::hardware_concurrency(); // Max # of threads the system supports
    std::cout<<"Nb coeur = "<<num_threads<<std::endl;
    ThreadPool pool(num_threads);

    generator g;
    g.gen(16,pool); 

    /* std::vector< std::future<int> > results;
    

    for(int i = 0; i < 8; ++i) {
        results.emplace_back(
            pool.enqueue([i] {
                std::cout << "hello " << i << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << "world " << i << std::endl;
                return i*i;
            })
        );
    }

    for(auto && result: results)
        std::cout << result.get() << ' ';
    std::cout << std::endl;
     */
    return 0;
}
