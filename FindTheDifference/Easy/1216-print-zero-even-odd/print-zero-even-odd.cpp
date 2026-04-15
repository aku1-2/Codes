class ZeroEvenOdd {
    mutex m;
    condition_variable cv;
    int num=1;
    int turn;
private:
    int n;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        turn =0;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
            unique_lock<mutex> lock(m);
            while(turn!=0){
                cv.wait(lock);
            }
            printNumber(0);
            if(num%2==1){
                turn=1;
            }
            else turn=2;
            cv.notify_all();

        }
    }

    void even(function<void(int)> printNumber) {
         for(int i=0;i<n;i++){
            unique_lock<mutex> lock(m);
            while(turn!=2){
                if(num>n) return;
                cv.wait(lock);
            }
            printNumber(num);
            turn =0;
            num++;
            cv.notify_all();

        }
    }

    void odd(function<void(int)> printNumber) {
        for(int i=0;i<n;i++){
            unique_lock<mutex> lock(m);
            while(turn!=1){
                if(num>n) return;
                cv.wait(lock);
            }
            printNumber(num);
            turn =0;
            num++;
            cv.notify_all();

        }
    }
};