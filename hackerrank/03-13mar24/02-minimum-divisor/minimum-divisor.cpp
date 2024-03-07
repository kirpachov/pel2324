#include <bits/stdc++.h>
#include<cmath>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


bool test_divisor(vector<int> arr, long long unsigned threshold, double number){
  int acc = 0;
  int i = arr.size() - 1;
  bool result = true;
  while(i >= 0 && result){
    acc += ceil((double)arr.at(i) / number);
    if (acc > threshold) result = false;

    i--;
  }

  return result;
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

  double result = 1;
  bool found = false;
  int step = 500000;

  while(!found){
    if (test_divisor(arr, threshold, result)) found = true;
    else {
      bool found_step = false;
      while(!found_step) {
        if (!test_divisor(arr, threshold, result + step)) {
          result = result + (step == 0 ? 1 : step);
          found_step = true;
        } else step = step / 2;
      }
    }
  }

//   int step = 500000;
//   int result = 1;
//   bool found = false;
//   while(!found){
//     if (!test_divisor(arr, threshold, result + step)){
//       result += step;
//     } else step = step / 2;

//     if (step < 2) found = true;
//   }
 
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

    /*cout << "arr: (" << arr_count << ") \n";
    for(auto a: arr) cout << a << ",";
    cout << "\n/arr" << endl;*/

    int result = minimum_divisor(arr, threshold);

    //cout << result << "\n";
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
