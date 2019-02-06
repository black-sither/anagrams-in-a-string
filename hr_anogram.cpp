#include <bits/stdc++.h>

using namespace std;

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(string s) {
 map <int, set< map<char,int> > > allsub;
 map<char,int> let;
 map< map<char,int>,int > all_counts;
 int anog=0,tmp;
 string sub;
  for(int i=0;i<s.length();i++){
     for(int j=1;j<=s.length() - i;j++){
        let.clear();
        sub=s.substr(i,j);
        for(string::iterator it=sub.begin();it!=sub.end();it++)
        {
            let[*it]+=1;
        }
        if(allsub[j].find(let) !=allsub[j].end())
        {
            all_counts[let]++;
        }
        else
        {
            allsub[j].insert(let);
        }
     }
 }
 for(auto it=all_counts.begin();it!=all_counts.end();it++)
    {
        tmp=it->second + 1;
        if(tmp == 1)
        {
            anog++;
        }
        else
        {
            anog += (tmp * (tmp - 1))/2;
        }
    }
    return anog;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
