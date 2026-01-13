#include <iostream>
#include <optional>
#include <vector>

using namespace std;

optional<int> find(vector<int>&v, int x)
{
    for(auto c : v)
    {
        if(c==x) return 1;
    }
    return {};

}

struct Config {
    int maxConnections;
    std::string serverName;
};

// Function that tries to initialize Config
std::optional<Config> loadConfig(bool valid) {
    if (!valid) {
        return std::nullopt;  // Initialization failed
    }
    return Config{10, "MyServer"};  // Successfully initialized
}

int main()
{
    vector<int>v{3,622,73,45,27,76};
    auto x = find(v,4);
    auto y = find(v,3);

    if(x.has_value()) cout << "Element is found in the vector." << endl;
    else cout << "Element isn't found in the vector." << endl;

    if(y.has_value()) cout << "Element is found in the vector." << endl;
    else cout << "Element isn't found in the vector." << endl;

    optional<Config> config = loadConfig(false);
    if(config.has_value()) cout << "Configurations are valid." << endl;
    else cout << "Configurations aren't valid." << endl;
}