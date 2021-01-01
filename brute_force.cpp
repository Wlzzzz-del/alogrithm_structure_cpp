#include <iostream>
using namespace std;

char* StrStr(const char* str, const char* target)
{
				if (!*target) {
								return (char*)str;
				}
				char* p1 = (char*)str;
				while (*p1) {
								char* str_begin = p1;
								char* target_begin = (char*)target;
								while(*str_begin && *target_begin && *target_begin==*str_begin)
								{
												str_begin++;
												target_begin++;
								}
								if (!*target_begin) {
								return p1;
								}
								p1++;
				}
				return NULL;
}

int main()
{
				const char* test_a = "abcdefg";
				const char* test_b = "de";
				cout<<"主字符串为:"<<test_a<<endl;
				cout<<"子字符串为:"<<test_b<<endl;
				cout<<"匹配的位置为:"<<StrStr(test_a,test_b)<<endl;
				return 0;
}
