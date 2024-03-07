#include <bits/stdc++.h>
#include<cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


bool test_divisor(vector<int> arr, int threshold, float number){
  long int acc = 0;
  for(int i = arr.size() - 1; i > 0; i--){
    const int n = arr.at(i);
    float c = (float)n / number;
    acc += ceil(c);

    if (acc > threshold) return false;
  }

  return true;
}

/*
 * Complete the 'minimum_divisor' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY arr
 *  2. INTEGER threshold
 */

int minimum_divisor(vector<int> arr, int threshold) {
  sort(arr.begin(), arr.end());
  float result = 1;
  bool found = false;

  while(!found){
    if (test_divisor(arr, threshold, result)) found = true;
    else result++;
  }

  return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    string threshold_temp;
    getline(cin, threshold_temp);

    int threshold = stoi(ltrim(rtrim(threshold_temp)));

    int result = minimum_divisor(arr, threshold);

    cout << result << endl;
    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
