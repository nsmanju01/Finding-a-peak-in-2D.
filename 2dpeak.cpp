// Finding peak element in a 2D Array.
#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vector_t;

int maxrow(vector_t a, int col,int &max_val)
{

    int index;
    for(int i=0; i<a.size(); i++)
    {
        if(max_val < a[i][col] )
        {
            max_val = a[i][col];
            index = i;
        }
    }
    return index;
}


int findPeakrec(vector_t a,int l,int r)
{
    if(l>r)
        return -1;

    int mid = (l+r)/2;
    int max_val = 0;
    int max_row_index = maxrow(a,mid,max_val);
    cout << a[max_row_index][mid] << " ";

    if (mid == 0 || mid == a[0].size()-1)
        return max_val;



    if(mid-1 != 1 && max_val < a[max_row_index][mid-1])
        return findPeakrec(a,l,mid-mid/2);
    else
    if (mid+1 != a[0].size() && max_val < a[max_row_index][mid+1])
        return findPeakrec(a,mid+mid/2,r);
    else
        return max_val;


}

int findPeak(vector_t a)
{
    int l=0;
    int r= a[0].size()-1;

    return findPeakrec(a,l,r);
}

int main()
{
	vector_t a = {{ 99, 3, 9, 5},
					{ 14, 13, 12, 4 },
					{ 5, 9, 8, 10 },
					{ 6, 7, 9, 10 } };

	// Number of Columns

	cout << findPeak(a);
	return 0;
}
