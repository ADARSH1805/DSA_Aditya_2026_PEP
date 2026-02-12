// https://leetcode.com/problems/lru-cache/description/

class LRUCache {
public:
  typedef pair<int, int> pi;

  int cap;
  vector<list<pi>::iterator> mp;
  list<pi> l;

  LRUCache(int capacity) {
    cap = capacity;
    mp.assign(1e4 + 1, end(l));
  }

  int get(int key) {
    if (mp[key] == end(l)) {
      return -1;
    }

    int ans = mp[key]->second;
    l.erase(mp[key]);
    l.push_back({key, ans});
    mp[key] = --end(l);

    return ans;
  }

  void put(int key, int value) {
    if (mp[key] != end(l)) {
      mp[key]->second = value;
      l.erase(mp[key]);
      l.push_back({key, value});
      mp[key] = --end(l);
    } else {
      l.push_back({key, value});
      mp[key] = --end(l);

      if (l.size() > cap) {
        mp[l.front().first] = end(l);
        l.pop_front();
      }
    }
  }
};
