class Solution {
public:
    string replaceSpace(string s) {
        int cnt = 0;
        for (auto i:s) {
            if (i == ' ') {
                cnt++;
            }
        }
        int i = s.length()-1;
        int j = i + 2*cnt;
        // 这儿浪费了好多时间，不熟啊
        s.resize(j+1);
        for (;;) {
            if (i < 0) {
                break;
            }
            if (s[i] != ' ') {
                s[j] = s[i];
            } else {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            }
            j--;
            i--;
        }
        return s;
    }
};
