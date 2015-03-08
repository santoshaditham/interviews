/* universal hash table to fit any type of data */
#include <iostream>
#include <unordered_map>

class Hashtable {
    std::unordered_map<const void *, const void *> htmap;

public:
    void put(const void *key, const void *value) {
            htmap[key] = value;
    }

    const void *get(const void *key) {
            return htmap[key];
    }

};

int main() {
    Hashtable ht;
    ht.put("Bob", "Dylan");
    int one = 1;
    ht.put("one", &one);
    std::cout << (char *)ht.get("Bob") << "; " << *(int *)ht.get("one");
}
