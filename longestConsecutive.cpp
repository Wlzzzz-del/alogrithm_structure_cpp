#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/* get the length of the longest consecutive elements sequence in an array. For example, given [31,6,32,1,3,2], the longest consecutive elements sequence is [1,2,3].Return its length:3.
*/

struct Bound
{
				int high;
				int low;
};
int longestConsecutive(vector<int> &num){
				int local = 0;
				int max_length = 0;
				unordered_map<int, Bound> hash_table;
				for (int i=0; i<num.size(); i++) {
				if (hash_table.count(i) {
								continue;
				}
				}
}
int main()
{
				Bound a;
				a.high=1;
				a.low = 2;
				cout<<a.high<<endl;
				cout<<a.low<<endl;
				return 0;
}
