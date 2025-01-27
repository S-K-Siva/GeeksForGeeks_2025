//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    
    LRUCache(int cap) {
        this->capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()) return -1;
        auto it = cacheMap[key];
        int res = it->second;
        cache.erase(it);
        cache.push_front({key,res});
        cacheMap[key] = cache.begin();
        return res;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if(cacheMap.find(key) != cacheMap.end()){
            auto it = cacheMap[key];
            cache.erase(it);
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }
        else if(cache.size() == capacity){
            pair<int,int> it = cache.back();
            cacheMap.erase(it.first);
            cache.pop_back();
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }else{
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends