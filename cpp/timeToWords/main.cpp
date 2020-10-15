#include <iostream>
#include <fstream>

using namespace std;

static const string g_timeWords[]{
    "", "one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve",
    "thirteen", "fourteen", "quarter", "sixteen", "seventeen",
    "eighteen", "nineteen", "twenty"
};

string getMinutesWords(int m) {
    if (m == 30)
        return "half";

    if (m > 30)
        return getMinutesWords(60 - m);

    if (m > 20)
        return g_timeWords[20] + " " + g_timeWords[m - 20];

    return g_timeWords[m];
}

// Complete the timeInWords function below.
string timeInWords(int h, int m) {
    const string& hours = g_timeWords[m > 30 ? h + 1 : h];

    if (m == 0)
        return hours + " o' clock";

    const string& past_to = ((m > 30) ? " to " : " past ");

    return getMinutesWords(m) + past_to + hours;
}

int main()
{
    int h;
    cin >> h;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = timeInWords(h, m);

    cout << result.c_str() << "\n";

    return 0;
}
