class LRUCache {
public:
    // first int in unorderred map is for key and in pair first int is for key
    // value pair and third int is for freq
    unordered_map<int, pair<int, int>> mp;
    int priorityOrder = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq; // helpful when size==currSizee it help to replace least recent
            // cache
    int size;
    int currSize;
    LRUCache(int capacity) {
        size = capacity;
        currSize = 0;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            mp[key].second++;
            pq.push({priorityOrder, key});
            priorityOrder++;
            return mp[key].first;
        }
        return -1;
    }

    void put(int key, int value) {

        if (currSize < size) {
            if (mp.find(key) != mp.end()) {
                mp[key].first = value;
            } else {
                mp[key].first = value;
                currSize++;
            }

            mp[key].second++;
            pq.push({priorityOrder, key});

        } else {
            if (mp.find(key) != mp.end()) {
                mp[key].first = value;
                mp[key].second++;
                pq.push({priorityOrder, key});
            } else {

                while (mp[pq.top().second].second != 1) {
                    mp[pq.top().second].second--;
                    pq.pop();
                }
                int val = pq.top().second;
                mp.erase(val);
                pq.pop();
                mp[key].first = value;
                mp[key].second++;
                pq.push({priorityOrder, key});
            }
        }
        priorityOrder++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */