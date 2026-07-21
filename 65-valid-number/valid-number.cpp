class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool seenDigit = false;
        bool seenDot = false;
        bool seenExp = false;
        bool digitAfterExp = true; // must have digit after exponent

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (isdigit(c)) {
                seenDigit = true;
                if (seenExp) digitAfterExp = true;
            }
            else if (c == '+' || c == '-') {
                // sign is only valid at start or right after exponent
                if (i > 0 && !(s[i-1] == 'e' || s[i-1] == 'E')) return false;
            }
            else if (c == '.') {
                // dot not allowed after exponent or if already seen
                if (seenDot || seenExp) return false;
                seenDot = true;
            }
            else if (c == 'e' || c == 'E') {
                // exponent must follow a digit and only appear once
                if (seenExp || !seenDigit) return false;
                seenExp = true;
                digitAfterExp = false; // reset, must see digit later
            }
            else {
                return false; // invalid character
            }
        }

        return seenDigit && digitAfterExp;
    }
};
