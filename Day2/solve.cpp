#include<string>
#include<fstream>
#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;


pair<string ,string>getValues(string s){
    int pos=s.find('-');
    string left=s.substr(0,pos);
    string right=s.substr(pos+1);
    return {left,right};
}

string addOne(string s) {
    int i = s.size() - 1;
    while (i >= 0 && s[i] == '9') {
        s[i] = '0';
        i--;
    }
    if (i >= 0) {
        s[i]++;
    } else {
        s = '1' + s;
    }
    return s;
}

bool isPalindrome(string s) {
    int n = s.length();
    int half = n / 2;
    string first = s.substr(0, half);
    string second = s.substr(half);
    return first == second;
}

string addStrings(string a, string b) {
    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;
    string result = "";

    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;
        int digitB = (j >= 0) ? b[j] - '0' : 0;

        int sum = digitA + digitB + carry;

        result.push_back((sum % 10) + '0');
        carry = sum / 10;

        i--;
        j--;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool lessEqual(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}




void solve(string&ans,string start,string end){

    while(lessEqual(start,end)){
      
        bool con=isPalindrome(start);

        if(con){
              if(start=="101") break;
            ans=addStrings(ans,start);
        }
        start=addOne(start);
    }
}

int main(){
     ifstream inputfile("input.txt");

     if(!inputfile.is_open()) {
        cerr<<"Error while opening a file";
     }

     string ans="0";



     string line;

     while(getline(inputfile,line,',')){
        auto value=getValues(line);
        solve(ans,value.first,value.second);
     }

     cout<<ans<<endl;

    
}