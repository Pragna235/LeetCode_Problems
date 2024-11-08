//Approach 1 : 
//time complexity - O(1) since the algorithm always iterates through a constant number of values (13 in this case).
//O(1) since the amount of extra space used is constant (the size of the storeIntRoman vector, which is also 13 in this case
class Solution {
public:
    string intToRoman(int num) {
        string Roman = "";
        // Creating vector of pairs to store the Roman numeral values and their corresponding symbols
        vector<pair<int, string>> storeIntRoman = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
        // Iterating through the vector and repeatedly adds the corresponding symbols to the result string while subtracting the corresponding value from the input integer until the input integer becomes zero.
        for (int i = 0; i < storeIntRoman.size(); i++) {
            while (num >= storeIntRoman[i].first) {
                Roman += storeIntRoman[i].second;
                num -= storeIntRoman[i].first;
            }
        }
        return Roman;
    }
};
