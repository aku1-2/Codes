class DiningPhilosophers {
    binary_semaphore fork[5]={
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1),
        binary_semaphore(1),
    };
    counting_semaphore<4> room{4};
    mutex m,l;
public:
    DiningPhilosophers() {}

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
                        lock_guard<mutex> lock(m);
                        room.acquire();
                        fork[philosopher].acquire();
                        fork[(philosopher+1)%5].acquire();
                        
                        pickLeftFork();
                        pickRightFork();
                        eat();
                        putLeftFork();
                        putRightFork();
                        fork[philosopher].release();
                        fork[(philosopher+1)%5].release();
                        room.release();
                        

    }
};