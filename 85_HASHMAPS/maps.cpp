#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{

    // creation
    unordered_map<string, int> m;

    // insertion

    // 1
    pair<string, int> p = make_pair("vodka", 3);
    m.insert(p);

    // 2
    pair<string, int> pair2("paani", 2);
    m.insert(pair2);

    // 3

    m["mera"] = 1;

    // this will update
    m["mera"] = 4;

    // search
    cout << m["mera"] << endl;
    cout << m["paani"] << endl;
    cout << m.at("vodka") << endl;

    // cout << m.at("Unknown key") << endl; // this will give out of range error

    cout << m["Unknown key"] << endl; // is ke liye 0 ban jaayegi entry

    cout << m.at("Unknown key") << endl; // this will give out of range error

    // size
    cout << "the size of map is " << m.size() << endl;

    // check presence of particular key
    cout << m.count("vodka") << endl; // if present then 1
    cout << m.count("bro") << endl;   // if not present then 0

    // erase
    m.erase("vodka");
    cout << m.count("vodka") << endl; // if present then 1
    cout << "the size of map is " << m.size() << endl;

    // access full map with for loops

    // for (auto i : m)
    // {
    //     cout << i.first << " " << i.second << " " << endl;
    // }

    // iterator

    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {

        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}