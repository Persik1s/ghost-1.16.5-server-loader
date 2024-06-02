#ifndef ARRAY
#define ARRAY
#include <vector>
#include <string>
class ListModule {
private:
    std::vector<std::string> listName;
    std::vector<bool*> listBool;
public:
    bool init = false;

    void Add(std::string name ,bool* fun){
        this->listName.push_back(name);
        this->listBool.push_back(fun);
    }
    bool IsBool(int i){
        return *this->listBool[i];
    }
    const char* GetName(int i){
        return this->listName[i].c_str();
    }
    int Size(){
        return this->listBool.size();
    }
};
#endif