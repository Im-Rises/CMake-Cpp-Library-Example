#include <pthread.h>
#include <iostream>

void* thread_func(void* arg) {
    std::cout << "Hello from thread" << std::endl;
    return nullptr;
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    pthread_create(&thread, nullptr, thread_func, nullptr);
    pthread_join(thread, nullptr);
    return 0;
}
