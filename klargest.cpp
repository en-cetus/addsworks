#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    //Construct a max heap
    std::priority_queue<int> pq(values.begin(), values.end());

    //Found the kth largest
    for (int i = 1; i < k && !pq.empty(); ++i) {
        pq.pop();
    }

    return pq.top();
}
