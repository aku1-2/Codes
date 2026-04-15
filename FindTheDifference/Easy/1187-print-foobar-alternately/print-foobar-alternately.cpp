class FooBar {
    int turn;
    condition_variable cv;
    mutex m;
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        turn=0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            if(turn!=0){
                cv.wait(lock);
            }
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            turn=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            if(turn!=1){
                cv.wait(lock);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            turn=0;
            cv.notify_all();
        }
    }
};