#include <iostream>
#include <vector>
#include <list>
#include <chrono>

int main() {
    const int n = 300000; //

    ///////////// Vector test ////////////////
    std::cout << "*** Vector Test ***" << std::endl;
    std::vector<int> vec;
    
    // insert back
    std::cout << "Insert " << n << " elements at back ... " << std::endl;
    auto start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        vec.push_back(i); 
    }

    auto end_vec = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_vec = end_vec - start_vec;
    std::cout << "time taken: " << duration_vec.count() << " seconds\n";
    std::cout << std::endl;

    // insert front
    vec.clear();
    vec.resize(0);
    std::cout << "Insert " << n << " elements at front ... " << std::endl;
    start_vec = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
		vec.insert(vec.begin(), i); // 맨 앞에 삽입
	}

    end_vec = std::chrono::high_resolution_clock::now();
    duration_vec = end_vec - start_vec;
    std::cout << "time taken: " << duration_vec.count() << " seconds\n";
    std::cout << std::endl;

    // iterating through vector
    std::cout << "Iterating through vector ... " << std::endl;
    start_vec = std::chrono::high_resolution_clock::now();
    for (auto& v : vec) {
        v = v * 2; // 단순한 연산
    }
    end_vec = std::chrono::high_resolution_clock::now();
    duration_vec = end_vec - start_vec;
    std::cout << "time taken: " << duration_vec.count() << " seconds\n";
    std::cout << std::endl;

    // copy vector
    std::cout << "Copying vector ... " << std::endl;
    start_vec = std::chrono::high_resolution_clock::now();
    std::vector<int> vec_copy;
    vec_copy = vec; // copy
    end_vec = std::chrono::high_resolution_clock::now();
    duration_vec = end_vec - start_vec;
    std::cout << "time taken: " << duration_vec.count() << " seconds\n";
    std::cout << std::endl;


    ///////////// List test ////////////////
    std::cout << "*** List Test ***" << std::endl;
    std::list<int> lst;
    
    // insert back
    std::cout << "Insert " << n << " elements at back ... " << std::endl;
    auto start_lst = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
		lst.push_back(i); 
	}

    auto end_lst = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_lst = end_lst - start_lst;
    std::cout << "time taken: " << duration_lst.count() << " seconds\n";
    std::cout << std::endl;

    // insert front
    lst.clear();
    lst.resize(0);
    std::cout << "Insert " << n << " elements at front ... " << std::endl;
    start_lst = std::chrono::high_resolution_clock::now();
   
    for (int i = 0; i < n; ++i) {
        lst.push_front(i);
    }

    end_lst = std::chrono::high_resolution_clock::now();
    duration_lst = end_lst - start_lst;
    std::cout << "time taken: " << duration_lst.count() << " seconds\n";
    std::cout << std::endl;

  

    // iterating through list
    std::cout << "Iterating through list ... " << std::endl;
    start_lst = std::chrono::high_resolution_clock::now();
    for (auto& l : lst) {
		l = l * 2; // 단순한 연산
	}
    end_lst = std::chrono::high_resolution_clock::now();
    duration_lst = end_lst - start_lst;
    std::cout << "time taken: " << duration_lst.count() << " seconds\n";
    std::cout << std::endl;

    // copy list

    std::cout << "Copying list ... " << std::endl;
    start_lst = std::chrono::high_resolution_clock::now();
    std::list<int> lst_copy;
    lst_copy = lst; // copy
    end_lst = std::chrono::high_resolution_clock::now();
    duration_lst = end_lst - start_lst;
    std::cout << "time taken: " << duration_lst.count() << " seconds\n";
    std::cout << std::endl;



    return 0;
}