#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

// Complete the anagram function below.
int anagram(string s) {
    if (s.length() % 2 != 0)
        return -1;

    int const  half_size = s.length() / 2;
    auto const mid       = begin(s) + half_size;

    sort(begin(s), mid);
    sort(mid, end(s));

    vector<char> s_intersection;
    s_intersection.reserve(half_size);

    set_intersection(begin(s), mid, mid, end(s), back_inserter(s_intersection));

    return half_size - size(s_intersection);
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        cin >> s;

        int result = anagram(s);

        cout << result << "\n";
    }

}
