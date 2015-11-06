/* universal map to fit any type of data for key or value*/
#include <iostream>
#include <unordered_map>

class Universal_Map {
    std::unordered_map<const void *, const void *> umap;

public:
    void put(const void *key, const void *value) { umap[key] = value; }
    const void *get(const void *key) { return umap[key]; }
};

int main() {
    Universal_Map um;
    um.put("Bob", "Dylan");
    int one = 1;
    um.put("one", &one);
    std::cout << (char *)um.get("Bob") << "; " << *(int *)um.get("one");
}
