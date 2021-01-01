#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

/* find a pair of two elements in an array, whose sum is a given target number.
 */

vector<int> addsToTarget(vector<int> &number, int target)
{
				unordered_map<int, int> hash_table;
				vector<int> array;
				for(auto adj: number)
				{
				if (hash_table[adj]) {
								array.push_back(adj);
								array.push_back(target-adj);
								return array;
				}
				hash_table[target-adj]=adj;
				}
				for (int i=0; i<hash_table.size(); i++) {
				cout<<hash_table[i]<<endl;
				}
}

int main()
{
				vector<int> array = {1,2,3};
				int target = 4;
				vector<int> target_arr = addsToTarget(array, target);
				for(int i=0; i<target_arr.size(); i++)
				{
								cout<<target_arr[i]<<endl;
				}
				return 0;
}
