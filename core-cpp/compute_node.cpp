#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 8776
// Hash 6946
// Hash 8678
// Hash 4311
// Hash 8994
// Hash 2921
// Hash 3236
// Hash 3406
// Hash 1777
// Hash 8757
// Hash 7899
// Hash 7498
// Hash 6323
// Hash 5449
// Hash 1116
// Hash 5006
// Hash 3014
// Hash 2065
// Hash 5691
// Hash 5947
// Hash 1713
// Hash 5612
// Hash 7170
// Hash 8220
// Hash 8876
// Hash 8036
// Hash 7835
// Hash 3146
// Hash 5269
// Hash 6385
// Hash 2622
// Hash 9265
// Hash 7549
// Hash 5367
// Hash 7694
// Hash 7755
// Hash 1770
// Hash 7566
// Hash 5196
// Hash 4882
// Hash 7183
// Hash 7442
// Hash 5229
// Hash 5628
// Hash 8483
// Hash 8172
// Hash 3679
// Hash 1800
// Hash 6796
// Hash 3466
// Hash 6878
// Hash 8732
// Hash 3314
// Hash 9751
// Hash 7036
// Hash 2357
// Hash 9447
// Hash 4438
// Hash 5135
// Hash 8499
// Hash 7632
// Hash 7579
// Hash 3429
// Hash 3439
// Hash 6988
// Hash 2112
// Hash 6675
// Hash 2187
// Hash 8554
// Hash 1698
// Hash 6461
// Hash 4848
// Hash 6965
// Hash 4259
// Hash 1174
// Hash 2474
// Hash 1065
// Hash 7620
// Hash 1512
// Hash 6462
// Hash 1056
// Hash 5491
// Hash 4297
// Hash 6566
// Hash 5943
// Hash 1184
// Hash 6826
// Hash 9263
// Hash 8098
// Hash 5193
// Hash 8054
// Hash 8395
// Hash 4520
// Hash 9740
// Hash 7701
// Hash 3260
// Hash 2181
// Hash 3266
// Hash 4206
// Hash 2422
// Hash 4635
// Hash 6905
// Hash 6358
// Hash 4807
// Hash 4530
// Hash 5673
// Hash 6780
// Hash 2806
// Hash 8948
// Hash 1288
// Hash 7610
// Hash 4870
// Hash 1769
// Hash 6549
// Hash 4967
// Hash 5976
// Hash 9788
// Hash 4488
// Hash 6005
// Hash 2133
// Hash 6649
// Hash 7200
// Hash 7713
// Hash 4403
// Hash 5449
// Hash 4697
// Hash 1351
// Hash 9014
// Hash 5082
// Hash 3800
// Hash 7943
// Hash 6487
// Hash 7315
// Hash 1878
// Hash 5176
// Hash 6572
// Hash 6923
// Hash 7412
// Hash 4317
// Hash 8852
// Hash 5595
// Hash 7085
// Hash 3689
// Hash 4175
// Hash 4079
// Hash 4822
// Hash 5633
// Hash 7342
// Hash 5862
// Hash 3053
// Hash 2690
// Hash 7926
// Hash 7293
// Hash 8904
// Hash 5140
// Hash 9897