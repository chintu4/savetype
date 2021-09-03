#include <iostream>
#include <string.h>
#include <fstream>
#include<unordered_map>
#include <typeinfo>

using namespace std;
void appendFile(string c,string file){
	std::ofstream o(file,ios::app);
	o<<c;
	o.close();
}
string charToString(char* s){
	string temp;
	for(int i=0;i<<strlen(s);i++){
		temp+=s[i];
	}
	return temp;
}


string readFile(string s){
	std::ifstream f(s);
	string myText="nothing Found";string temp;
	if (f){
		while(f){
			myText="";
			getline(f,temp);
			myText+=temp+'\n';
		}
	}else{myText=s+"nothing found";}

	f.close();
	return myText;
}
bool check_key(unordered_map<string, string > m, string key)
{
	// Key is not present

	if (m.find(key) == m.end())
		return false;

	return true;
}
int main(int argc,char**argv){
	string url="/home/chintu/Documents/c.txt";
	if (argc<=1){
		cout<<"!!!Argument Must be passed!!!\nArguments:\n\tw [key][value]\n or\n\t [key]"<<endl;exit(0);}else{
			string s=readFile(url);
			unordered_map<string,string>kv ;

			bool k=0;
			string key,value;
			for (int i=0;i<s.length();i++){ 
				if (s.at(i)==':')
					k=1;
				else if(s.at(i)==','){
					kv[key] = value;
					key="";value="";k=0;}
				else if (k==0)
					key+=s[i];
				else
					value+=s[i];
			}

			//writting a key and value;
			if(std::string(argv[1])=="w"){
				if (argc<4){
					cout<<"Arguments after w [key] [value]\nRequired number of arguments Passed\n";}
				else{
					if (check_key(kv,std::string(argv[2]))==true){
						cout<<"!!!key already present!!!\nkey entered aleady present\n  ex:\n hello w k vim";
					}else{
						string t=std::string(argv[2])+":"+std::string(argv[3])+",";
						appendFile(t,url);}}
			}else{
				//read the string
				string q=kv[argv[1]];
				system(q.c_str());
			}
		}}


