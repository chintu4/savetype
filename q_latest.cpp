/* author: chintu sharma
   email: chintusharma00014@gmail.com
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <unordered_map>
#include <typeinfo>
#include <sys/stat.h>
//#include "colors.h"

using namespace std;

inline bool exists_file (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}

template<typename K, typename V>
void print_map(std::unordered_map<K, V> const &m)
{
    for (auto const &pair: m) {
        std::cout << "{" << pair.first << ": " << pair.second << "}\n";
    }
}
void appendFile(string c, string file)
{
    std::ofstream o(file, ios::app);
    o << c;
    o.close();
}
string charToString(char *s)
{
    string temp;
    for (size_t i = 0; i < strlen(s); i++)
    {
        temp += s[i];
    }
    return temp;
}
void writeFile(string url,string c){
    ofstream file(url,ios::out);
    file<<c;
    file.close();

}

string readFile(string s)
{
    std::ifstream f(s);
    string myText = "nothing Found";
    string temp;
    if (f)
    {
        while (f)
        {
            myText = "";
            getline(f, temp);
            myText += temp + '\n';
        }
    }
    else
    {
        myText = s + "nothing found";
    }

    f.close();
    return myText;
}
bool check_key(unordered_map<string, string> m, string key)
{
    // Key is not present

    if (m.find(key) == m.end())
        return false;

    return true;
}

int main(int argc, char **argv)
{
    string url = "/home/chintu/Documents/c.txt";
    if (argc <= 1)
    {
        cout << "!!!Argument Must be passed!!!\nArguments:\n\tw [key][value]\n or\n\t [key]" << endl;
        exit(0);
    }
    else
    {
        string s = readFile(url);
        unordered_map<string, string> kv;

        bool k = 0;
        string key, value;
        for (size_t i = 0; i < s.length(); i++)
        {
            if (s.at(i) == ':')
                k = 1;
            else if (s.at(i) == ',')
            {
                kv[key] = value;
                key = "";
                value = "";
                k = 0;
            }
            else if (k == 0)
                key += s[i];
            else
                value += s[i];
        }

        // writting a key and value;
        if (std::string(argv[1]) == "w")
        {
            if (argc < 4)
            {
                cout << "Arguments after w [key] [value]\nRequired number of arguments Passed\n";
            }
            else
            {
                if (check_key(kv, std::string(argv[2])) == true)
                {
                    cout << "!!!key already present!!!\nkey entered aleady present\n  ex:\n hello w k vim";
                }
                else
                {
                    string t = std::string(argv[2]) + ":" + std::string(argv[3]) + ",";
                    appendFile(t, url);
                }
            }
        }
        else if(std::string(argv[1]) == "p"){
			if (argc < 1)
            {
                cout << "Arguments after p [key] [value]\nRequired number of arguments Passed\n";
            }
            else
            {std::cout<<"Printed:"<<"{key:value} that existed!!!"<<std::endl;
                print_map(kv);
			}}else if(std::string(argv[1]) == "r"){
                string f=readFile(url);
                string keyValue=std::string(argv[2]);
                size_t t=f.find(keyValue);
                string tmp=f.substr(t,string::npos);
                size_t k=tmp.find(",");
                string tmp2=tmp.substr(0,k);
                f.erase(t,t+k-4);
                writeFile(url,f);
            }
        else
        {
            string q = kv[argv[1]];
            ;
            if (q == "")
            {
                cerr << "string not found"<<std::endl;
                exit(1);
            }
            /*all args should be append to q string after the key in args means from index 2*/
            if (argc > 1)
            {
                for (int i = 2; i < argc; i++)
                {
                    q.append(" ");
                    q.append(argv[i]);
                }
            }
            // else find value of given string and pass to q to execute.
            std::cout << q << std::endl;

            system(q.c_str());
        }
    }
}
