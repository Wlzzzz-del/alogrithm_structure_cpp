#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
struct Bound
{
				int high = 0;
				int low =0;
};

int longconsecutive(vector<int> array)
{
				unordered_map<int , Bound> hash_table;
				int local = 0;
				int max_length = 0;
				for (int i=0; i<array.size(); i++) {
				if (hash_table.count(i)) {
				continue;
				}
				local = array[i];
				int high = local;
				int low = local;
				if (hash_table.count(local-1)) {
				low = hash_table[local-1].low;
				}
				if(hash_table.count(local+1))
				{
				high = hash_table[local+1].high;
				}
				hash_table[high].low= hash_table[local].low = low;
				hash_table[low].high = hash_table[local].high = high;

				if(high - low +1 >max_length)
								max_length= high- low +1;

				}
				return max_length;

}

int main()
{
				vector<int> array = {31,6,32,1,3,2};
				cout<<longconsecutive(array);
				return 0;
}
