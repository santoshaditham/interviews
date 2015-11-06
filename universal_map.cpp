/* universal map to fit any type of data for key or value*/
#include <iostream>
#include <unordered_map>
#include <string>

class Universal_Map {
    std::unordered_map<void *, void *> umap;
public:
    void put(void *key, void *value) { umap[key] = value;}
    const void *get(void *key) { return umap[key];}
};

int main() {
	int* int_val = new int(1); double* long_val = new double(1.00);
	char* char_val = new char('a'); std::string* string_val = new std::string("Hello");
    Universal_Map um;
    um.put((void*)char_val, (void*)string_val);
    um.put((void*)int_val, (void*)long_val);
    std::cout << (std::string *)um.get(char_val) << std::endl;
    std::cout << *(double *)um.get(int_val) << std::endl;
}
