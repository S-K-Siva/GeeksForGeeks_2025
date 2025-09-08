class LRUCache {
  public:
    int capacity;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> cacheMap;
    LRUCache(int cap) {
        // code here
        this->capacity = cap;
        
    }

    int get(int key) {
        if(cacheMap.find(key) == cacheMap.end()){
            return -1;
        }
        
        auto it = cacheMap[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key,value});
        cacheMap[key] = cache.begin();
        return value;
    }

        
    void put(int key, int value) {
        // code here
        if(cacheMap.find(key) == cacheMap.end()){
            if(cache.size() == capacity){
                auto lru = cache.back();
                cacheMap.erase(lru.first);
                cache.pop_back();
            }
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }else{
            auto it = cacheMap[key];
            cache.erase(it);
            cache.push_front({key,value});
            cacheMap[key] = cache.begin();
        }
    }
};