#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
	int end;
	
	multimap<int, int> mp = {
	  {3, 3},
	  {3, 1},
	  {3, 2},
	  {1, 4},
	  {2, 4},
	  {1, 5},
	  {1, 5}
	};

	using iterator = decltype(mp)::iterator;
	pair<iterator, iterator> ret = mp.equal_range(3);

	for (iterator it = ret.first; it != ret.second; ++it) {
		cout << it->first << "," << it->second << endl;
	}

	FILE* fp;

	fopen_s(&fp, "./mp.dat", "wb");
	fwrite(&mp, sizeof(mp), 1, fp);

	fclose(fp);

	cin >> end;
	
	
	multimap<int, int> mpr = {};

	fopen_s(&fp, "./mp.dat", "rb");
	fread(&mpr, sizeof(mpr), 1, fp);

	using iterator = decltype(mpr)::iterator;
	pair<iterator, iterator> retr = mpr.equal_range(1);

	for (iterator it = retr.first; it != retr.second; ++it) {
		cout << it->first << "," << it->second << endl;
	}

	cin >> end;
	

	return 0;
}
