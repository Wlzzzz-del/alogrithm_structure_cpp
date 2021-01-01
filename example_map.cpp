#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
				map<int, string > mymap;
				mymap.insert(pair<int, string>(3, "chen"));
				mymap.insert(pair<int, string>(4, "chen1"));
				mymap.insert(pair<int, string>(5, "chen2"));
				mymap[3] = "lisa";
				auto it = mymap.begin();
				while(it != mymap.end())
				{
								cout<< it->first << it-> second;
								cout<<endl;
								it++;
				}

}
